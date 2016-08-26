#ifndef KE_COLLISIONCOMPONENT_HPP
#define KE_COLLISIONCOMPONENT_HPP

#include <Box2D\Box2D.h>

#include "../Core/PhysicSystem.hpp"
#include "../Core/SceneComponent.hpp"

namespace ke
{

class CollisionComponent : public SceneComponent
{
	public:
		CollisionComponent();

		void onRegister();
		void onUnregister();

		b2Fixture* getFixture();
		b2Shape* getShape();

		void setShape(std::vector<sf::Vector2f> shape);

	protected:
		b2Fixture* mFixture;
};

} // namespace ke

#endif // KE_COLLISIONCOMPONENT_HPP
