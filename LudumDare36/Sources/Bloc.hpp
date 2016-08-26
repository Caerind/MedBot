#ifndef BLOC_HPP
#define BLOC_HPP

#include "../Keengine/Core/Actor.hpp"

#include "../Keengine/Components/CollisionComponent.hpp"

class Bloc : public ke::Actor
{
    public:
		Bloc();

        typedef std::shared_ptr<Bloc> Ptr;

	private:
		ke::CollisionComponent mComponent;
};

#endif // BLOC_HPP
