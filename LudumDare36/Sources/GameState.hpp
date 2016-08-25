#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "../Keengine/Application/Application.hpp"
#include "../Keengine/Core/World.hpp"

class GameState : public ke::State
{
	public:
		GameState();
		~GameState();

		bool handleEvent(sf::Event const& event);
		bool update(sf::Time dt);
		void render(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default);

		void onActivate();
		void onDeactivate();

	protected:
		ke::World& mWorld;
};

#endif // GAMESTATE_HPP
