#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "../Keengine/Application/Application.hpp"
#include "../Keengine/Core/World.hpp"

#include <SFML/Graphics/Sprite.hpp>

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

		void createData();
		void createActor();
		void createGui();

		void grantMoney(int team, int amount);

	protected:
		ke::World& mWorld;

		std::string mBase1;
		std::string mBase2;

		int mMoney1;
		int mMoney2;

		sf::Sprite mHeadSprite;
		sf::Sprite mBodySprite;
		sf::Sprite mLegsSprite;
		int mHead;
		int mBody;
		int mLegs;

		struct GameData
		{
			GameData();
			GameData(int id, int price, int value);
			int id;
			int price;
			int value;
		};

		std::map<int, GameData> mData;
};

#endif // GAMESTATE_HPP
