#include "TutoState.hpp"

TutoState::TutoState()
{
	ke::Application::setBackgroundTexture("tuto", { 0,0,1600,900 });

	ke::Theme& theme = getApplication().getResource<ke::Theme>("css");
	tgui::Button::Ptr buttonGame = theme.create("Button");
	buttonGame->setSize({ 400,100 });
	buttonGame->setPosition({ 1600 - 400 - 60, 100 });
	buttonGame->setText(" Skip tutorial ");
	buttonGame->connect("pressed", [&]()
	{
		clearStates();
		pushState("GameState");
	});
	mGui.add(buttonGame);
	tgui::Button::Ptr buttonQuit = theme.create("Button");
	buttonQuit->setSize({ 400,100 });
	buttonQuit->setPosition({ 60, 100 });
	buttonQuit->setText("Return to menu");
	buttonQuit->connect("pressed", [&]()
	{
		clearStates();
		pushState("MenuState");
	});
	mGui.add(buttonQuit);

	mFrench = false;

	mTuto.setTexture(getApplication().getResource<ke::Texture>("tuto"));
	mTuto.setTextureRect({ 1600,mFrench * 222,649,222 });
	mTuto.setPosition(466, 57);

	tgui::CheckBox::Ptr fr = theme.create("CheckBox");
	fr->setSize(50, 50);
	fr->setPosition(1600 - 400 - 60, 220);
	fr->uncheck();
	fr->connect("checked", [&]() {
		mFrench = true;
		mTuto.setTextureRect({ 1600,mFrench * 222,649,222 });
	});
	fr->connect("unchecked", [&]() {
		mFrench = false;
		mTuto.setTextureRect({ 1600,mFrench * 222,649,222 });
	});
	mGui.add(fr);
	tgui::Label::Ptr frLabel = theme.create("Label");
	frLabel->setTextSize(30);
	frLabel->setPosition(fr->getPosition() + sf::Vector2f(70, 10));
	frLabel->setText("French");
	frLabel->setTextColor(sf::Color::Black);
	mGui.add(frLabel);
}

TutoState::~TutoState()
{
}

bool TutoState::handleEvent(sf::Event const & event)
{
	mGui.handleEvent(event);
	return false;
}

bool TutoState::update(sf::Time dt)
{
	return false;
}

void TutoState::render(sf::RenderTarget & target, sf::RenderStates states)
{
	target.draw(mTuto);
	mGui.draw();
}
