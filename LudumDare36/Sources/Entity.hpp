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
		virtual void onDying() const;

		int getTeam() const;
		void setTeam(int team);

		void grantMoney();

		std::string getTarget() const;
		void acquireTarget();

	protected:
		int mLifeStat;
		int mAttackStat;
		int mSpeedStat;

		int mLife;

		int mTeam;

		std::string mTarget;
};

#endif // ENTITY_HPP
