#include "MenuState.hpp"

MenuState::MenuState()
{
	ke::Application::setBackgroundTexture("ld36", { 0,0,1600,900 });

	ke::Theme& theme = getApplication().getResource<ke::Theme>("css");

	// TODO : Title

    tgui::Button::Ptr buttonGame = theme.create("Button");
	buttonGame->setSize({ 400,100 });
	buttonGame->setPosition({ 600, 300 });
	buttonGame->setText("Play");
    buttonGame->connect("pressed", [&]()
    {
		clearStates();
		pushState("TutoState");
    });
	mGui.add(buttonGame);

	// TODO : Scores

	tgui::Button::Ptr buttonQuit = theme.create("Button");
	buttonQuit->setSize({ 400,100 });
	buttonQuit->setPosition({ 600, 750 });
	buttonQuit->setText("Quit");
	buttonQuit->connect("pressed", [&]()
	{
		clearStates();
	});
	mGui.add(buttonQuit);
}

MenuState::~MenuState()
{
}

bool MenuState::handleEvent(sf::Event const & event)
{
	mGui.handleEvent(event);
	return false;
}

bool MenuState::update(sf::Time dt)
{
	return false;
}

void MenuState::render(sf::RenderTarget & target, sf::RenderStates states)
{
	mGui.draw();
}
