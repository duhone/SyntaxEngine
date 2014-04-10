#pragma once
#include "WindowSettings.h"
#include "ILabel.h"
#include "ISprite.h"
#include "Syntax Database.h"

namespace graphicsengine
{
	class IGraphicsEngine
	{
	public:
		IGraphicsEngine(void);
		virtual ~IGraphicsEngine(void);
		
		static IGraphicsEngine* getInstance(void);
		virtual void Initialize(WindowSettings* windowSettings)=0;
		void Shutdown(void);

	protected:
		static IGraphicsEngine* instance;

	public:
		virtual void setBackgroundColor(const float& red, const float& green, const float& blue) = 0;
		virtual void SetDatabase(Syntax::Database::ISyntaxDatabase *database) = 0;
		virtual ILabel* CreateLabel(const std::wstring& prototypeName) = 0;
		virtual ISprite* CreateSprite(const std::wstring& prototypeName) = 0;
		virtual void Commit() = 0;
		virtual float GetAspectRatio() = 0;
		virtual int GetHighestValidQuality() = 0;
		virtual void SetQuality(int quality) = 0;
	};
}
