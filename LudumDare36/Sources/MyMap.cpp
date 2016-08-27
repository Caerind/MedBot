#include "../Keengine/Core/World.hpp"
#include "MyMap.hpp"

#include <iostream>

MyMap::MyMap()
{
	setZ(-1000.f);
	registerComponent(&mBackground);
	attachComponent(&mBackground);
	ke::Texture& texture = getWorld().getResource<ke::Texture>("back");
	texture.setRepeated(true);
	texture.setSmooth(true);
	mBackground.setTexture(texture);
	mBackground.setTextureRect(sf::IntRect(0, 0, 800, 225));
	mBackground.scale({ 2.f, 2.f });
}
