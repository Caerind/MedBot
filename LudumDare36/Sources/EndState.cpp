#include "EndState.hpp"

EndState::EndState()
{
	mSent = false;

	mHide.setTexture(getApplication().getResource<ke::Texture>("ld36"));
	mHide.setTextureRect({ 450,375,1,160 });
	mHide.setPosition({ 450, 375 });
	mHide.setScale(700.f, 1.f);

	bool win = (ke::Application::getValues().getProperty("winner") == "1");
	std::string score = ke::Application::getValues().getProperty("score");

	ke::Application::setBackgroundTexture("ld36", { 0,0,1600,900 });
	
	ke::Theme& theme = ke::Application::getResource<ke::Theme>("css");
	ke::Font& font = ke::Application::getResource<ke::Font>("futura");

	if (!win)
	{
		mSent = true;
	}

	mInfo.setFont(font);
	mInfo.setOutlineThickness(2.f);
	mInfo.setOutlineColor(sf::Color::Black);
	mInfo.setFillColor(sf::Color::White);
	mInfo.setString((win) ? "Victory !" : "Defeat...");
	mInfo.setCharacterSize(100);
	mInfo.setOrigin(mInfo.getGlobalBounds().width * 0.5f, mInfo.getGlobalBounds().height * 0.5f);
	mInfo.setPosition(800, 150);

	mScore.setFont(font);
	mScore.setOutlineThickness(2.f);
	mScore.setOutlineColor(sf::Color::Black);
	mScore.setFillColor(sf::Color::White);
	mScore.setString("Score : " + score);
	mScore.setCharacterSize(80);
	mScore.setOrigin(mScore.getGlobalBounds().width * 0.5f, mScore.getGlobalBounds().height * 0.5f);
	mScore.setPosition(800, 300);

	if (win)
	{
		mBox = theme.create("EditBox");
		mBox->setSize(300, 100);
		mBox->setPosition(600, 450);
		mBox->setDefaultText("Username");
		mBox->setTextSize(40);
		mGui.add(mBox);

		mSend = theme.create("Button");
		mSend->setSize(100, 100);
		mSend->setPosition(900, 450);
		mSend->setText("Send");
		mSend->setTextSize(40);
		mGui.add(mSend);

		mSend->connect("pressed", [&]()
		{
			if (!mSent)
			{
				std::string name = mBox->getText().toAnsiString();
				std::ostringstream oss;
				oss << "action=insert&name=" << name << "&score=" << ke::Application::getValues().getProperty("score");
				getApplication().getLog() << "Sending : " + oss.str();
				if (ke::HttpThread::sendHttpRequest("http://atmog.altervista.org/medbot.php", oss.str()))
				{
					getApplication().getLog() << "Sent !";
					mSent = true;
					mSend->setSize(400, 100);
					mSend->setPosition(600, 450);
					mSend->setText("Play Again !");
					mSend->setTextSize(40);
				}
			}
			else
			{
				clearStates();
				pushState("GameState");
			}
		});
	}
	else
	{
		tgui::Button::Ptr retry = theme.create("Button");
		retry->setSize(400, 100);
		retry->setPosition(600, 450);
		retry->setText("Try Again !");
		retry->setTextSize(40);
		mGui.add(retry);

		retry->connect("pressed", [&]()
		{
			clearStates();
			pushState("TutoState");
		});
	}

	tgui::Button::Ptr quit = theme.create("Button");
	quit->setSize(400, 100);
	quit->setPosition(600, 600);
	quit->setText("Go to Menu");
	quit->setTextSize(40);
	mGui.add(quit);

	quit->connect("pressed", [&]()
	{
		clearStates();
		pushState("MenuState");
	});
}

EndState::~EndState()
{
}

bool EndState::handleEvent(sf::Event const & event)
{
	mGui.handleEvent(event);
	return false;
}

bool EndState::update(sf::Time dt)
{
	return false;
}

void EndState::render(sf::RenderTarget & target, sf::RenderStates states)
{
	target.draw(mHide);
	target.draw(mInfo);
	target.draw(mScore);
	mGui.draw();
}
