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
	ke::Application::createResource<ke::Texture>("ld36", "Sources/ld36.png").setSmooth(true);
	ke::Application::createResource<ke::Texture>("robot", "Sources/robot.png").setSmooth(true);
	ke::Application::createResource<ke::Texture>("back", "Sources/back.png").setSmooth(true);
	ke::Application::createResource<ke::Texture>("base", "Sources/base.png").setSmooth(true);
	ke::Application::createResource<ke::Texture>("soldier", "Sources/soldier.png").setSmooth(true);
	ke::Application::createResource<ke::Texture>("lifebar", "Sources/lifebar.png");
	ke::Application::createResource<ke::Texture>("part", "Sources/part.png");
	ke::Application::createResource<ke::Texture>("hud", "Sources/hud.png");

	// Register States
	ke::Application::registerState<GameState>("GameState");

	// Run
	ke::Application::runState("GameState");

	// Quit properly
	ke::Application::quit();

	return 0;
}