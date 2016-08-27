#ifndef BASE_HPP
#define BASE_HPP

#include "Entity.hpp"

#include "../Keengine/Components/SpriteComponent.hpp"

class Base : public Entity
{
    public:
		Base(int  team);

		void update(sf::Time dt);

        typedef std::shared_ptr<Base> Ptr;

	private:
		ke::SpriteComponent mSprite;
		ke::SpriteComponent mLifeBack;
		ke::SpriteComponent mLifeBar;
};

#endif // MYACTOR_HPP
