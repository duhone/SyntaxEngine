#pragma once

namespace Syntax
{
	namespace Compiler
	{
		class INodeHandler;
		class INodeCompiler;
		class Asset;

		class NodeHandler
		{
		public:
			NodeHandler(INodeHandler* handler);
			virtual ~NodeHandler(void);
			std::wstring Handles();
			std::wstring Parent();
			void HandleAttribute(const std::wstring &name,const std::wstring& value);
			void HandleNode(CComPtr<IXmlReader> &pReader,Syntax::Compiler::INodeCompiler *parent,Asset *parentAsset,bool emptyElement);
			void StartProcessing();
			void EndProcessing();
			void PreCompile();
		private:
			INodeHandler* handler;
		};
	}
}
