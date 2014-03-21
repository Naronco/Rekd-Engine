#ifndef REKD_TEXT_COMPONENT_H_
#define REKD_TEXT_COMPONENT_H_

#include "IComponent.h"
#include "ComponentFlag.h"

namespace Rekd2D
{
	namespace Core
	{
		class TextComponent : public IComponent
		{
		public:
			TextComponent();

			void Load(ContentManager* content);
			RectF GetBounds();
			void Render(Renderer* renderer);
			void SetFlag(unsigned int type, unsigned int value);
			void Click(unsigned char button);
			void Load();
			unsigned int GetFlags();
			std::string Text;
		protected:
			bool Focused = false;
			Texture* m_Font;
		};
	}
}
#endif