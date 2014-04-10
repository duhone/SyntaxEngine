#pragma once
#include "syntaxgraphicsmobile.h"
#include "Singleton.h"
#include "..\SyntaxMath\Color.h"

namespace Syntax
{
	namespace Graphics
	{
		class IDevice;
		class ResourceManager;

		class GraphicsImpl :
			public Syntax::Graphics::IGraphics, public Syntax::Utility::Singleton<GraphicsImpl>
		{
			friend Syntax::Utility::Singleton<GraphicsImpl>;
		public:
#ifdef _WINDOWS
			virtual void Initialize(const SettingsWindows& _settings);
			HWND Hwnd() {return hwnd;}
#endif
			virtual void SetDatabase(Syntax::Database::ISyntaxDatabase *_database);
			virtual void Commit();
			virtual bool UseBackgroundColor() {return useBackgroundColor;}
			virtual void UseBackgroundColor(bool _useBackColor) {useBackgroundColor = _useBackColor;}
			virtual void BackgroundColor(unsigned char _red,
				unsigned char _green, unsigned char _blue) {backgroundColor.Set(_red,_green,_blue);}
			virtual void BackgroundColor(Syntax::Math::Color32 _color) {backgroundColor = _color;}
			virtual Syntax::Math::Color32 BackgroundColor() {return backgroundColor;}
			virtual boost::shared_ptr<IPanel> CreatePanel(const Syntax::Utility::Guid &_id);
			boost::shared_ptr<IDevice> Device() const {return device;}
		protected:
			GraphicsImpl(void);
			virtual ~GraphicsImpl(void);
		private:
			boost::shared_ptr<IDevice> device;
			bool useBackgroundColor;
			Syntax::Math::Color32 backgroundColor;
#ifdef _WINDOWS
			HWND hwnd;
#endif

			//boost::shared_ptr<ResourceManager> resourceManager;
		};
	}
}
