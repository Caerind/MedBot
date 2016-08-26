#include "CollisionComponent.hpp"
#include "../Core/Actor.hpp"
#include <iostream>

namespace ke
{

CollisionComponent::CollisionComponent()
{
	mFixture = nullptr;
}

void CollisionComponent::onRegister()
{
	if (mActor != nullptr)
	{
		b2Body* actorBody = mActor->getBody();
		if (actorBody != nullptr)
		{
			b2FixtureDef fDef;
			b2PolygonShape shape;
			fDef.shape = &shape;
			mFixture = actorBody->CreateFixture(&fDef);
			mFixture->SetUserData(this);
		}
	}
}

void CollisionComponent::onUnregister()
{
	if (mActor != nullptr)
	{
		b2Body* actorBody = mActor->getBody();
		if (actorBody != nullptr)
		{
			actorBody->DestroyFixture(mFixture);
			mFixture = nullptr;
		}
	}
}

b2Fixture* CollisionComponent::getFixture()
{
	return mFixture;
}

b2Shape* CollisionComponent::getShape()
{
	if (mFixture != nullptr)
	{
		return mFixture->GetShape();
	}
	return nullptr;
}

void CollisionComponent::setShape(std::vector<sf::Vector2f> shape)
{
	b2PolygonShape* polygon = static_cast<b2PolygonShape*>(mFixture->GetShape());
	if (polygon != nullptr)
	{
		b2Vec2 vertices[8];
		for (std::size_t i = 0; i < shape.size(); i++)
		{
			vertices[i] = shape[i] * ke::Physic::conv;
		}
		polygon->Set(vertices, shape.size());
	}
}

} // namespace ke