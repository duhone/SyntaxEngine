// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the SYNTAXGRAPHICSMOBILE_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// SYNTAXGRAPHICSMOBILE_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#pragma once

#ifdef SYNTAXGRAPHICSMOBILE_EXPORTS
#define SYNTAXGRAPHICSMOBILE_API __declspec(dllexport)
#else
#define SYNTAXGRAPHICSMOBILE_API __declspec(dllimport)
#endif

#include"boost/smart_ptr.hpp"
#include "../Syntax Database/SyntaxDatabaseFwd.h"
#include "..\SyntaxMath\Color.h"
#include "..\Utility\Guid.h"
#include "..\SyntaxMath\Rectangle.h"

namespace Syntax
{
	namespace Graphics
	{
		class SYNTAXGRAPHICSMOBILE_API IPanel
		{
		public:
			virtual float Z() const = 0;
			virtual void Z(float _z) = 0;
			virtual bool Show() const = 0;
			virtual void Show(bool _show) = 0;
			virtual float X() const = 0;
			virtual void X(float _x) = 0;
			virtual float Y() const = 0;
			virtual void Y(float _y) = 0;
			virtual float Width() const = 0;
			virtual void Width(float _width) = 0;
			virtual float Height() const = 0;
			virtual void Height(float _height) = 0;
			virtual const Syntax::Utility::Guid& BackgroundTexture() const = 0;
			virtual void BackgroundTexture(const Syntax::Utility::Guid& _backgroundTexture) = 0;
			virtual const Syntax::Math::Color32& BackgroundColor() const = 0;
			virtual void BackgroundColor(const Syntax::Math::Color32& _backgroundColor) = 0;
			virtual bool UseBackgroundImage() const = 0;
			virtual void UseBackgroundImage(bool _useBackgroundImage) = 0;
			virtual bool AnchorLeft() const = 0;
			virtual void AnchorLeft(bool _anchorLeft) = 0;
			virtual bool AnchorRight() const = 0;
			virtual void AnchorRight(bool _anchorRight) = 0;
			virtual bool AnchorTop() const = 0;
			virtual void AnchorTop(bool _anchorTop) = 0;
			virtual bool AnchorBottom() const = 0;
			virtual void AnchorBottom(bool _anchorBottom) = 0;
		protected:
			IPanel(void) {};
			virtual ~IPanel(void) {};
		};

#ifdef _WINDOWS
		struct SettingsWindows
		{
			HWND hwnd;
		};
#endif
		class SYNTAXGRAPHICSMOBILE_API IGraphics
		{
		public:
#ifdef _WINDOWS
			virtual void Initialize(const SettingsWindows& _settings) = 0;
#endif
			virtual void SetDatabase(Syntax::Database::ISyntaxDatabase *_database) = 0;
			virtual void Commit() = 0;
			virtual bool UseBackgroundColor() = 0;
			virtual void UseBackgroundColor(bool _useBackColor) = 0;
			virtual void BackgroundColor(unsigned char _red,
				unsigned char _green, unsigned char _blue) = 0;
			virtual void BackgroundColor(Syntax::Math::Color32 _color) = 0;
			virtual Syntax::Math::Color32 BackgroundColor() = 0;
			virtual boost::shared_ptr<IPanel> CreatePanel(const Syntax::Utility::Guid &_id) = 0;
		protected:
			IGraphics() {};
			virtual ~IGraphics() {};
		};

	}
}

SYNTAXGRAPHICSMOBILE_API Syntax::Graphics::IGraphics& GetGraphics(void);