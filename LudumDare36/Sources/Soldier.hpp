#ifndef SOLDIER_HPP
#define SOLDIER_HPP

#include "Entity.hpp"

#include "../Keengine/Components/AnimatorComponent.hpp"

class Soldier : public Entity
{
    public:
		Soldier(sf::Time gameTime);

        typedef std::shared_ptr<Soldier> Ptr;

	private:
		ke::AnimatorComponent mComponent;
		sf::Time mAttackTimer;
};

#endif // SOLDIER_HPP
