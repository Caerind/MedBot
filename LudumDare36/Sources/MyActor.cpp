#include "../Keengine/Core/World.hpp"
#include "MyActor.hpp"

#include <iostream>

MyActor::MyActor()
{
	registerComponent(&mComponent);
	attachComponent(&mComponent);
	mComponent.setShape({ {-40,-30.f}, {40.f, -30.f}, {40.f, 0.f}, {-40.f, 0.f} });

	registerComponent(&mPoint);
	attachComponent(&mPoint);

	registerComponent(&mCamera);
	attachComponent(&mCamera);
	mCamera.setPosition({ 0.f, 0.f });

	registerComponent(&mInput);
	mInput.bindAction("MoveUp", [&](std::vector<std::string> const& data)
	{
		float impulse = getBody()->GetMass() * (-5 - getBody()->GetLinearVelocity().y);
		getBody()->ApplyLinearImpulse(b2Vec2(0.f, impulse), getBody()->GetWorldCenter(), true);
		return false;
	});
	mInput.bindAction("MoveDown", [&](std::vector<std::string> const& data)
	{
		float impulse = getBody()->GetMass() * (5 - getBody()->GetLinearVelocity().y);
		getBody()->ApplyLinearImpulse(b2Vec2(0.f, impulse), getBody()->GetWorldCenter(), true);
		return false;
	});
	mInput.bindAction("MoveRight", [&](std::vector<std::string> const& data)
	{
		float impulse = getBody()->GetMass() * (5 - getBody()->GetLinearVelocity().x);
		getBody()->ApplyLinearImpulse(b2Vec2(impulse, 0.f), getBody()->GetWorldCenter(), true);
		return false;
	});
	mInput.bindAction("MoveLeft", [&](std::vector<std::string> const& data)
	{
		float impulse = getBody()->GetMass() * (-5 - getBody()->GetLinearVelocity().x);
		getBody()->ApplyLinearImpulse(b2Vec2(impulse, 0.f), getBody()->GetWorldCenter(), true);
		return false;
	});

	registerComponent(&mSprite);
	attachComponent(&mSprite);
	mSprite.setTexture("ld36");
	mSprite.scale({ 0.05f, 0.1f });
	mSprite.move({ -40.f, -90.f });
}
