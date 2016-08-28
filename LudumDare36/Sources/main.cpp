#include "../Keengine/Application/Application.hpp"

#include "IntroState.hpp"
#include "MenuState.hpp"
#include "TutoState.hpp"
#include "GameState.hpp"
#include "EndState.hpp"

int main()
{
	// Init
	ke::Application::init("Sources/"); 

	// Maybe set some settings
	// and/or additional initialization
	ke::Application::setView(sf::View({ 800, 450 }, {1600, 900}));
	
	// Create/Load Resources
	ke::Application::registerMusicFile("roback", "Sources/roback.ogg");
	ke::Application::playMusic("roback");
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
	ke::Application::createResource<ke::Texture>("tuto", "Sources/tuto.png");
	ke::Application::createResource<ke::SoundBuffer>("sbad", "Sources/sound_bad.wav");
	ke::Application::createResource<ke::SoundBuffer>("scoin", "Sources/sound_coin.wav");
	ke::Application::createResource<ke::SoundBuffer>("sdier", "Sources/sound_die_robot.wav");
	ke::Application::createResource<ke::SoundBuffer>("sdies", "Sources/sound_die_soldier.wav");
	ke::Application::createResource<ke::SoundBuffer>("sgood", "Sources/sound_good.wav");
	ke::Application::createResource<ke::SoundBuffer>("sspawnr", "Sources/sound_spawn_robot.wav");
	ke::Application::createResource<ke::SoundBuffer>("sspawns", "Sources/sound_spawn_soldier.wav");
	ke::Application::createResource<ke::SoundBuffer>("shit", "Sources/sound_hit.wav");

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