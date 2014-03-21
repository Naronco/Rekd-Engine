#ifndef REKD_CHECKBOX_COMPONENT_H_
#define REKD_CHECKBOX_COMPONENT_H_

#include "IComponent.h"

namespace Rekd2D
{
	namespace Core
	{
		class CheckboxComponent : public IComponent
		{
		public:
			CheckboxComponent();

			void Load(ContentManager* content);
			RectF GetBounds();
			void Render(Renderer* renderer);
			void SetFlag(unsigned int type, unsigned int value);
			void Click(unsigned char button);
			void Load();
			unsigned int GetFlags();
		protected:
			bool Checked = false;
			Texture* CheckBoxOff;
			Texture* CheckBoxOn;
		};
	}
}
#endif