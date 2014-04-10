#include "StdAfx.h"
#include "DataHandler.h"
#include "DataCompiler.h"
#include "CompilerImpl.h"

using namespace Syntax;
using namespace Syntax::Compiler;

DataHandler::DataHandler(void)
{
}

DataHandler::~DataHandler(void)
{
}

INodeCompiler* DataHandler::StartElement()
{
	DataCompiler *compiler = new DataCompiler();;
	CompilerImpl::Instance().SetTop(compiler);
	return compiler;
}