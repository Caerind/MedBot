#ifndef ROBOT_HPP
#define ROBOT_HPP

#include "Entity.hpp"

#include "../Keengine/Components/AnimatorComponent.hpp"

class Robot : public Entity
{
    public:
		Robot();

		void update(sf::Time dt);

        typedef std::shared_ptr<Robot> Ptr;

	private:
		ke::AnimatorComponent mComponent;
		sf::Time mAttackTimer;
};

#endif // ROBOT_HPP
