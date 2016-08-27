#ifndef SOLDIER_HPP
#define SOLDIER_HPP

#include "Entity.hpp"

#include "../Keengine/Components/AnimatorComponent.hpp"

class Soldier : public Entity
{
    public:
		Soldier();

		void update(sf::Time dt);

        typedef std::shared_ptr<Soldier> Ptr;

	private:
		ke::AnimatorComponent mComponent;

		std::string mTarget;
};

#endif // SOLDIER_HPP
