#include "IntroState.hpp"

IntroState::IntroState()
{
	ke::Application::setBackgroundColor(sf::Color::White);
	ke::Application::setBackgroundTexture("ld36", { 0, 0, 1600, 900 });

	ke::Font& font = getApplication().getResource<ke::Font>("futura");
	mTitle.setFont(font);
	mTitle.setOutlineThickness(2.f);
	mTitle.setOutlineColor(sf::Color::Black);
	mTitle.setFillColor(sf::Color::White);
	mTitle.setString("Loading...");
	mTitle.setCharacterSize(80);
	mTitle.setOrigin(mTitle.getGlobalBounds().width * 0.5f, mTitle.getGlobalBounds().height * 0.5f);
	mTitle.setPosition(800, 700);

	mLoaded = false;
}

IntroState::~IntroState()
{
}

bool IntroState::handleEvent(sf::Event const & event)
{
	return false;
}

bool IntroState::update(sf::Time dt)
{
	mElapsed += dt;

	if (!mLoaded)
	{
		ke::Application::createResource<ke::Theme>("css", "widgets.css");
		ke::Application::createResource<ke::Texture>("robot", "robot.png").setSmooth(true);
		ke::Application::createResource<ke::Texture>("back", "back.png").setSmooth(true);
		ke::Application::createResource<ke::Texture>("base", "base.png").setSmooth(true);
		ke::Application::createResource<ke::Texture>("soldier", "soldier.png").setSmooth(true);
		ke::Application::createResource<ke::Texture>("lifebar", "lifebar.png");
		ke::Application::createResource<ke::Texture>("part", "part.png");
		ke::Application::createResource<ke::Texture>("hud", "hud.png");
		ke::Application::createResource<ke::Texture>("tuto", "tuto.png");
		ke::Application::createResource<ke::SoundBuffer>("sbad", "sound_bad.wav");
		ke::Application::createResource<ke::SoundBuffer>("scoin", "sound_coin.wav");
		ke::Application::createResource<ke::SoundBuffer>("sdier", "sound_die_robot.wav");
		ke::Application::createResource<ke::SoundBuffer>("sdies", "sound_die_soldier.wav");
		ke::Application::createResource<ke::SoundBuffer>("sgood", "sound_good.wav");
		ke::Application::createResource<ke::SoundBuffer>("sspawnr", "sound_spawn_robot.wav");
		ke::Application::createResource<ke::SoundBuffer>("sspawns", "sound_spawn_soldier.wav");
		ke::Application::createResource<ke::SoundBuffer>("shit", "sound_hit.wav");
		mLoaded = true;
	}

	if (mElapsed >= sf::seconds(0.5f) && mLoaded)
	{
		clearStates();
		pushState("MenuState");
	}
	return false;
}

void IntroState::render(sf::RenderTarget & target, sf::RenderStates states)
{
	target.draw(mTitle);
}
