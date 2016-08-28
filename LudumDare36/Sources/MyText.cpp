#include "../Keengine/Core/World.hpp"
#include "MyText.hpp"

#include <iostream>

MyText::MyText(int amount)
{
	setZ(150.f);

	mTime = sf::Time::Zero;

	registerComponent(&mText);
	attachComponent(&mText);
	mText.setFont("futura");
	mText.setString("+$" + std::to_string(amount));
	mText.setFillColor(sf::Color::White);
	mText.setOutlineColor(sf::Color::Black);
	mText.setOutlineThickness(2.f);
	mText.setSize(20);
	mText.move({ 30.f, -5.f });

	registerComponent(&mCoins);
	attachComponent(&mCoins);
	mCoins.setTexture("hud");
	mCoins.setTextureRect({ 0,0,25,25 });
}

void MyText::update(sf::Time dt)
{
	mTime += dt;
	if (mTime < sf::seconds(1.f))
	{
		move(sf::Vector2f(0.f, -1.f) * dt.asSeconds() * 200.f);
	}
	if (mTime >= sf::seconds(2.f))
	{
		remove();
	}
}
