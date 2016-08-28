#ifndef ROBOT_HPP
#define ROBOT_HPP

#include "Entity.hpp"

#include "../Keengine/Components/AnimatorComponent.hpp"
#include "../Keengine/Components/SpriteComponent.hpp"

class Robot : public Entity
{
    public:
		Robot(int head, int body, int legs);

		void onRun();
		void onAttack(sf::Time attackTimer);

        typedef std::shared_ptr<Robot> Ptr;

	private:
		ke::SpriteComponent mHead;
		ke::SpriteComponent mBody;
		ke::AnimatorComponent mLegs;
		ke::AnimatorComponent mArms;
		sf::Time mAttackTimer;
};

#endif // ROBOT_HPP
