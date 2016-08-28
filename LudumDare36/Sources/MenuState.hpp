#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

#include "../Keengine/Application/Application.hpp"

class MenuState : public ke::State
{
	public:
		MenuState();
		~MenuState();

		bool handleEvent(sf::Event const& event);
		bool update(sf::Time dt);
		void render(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default);

	protected:
};

#endif // MENUSTATE_HPP
