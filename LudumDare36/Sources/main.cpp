#include "../Keengine/Application/Application.hpp"

#include "GameState.hpp"

int main()
{
	// Init
	ke::Application::init("Sources/"); 

	// Maybe set some settings
	// and/or additional initialization
	
	// Create/Load Resources
	ke::Application::createResource<ke::Theme>("css", "Sources/widgets.css");
	ke::Application::createResource<ke::Font>("futura", "Sources/futura.ttf");

	// Register States
	ke::Application::registerState<GameState>("GameState");

	// Run
	ke::Application::runState("GameState");

	// Quit properly
	ke::Application::quit();

	return 0;
}