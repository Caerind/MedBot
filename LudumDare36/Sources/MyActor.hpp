#ifndef MYACTOR_HPP
#define MYACTOR_HPP

#include "../Keengine/Core/Actor.hpp"

class MyActor : public ke::Actor
{
    public:
		MyActor();

        typedef std::shared_ptr<MyActor> Ptr;

	private:
};

#endif // MYACTOR_HPP
