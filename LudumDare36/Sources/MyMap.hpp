#ifndef MYMAP_HPP
#define MYMAP_HPP

#include "../Keengine/Core/Actor.hpp"

#include "../Keengine/Components/SpriteComponent.hpp"

class MyMap : public ke::Actor
{
    public:
		MyMap();

        typedef std::shared_ptr<MyMap> Ptr;

	private:
		ke::SpriteComponent mBackground;
};

#endif // MYMAP_HPP
