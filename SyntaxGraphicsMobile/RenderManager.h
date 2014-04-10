#pragma once
#include "Singleton.h"
#include "boost\smart_ptr.hpp"
#include "ForwardDeclarations.h"
#include <vector>

namespace Syntax
{
	namespace Graphics
	{
		class IPanel;
		class Panel;

		class RenderManager : public Syntax::Utility::Singleton<RenderManager>
		{
			friend Syntax::Utility::Singleton<RenderManager>;
		public:
			boost::shared_ptr<IPanel> CreatePanel(const Syntax::Utility::Guid &_id);
			void RemovePanel(IPanel *_panel);
			void PanelChangeZ(IPanel *_panel);
			void Render();
		protected:
			RenderManager(void);
			virtual ~RenderManager(void);
		private:
			std::vector<Panel*> panels;
		};
	}
}
