#ifndef REKD_TEXTBOX_COMPONENT_H_
#define REKD_TEXTBOX_COMPONENT_H_

#include "IComponent.h"
#include "KeyboardState.h"
#include "TextComponent.h"
#include "ComponentFlag.h"
#include <algorithm>

namespace Rekd2D
{
	namespace Core
	{
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
			void OnText(bool append, const std::string& text, int cursor, int selection);
			void OnKeyboard(KeyboardState ks, KeyboardState old);

			FontLoader* m_Font;
		protected:
			bool Focused = false;
			Texture* Textbox;
			Texture* TextboxFocused;
			TextComponent* m_Label;
			int cursor;
			int selLength;
		};
	}
}
#endif