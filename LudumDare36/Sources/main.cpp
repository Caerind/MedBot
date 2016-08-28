#include "../Keengine/Application/Application.hpp"

#include "IntroState.hpp"
#include "MenuState.hpp"
#include "TutoState.hpp"
#include "GameState.hpp"
#include "EndState.hpp"

int main()
{
	// Init
	ke::Application::init(); 

	// Maybe set some settings
	// and/or additional initialization
	ke::Application::setView(sf::View({ 800, 450 }, {1600, 900}));
	
	// Create/Load Resources
	ke::Application::registerMusicFile("roback", "roback.ogg");
	ke::Application::playMusic("roback");
	ke::Application::createResource<ke::Font>("futura", "futura.ttf");
	ke::Application::createResource<ke::Texture>("ld36", "ld36.png").setSmooth(true);
	// All others ressources are loaded during the intro state

	// Register States
	ke::Application::registerState<IntroState>("IntroState");
	ke::Application::registerState<MenuState>("MenuState");
	ke::Application::registerState<TutoState>("TutoState");
	ke::Application::registerState<GameState>("GameState");
	ke::Application::registerState<EndState>("EndState");

	// Run
	ke::Application::runState("IntroState");

	ke::Application::removeMusic("roback");

	// Quit properly
	ke::Application::quit();

	return 0;
}