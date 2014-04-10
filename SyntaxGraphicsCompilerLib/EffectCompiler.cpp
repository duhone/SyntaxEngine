#include "StdAfx.h"
#include "EffectCompiler.h"
#include "BinaryWriter.h"
#include "SyntaxGraphicsCompilerLib.h"

using namespace std;
using namespace Syntax::Utility;
using namespace Syntax::GraphicsCompiler;
using namespace boost;
using namespace boost::filesystem;

EffectCompiler::EffectCompiler(void)
{
}

EffectCompiler::~EffectCompiler(void)
{
}

void EffectCompiler::CompileData(Syntax::Utility::BinaryWriter &writer)
{
	SetUpFileNames();
	CheckFile();
	if(needsToUpdate)
	{
		BuildFXO();
		//Sleep(100);
		BuildFXF();
	}
	if(exists(tempFileName))
		remove(tempFileName);
	unsigned long inputFileSize = static_cast<unsigned long>(file_size(finalFileName));
	scoped_array<char> inputBuffer(new char[inputFileSize]);
	ifstream inputFile(finalFileName.c_str(),ios::in | ios::binary);
	inputFile.read(inputBuffer.get(),inputFileSize);
	writer << inputFileSize;
	writer.Write(inputBuffer.get(),inputFileSize);
}


void EffectCompiler::SetUpFileNames()
{
	wstringstream tempFileName;
	tempFileName << fileName << "o";
	wstringstream compiledFileName;
	compiledFileName << fileName << "f";

	this->tempFileName = tempFileName.str();
	this->finalFileName = compiledFileName.str();
}

void EffectCompiler::CheckFile()
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

void EffectCompiler::BuildFXO()
{
	wstringstream cmd;
	cmd << "/T fx_2_0 /Fo \"" << tempFileName << "\" \"" << fileName << "\"";
	SHELLEXECUTEINFO shellInfo;
	shellInfo.cbSize = sizeof(SHELLEXECUTEINFO);
	shellInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
	shellInfo.lpFile = L"fxc.exe";
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

void EffectCompiler::BuildFXF()
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