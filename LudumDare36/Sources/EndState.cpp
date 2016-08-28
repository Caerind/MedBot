#include "EndState.hpp"

EndState::EndState()
{
	mSent = false;

	ke::Application::setBackgroundTexture("ld36", { 0,0,1600,900 });
	
	ke::Theme& theme = ke::Application::getResource<ke::Theme>("css");
	bool win = (ke::Application::getValues().getProperty("winner") == "1");
	std::string score = ke::Application::getValues().getProperty("score");

	if (!win)
	{
		mSent = true;
	}

	tgui::Label::Ptr iLabel = theme.create("Label");
	iLabel->setText((win) ? "Victory !" : "Defeat...");
	iLabel->setSize(400, 100);
	iLabel->setPosition(600, 150);
	mGui.add(iLabel);

	tgui::Label::Ptr sLabel = theme.create("Label");
	sLabel->setText("Score : " + score);
	sLabel->setSize(400, 100);
	sLabel->setPosition(600, 300);
	mGui.add(sLabel);

	if (win)
	{
		mBox = theme.create("EditBox");
		mBox->setSize(300, 100);
		mBox->setPosition(600, 450);
		mBox->setDefaultText("Username");
		mGui.add(mBox);

		mSend = theme.create("Button");
		mSend->setSize(100, 100);
		mSend->setPosition(900, 450);
		mSend->setText("Send");
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
					mSend->setText("Sent !");
				}
			}

		});
	}
	else
	{
		tgui::Button::Ptr retry = theme.create("Button");
		retry->setSize(400, 100);
		retry->setPosition(600, 450);
		retry->setText("Try Again !");
		mGui.add(retry);

		retry->connect("pressed", [&]()
		{
			clearStates();
			pushState("IntroState");
		});
	}

	tgui::Button::Ptr quit = theme.create("Button");
	quit->setSize(400, 100);
	quit->setPosition(600, 600);
	quit->setText("Go to Menu");
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
	mGui.draw();
}
