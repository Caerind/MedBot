#ifndef MYACTOR_HPP
#define MYACTOR_HPP

#include "../Keengine/Core/Actor.hpp"

#include "../Keengine/Components/CollisionComponent.hpp"
#include "../Keengine/Components/PointComponent.hpp"
#include "../Keengine/Components/InputComponent.hpp"
#include "../Keengine/Components/CameraComponent.hpp"
#include "../Keengine/Components/SpriteComponent.hpp"

class MyActor : public ke::Actor
{
    public:
		MyActor();

        typedef std::shared_ptr<MyActor> Ptr;

	private:
		ke::CollisionComponent mComponent;
		ke::PointComponent mPoint;
		ke::InputComponent mInput;
		ke::CameraComponent mCamera;
		ke::SpriteComponent mSprite;
};

#endif // MYACTOR_HPP
