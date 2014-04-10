#include "StdAfx.h"
#include "TextureCompiler.h"
#include "BinaryWriter.h"
#include "SyntaxGraphicsCompilerLib.h"

using namespace std;
using namespace stdext;
using namespace Syntax::Utility;
using namespace Syntax::GraphicsCompiler;
using namespace boost;
using namespace boost::filesystem;

TextureCompiler::TextureCompiler(void)
{
	dds = false;
	type = L"color";
	optionsLookup[L"rgba"] = L" -rgb";
	optionsLookup[L"dxt1"] = L" -bc1";
	optionsLookup[L"dxt5"] = L" -bc3";
	optionsLookup[L"dxtn"] = L" -bc3n";
	optionsLookup[L"ati1"] = L" -bc4";
	optionsLookup[L"ati2"] = L" -bc5";
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
		if(!dds)
			BuildTemp();
		//Sleep(100);
		BuildFinal();
	}
	if(exists(tempFileName) && !dds)
		remove(tempFileName);
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
	wstringstream tempFileName;
	tempFileName << original << fileName << "_temp.dds";
	wstringstream compiledFileName;
	compiledFileName << original << fileName << "_compressed.ddz";

	wstring ext = extension(this->fileName);
	if(ext == L".dds")
	{
		dds = true;
		this->tempFileName = this->fileName;
	}
	else
		this->tempFileName = tempFileName.str();
	this->finalFileName = compiledFileName.str();
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

void TextureCompiler::BuildTemp()
{
	wstringstream cmd;
	cmd << " -nocuda";
	if(type == L"normal")
		cmd << L" -normal";
	else
		cmd << L" -color";
	hash_map<wstring,wstring>::iterator iterator = optionsLookup.find(compression);
	if(iterator == optionsLookup.end())
		cmd << L" -rgb";
	else
		cmd << iterator->second;

	cmd << L" \"" << fileName << L"\" \"" << tempFileName << L"\"";
	SHELLEXECUTEINFO shellInfo;
	shellInfo.cbSize = sizeof(SHELLEXECUTEINFO);
	shellInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
	shellInfo.lpFile = L"nvcompress.exe";
	shellInfo.lpDirectory = NULL;
	shellInfo.lpVerb = L"open";
	scoped_array<wchar_t> params(new wchar_t[cmd.str().length()+2]);
	wcscpy(params.get(),cmd.str().c_str());
	shellInfo.lpParameters = params.get();
	shellInfo.nShow = SW_SHOWDEFAULT;
	ShellExecuteEx(&shellInfo);
	DWORD exitCode = STILL_ACTIVE;
	while(exitCode == STILL_ACTIVE)
	{
		Sleep(25);
		GetExitCodeProcess(shellInfo.hProcess,&exitCode);
	}
	CloseHandle(shellInfo.hProcess);
}

void TextureCompiler::BuildFinal()
{
	unsigned long inputFileSize = static_cast<unsigned long>(file_size(tempFileName));
	scoped_array<char> inputBuffer(new char[inputFileSize]);
	ifstream inputFile(tempFileName.c_str(),ios::in | ios::binary);
	inputFile.read(inputBuffer.get(),inputFileSize);
	
	BinaryWriter outWriter(finalFileName);
	outWriter << inputFileSize;
	outWriter.CompressingMode(true);
	outWriter.Write(inputBuffer.get(),inputFileSize);
}