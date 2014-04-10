#pragma once

#ifdef SYNTAXCOMMANDCOMPILER_EXPORTS
#define SYNTAXCOMMANDCOMPILER_API __declspec(dllexport)
#else
#define SYNTAXCOMMANDCOMPILER_API __declspec(dllimport)
#endif
#include "INodeHandler.h"
#include "ICompiler.h"
#include "Singleton.h"
#include <vector>

SYNTAXCOMMANDCOMPILER_API std::vector<Syntax::Compiler::INodeHandler*> GetHandlers();