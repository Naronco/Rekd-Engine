#ifndef REKD_TEXTBOX_COMPONENT_H_
#define REKD_TEXTBOX_COMPONENT_H_

#include "IComponent.h"
#include "ComponentFlag.h"

namespace Rekd2D
{
	namespace Core
	{
		enum TextboxFlags
		{
			TEXTBOX_FOCUSED
		};
		class TextboxComponent : public IComponent
		{
		public:
			TextboxComponent();

			void Load(ContentManager* content);
			RectF GetBounds();
			void Render(Renderer* renderer);
			void SetFlag(unsigned int type, unsigned int value);
			void Click(unsigned char button);
			void Load();
			unsigned int GetFlags();
		protected:
			bool Focused = false;
			Texture* Textbox;
			Texture* TextboxFocused;
		};
	}
}
#endif