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

		tgui::HorizontalLayout::Ptr addScore(std::string const& index, std::string const& name, std::string const& score);

	protected:
		sf::Text mTitle;
};

#endif // MENUSTATE_HPP
