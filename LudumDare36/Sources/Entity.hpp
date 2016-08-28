#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "../Keengine/Core/Actor.hpp"

#include "../Keengine/Maths/Trigonometry.hpp"

class Entity : public ke::Actor
{
    public:
		Entity();

        typedef std::shared_ptr<Entity> Ptr;

		int getLifeStat() const;
		int getAttackStat() const;
		int getSpeedStat() const;
		void setLifeStat(int life);
		void setAttackStat(int attack);
		void setSpeedStat(int speed);

		int getLife() const;
		void setLife(int life);
		bool inflige(int damage);
		bool isAlive() const;
		bool isDead() const;

		int getTeam() const;
		void setTeam(int team);
		int getEnemyTeam();

		void update(sf::Time dt);

		virtual void onRun();
		virtual void onAttack(sf::Time attackTime);

		std::string getTarget() const;

	protected:
		int mLifeStat;
		int mAttackStat;
		int mSpeedStat;

		int mLife;

		int mTeam;

		std::string mTarget;
		sf::Time mAttackTimer;
};

#endif // ENTITY_HPP
