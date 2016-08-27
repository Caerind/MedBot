#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "../Keengine/Application/Application.hpp"
#include "../Keengine/Core/World.hpp"

#include "MyMap.hpp"
#include "Robot.hpp"
#include "Soldier.hpp"
#include "Base.hpp"

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

		void createActor();
		void createGui();

		void grantMoney(int team, int amount);

	protected:
		ke::World& mWorld;

		std::string mBase1;
		std::string mBase2;

		int mMoney1;
		int mMoney2;
};

#endif // GAMESTATE_HPP
