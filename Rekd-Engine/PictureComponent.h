#ifndef REKD_PICTURECOMPONENT_H_
#define REKD_PICTURECOMPONENT_H_

#include "IComponent.h"
#include "Action.h"

namespace Rekd2D
{
	namespace Core
	{
		class PictureComponent : public IComponent
		{
		public:
			PictureComponent();

			void Load(ContentManager* content);
			RectF GetBounds();
			void Render(Renderer* renderer);
			void SetFlag(unsigned int type, unsigned int value);
			void Click(unsigned char button);
			unsigned int GetFlags();
			void LoadTexture(std::string file);

			Texture* m_Texture;
			Action* OnClick;
		protected:
		};
	}
}
#endif