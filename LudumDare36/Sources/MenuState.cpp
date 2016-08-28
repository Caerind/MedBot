#include "MenuState.hpp"

MenuState::MenuState()
{
	ke::Application::setBackgroundTexture("ld36", { 0,0,1600,900 });

	ke::Theme& theme = getApplication().getResource<ke::Theme>("css");

	ke::Font& font = getApplication().getResource<ke::Font>("futura");

	mTitle.setFont(font);
	mTitle.setOutlineThickness(2.f);
	mTitle.setOutlineColor(sf::Color::Black);
	mTitle.setFillColor(sf::Color::White);
	mTitle.setString("Medbot");
	mTitle.setCharacterSize(100);
	mTitle.setOrigin(mTitle.getGlobalBounds().width * 0.5f, mTitle.getGlobalBounds().height * 0.5f);
	mTitle.setPosition(800, 150);

    tgui::Button::Ptr buttonGame = theme.create("Button");
	buttonGame->setSize({ 400,60 });
	buttonGame->setPosition({ 600, 300 });
	buttonGame->setText("Play");
    buttonGame->connect("pressed", [&]()
    {
		clearStates();
		pushState("TutoState");
    });
	mGui.add(buttonGame);

	tgui::VerticalLayout::Ptr vlayout = std::make_shared<tgui::VerticalLayout>();
	vlayout->setPosition(400, 385);
	vlayout->setSize(800, 380);
	mGui.add(vlayout);

	std::string rep;
	if (ke::HttpThread::sendHttpRequest("http://atmog.altervista.org/medbot.php", "action=read", &rep))
	{
		std::istringstream iss(rep);
		std::size_t i = 1;
		vlayout->add(addScore("Leaderboard", "Name", "Score", true));
		while (std::getline(iss, rep))
		{
			std::size_t found = rep.find_last_of(" ");
			if (found != std::string::npos)
			{
				std::string name = rep.substr(0, found);
				std::string score = rep.substr(found + 1);
				vlayout->add(addScore(std::to_string(i), name, score));
			}
			i++;
		}
	}

	tgui::Button::Ptr buttonQuit = theme.create("Button");
	buttonQuit->setSize({ 400,60 });
	buttonQuit->setPosition({ 600, 790 });
	buttonQuit->setText("Quit");
	buttonQuit->connect("pressed", [&]()
	{
		clearStates();
	});
	mGui.add(buttonQuit);

	tgui::CheckBox::Ptr musicBox = theme.create("CheckBox");
	musicBox->setSize(75, 75);
	musicBox->setPosition(1300, 500);
	if (ke::Application::getMusicVolume() >= 50.f)
	{
		musicBox->check();
	}
	else
	{
		musicBox->uncheck();
	}
	musicBox->connect("checked", []() { ke::Application::setMusicVolume(100.f); });
	musicBox->connect("unchecked", []() { ke::Application::setMusicVolume(0.f); });
	mGui.add(musicBox);

	tgui::CheckBox::Ptr soundBox = theme.create("CheckBox");
	soundBox->setSize(75, 75);
	soundBox->setPosition(1300, 600);
	if (ke::Application::getSoundVolume() >= 50.f)
	{
		soundBox->check();
	}
	else
	{
		soundBox->uncheck();
	}
	soundBox->connect("checked", []() { ke::Application::setSoundVolume(100.f); });
	soundBox->connect("unchecked", []() { ke::Application::setSoundVolume(0.f); });
	mGui.add(soundBox);

	tgui::Label::Ptr musicLabel = theme.create("Label");
	musicLabel->setPosition(1400, 530);
	musicLabel->setText("Music");
	mGui.add(musicLabel);

	tgui::Label::Ptr soundLabel = theme.create("Label");
	soundLabel->setPosition(1400, 630);
	soundLabel->setText("Sound");
	mGui.add(soundLabel);
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
	target.draw(mTitle);
}

tgui::HorizontalLayout::Ptr MenuState::addScore(std::string const& index, std::string const & name, std::string const & score, bool title)
{
	tgui::HorizontalLayout::Ptr h = std::make_shared<tgui::HorizontalLayout>();

	tgui::Button::Ptr i = getApplication().getResource<ke::Theme>("css").create((title) ? "title" : "score");
	i->setText(index);
	i->getRenderer()->setTextColor(sf::Color::White);
	i->getRenderer()->setTextColorDown(sf::Color::White);
	i->getRenderer()->setTextColorNormal(sf::Color::White);
	i->getRenderer()->setTextColorHover(sf::Color::White);
	h->add(i);

	tgui::Button::Ptr n = getApplication().getResource<ke::Theme>("css").create((title) ? "title" : "score");
	n->setText(name);
	n->getRenderer()->setTextColor(sf::Color::White);
	n->getRenderer()->setTextColorDown(sf::Color::White);
	n->getRenderer()->setTextColorNormal(sf::Color::White);
	n->getRenderer()->setTextColorHover(sf::Color::White);
	h->add(n);

	tgui::Button::Ptr s = getApplication().getResource<ke::Theme>("css").create((title) ? "title" : "score");
	s->setText(score);
	s->getRenderer()->setTextColor(sf::Color::White);
	s->getRenderer()->setTextColorDown(sf::Color::White);
	s->getRenderer()->setTextColorNormal(sf::Color::White);
	s->getRenderer()->setTextColorHover(sf::Color::White);
	h->add(s);

	return h;
}
