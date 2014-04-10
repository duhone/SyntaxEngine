// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the SYNTAXGRAPHICSMOBILECOMPILER_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// SYNTAXGRAPHICSMOBILECOMPILER_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef SYNTAXGRAPHICSMOBILECOMPILER_EXPORTS
#define SYNTAXGRAPHICSMOBILECOMPILER_API __declspec(dllexport)
#else
#define SYNTAXGRAPHICSMOBILECOMPILER_API __declspec(dllimport)
#endif

#include "INodeHandler.h"
#include "ICompiler.h"
#include "Singleton.h"
#include <vector>

SYNTAXGRAPHICSMOBILECOMPILER_API std::vector<Syntax::Compiler::INodeHandler*> GetHandlers();
SYNTAXGRAPHICSMOBILECOMPILER_API void SetCompiler(Syntax::Compiler::ICompiler *compiler);


namespace Syntax
{
	namespace GraphicsCompiler
	{
		class Globals : public Syntax::Utility::Singleton<Globals>
		{
			friend Syntax::Utility::Singleton<Globals>;
		public:
			Syntax::Compiler::ICompiler *Compiler() { return compiler;}
			void Compiler(Syntax::Compiler::ICompiler * compiler) { this->compiler = compiler;}
		private:
			Globals() {};
			virtual ~Globals() {};
			Syntax::Compiler::ICompiler *compiler;
		};
	}
}