#ifndef INTROSTATE_HPP
#define INTROSTATE_HPP

#include "../Keengine/Application/Application.hpp"

class IntroState : public ke::State
{
	public:
		IntroState();
		~IntroState();

		bool handleEvent(sf::Event const& event);
		bool update(sf::Time dt);
		void render(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default);

	protected:
		sf::Time mElapsed;
		sf::Text mTitle;
		bool mLoaded;
};

#endif // INTROSTATE_HPP
