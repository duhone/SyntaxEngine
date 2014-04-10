#include "StdAfx.h"
#include "TextureCompiler.h"
#include "SyntaxGraphicsMobileCompiler.h"
#include "StringUtil.h"
#include "BinaryWriterFO.h"
#include "BinaryReader.h"

#include "ddraw.h"

using namespace std;
using namespace stdext;
using namespace Syntax::Utility;
using namespace Syntax::GraphicsCompiler;
using namespace boost;
using namespace boost::filesystem;

TextureCompiler::TextureCompiler(void)
{

}

TextureCompiler::~TextureCompiler(void)
{
}

void TextureCompiler::CompileData(Syntax::Utility::BinaryWriter &writer)
{
	SetUpFileNames();
	CheckFile();
	if(needsToUpdate)
	{
		//Sleep(100);
		BuildFinal();
	}
	
	unsigned long inputFileSize = static_cast<unsigned long>(file_size(finalFileName));
	scoped_array<char> inputBuffer(new char[inputFileSize]);
	ifstream inputFile(finalFileName.c_str(),ios::in | ios::binary);
	inputFile.read(inputBuffer.get(),inputFileSize);
	writer << inputFileSize;
	writer.Write(inputBuffer.get(),inputFileSize);
}


void TextureCompiler::SetUpFileNames()
{
	wpath original(this->fileName);
	original.remove_leaf();
	wpath fileName(basename(this->fileName));
	wstringstream compiledFileName;
	compiledFileName << original << fileName << "_compressed.ddz";

	this->fileName = Globals::Instance().Compiler()->DataPath() + this->fileName;

	this->finalFileName = Globals::Instance().Compiler()->DataPath() + compiledFileName.str();
}

void TextureCompiler::CheckFile()
{
	if(Globals::Instance().Compiler()->SettingExists(L"rebuild"))
	{
		needsToUpdate = true;
		return;
	}
	needsToUpdate = false;
	wpath finalPath(finalFileName);
	if(!exists(finalPath))
	{
		needsToUpdate = true;
		return;
	}
	wpath origPath(fileName);
	time_t originalFileTime = last_write_time(origPath);
	time_t finalFileTime = last_write_time(finalPath);
	if(originalFileTime > finalFileTime)
		needsToUpdate = true;
}


void TextureCompiler::BuildFinal()
{
	unsigned char ddsMagic[4];
	DDSURFACEDESC2 surfaceDesc;
	BinaryReader reader(fileName);
	reader >> ddsMagic >> surfaceDesc;

	unsigned long inputFileSize = surfaceDesc.dwWidth*surfaceDesc.dwHeight;
	vector<unsigned short> inputBuffer;
	inputBuffer.reserve(inputFileSize);

	for (unsigned int y=0; y<surfaceDesc.dwHeight; ++y)
	{
        for (unsigned int x=0; x<surfaceDesc.dwWidth; ++x)
		{
			unsigned short temp;
			reader >> temp;
			inputBuffer.push_back(temp);
		}
    }
	
	BinaryWriter outWriter(finalFileName);
	outWriter << static_cast<long>(surfaceDesc.dwWidth);
	outWriter << static_cast<long>(surfaceDesc.dwHeight);
	outWriter.CompressingMode(true);
	ForEach(inputBuffer,BinaryWriterFO(outWriter));	
}