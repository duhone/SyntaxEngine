#pragma once
#include "Resource.h"

namespace graphicsengine
{
	namespace resources
	{
		class LabelPrototype :
			public Resource
		{
		private:
			std::wstring *text;
			long anchor;
			std::wstring *fontName;
		public:
			LabelPrototype(IDirect3DDevice9* d3d_device,const Syntax::Database::IRecord *record);
			virtual void BuildResource();
			virtual void FreeResource();
			virtual void Release(void);
			std::wstring& GetFontName() { return *fontName; }
			std::wstring& GetText() { return *text; }
			int GetAnchor() {return anchor; }
		public:
			virtual ~LabelPrototype(void);
		};
	}
}
