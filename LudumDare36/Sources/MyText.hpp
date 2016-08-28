#ifndef MYTEXT_HPP
#define MYTEXT_HPP

#include "../Keengine/Core/Actor.hpp"

#include "../Keengine/Components/TextComponent.hpp"
#include "../Keengine/Components/SpriteComponent.hpp"

class MyText : public ke::Actor
{
    public:
		MyText(int amount);

		void update(sf::Time dt);

        typedef std::shared_ptr<MyText> Ptr;

	private:
		ke::TextComponent mText;
		ke::SpriteComponent mCoins;
		sf::Time mTime;
};

#endif // MYMAP_HPP
