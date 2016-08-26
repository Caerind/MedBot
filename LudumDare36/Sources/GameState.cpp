#include "GameState.hpp"

GameState::GameState()
	: mWorld(ke::World::createInstance())
{
	// Register inputs
	mWorld.getInputs().setKeyboardMapping("MoveUp", sf::Keyboard::Z, ke::InputType::Hold);
	mWorld.getInputs().setKeyboardMapping("MoveLeft", sf::Keyboard::Q, ke::InputType::Hold);
	mWorld.getInputs().setKeyboardMapping("MoveDown", sf::Keyboard::S, ke::InputType::Hold);
	mWorld.getInputs().setKeyboardMapping("MoveRight", sf::Keyboard::D, ke::InputType::Hold);
	mWorld.getInputs().setMouseMapping("ClickLeft", sf::Mouse::Left, ke::InputType::Pressed);

	// If existing key binding, load it
	mWorld.getInputs().loadFromFile("Sources/inputs.cfg");

	// Bind action
	mWorld.getInputs().bindAction("ClickLeft", [&](std::vector<std::string> const& data)
	{
		// What to do when mouse click ?
		return false;
	});

	mWorld.getPhysic().setRenderDebug(true);

	mWorld.createActor<MyActor>()->setPosition({ 200.f, 200.f });
	mWorld.createActor<Bloc>()->setPosition({ -30.f, 500.f });
	mWorld.createActor<ke::Map>()->loadTmxFile("Sources/map.tmx");

}

GameState::~GameState()
{
	// Save key binding
	mWorld.getInputs().saveToFile("Sources/inputs.cfg");

	// Destroy the world
	ke::World::destroyInstance();
}

bool GameState::handleEvent(sf::Event const& event)
{
	mWorld.handleEvent(event);
	mGui.handleEvent(event);
	return false;
}

bool GameState::update(sf::Time dt)
{
	mWorld.update(dt);
	return false;
}

void GameState::render(sf::RenderTarget & target, sf::RenderStates states)
{
	mWorld.render(target);
	mGui.draw();
}

void GameState::onActivate()
{
}

void GameState::onDeactivate()
{
}