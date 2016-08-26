#include "../Keengine/Core/World.hpp"
#include "Bloc.hpp"

#include <iostream>

Bloc::Bloc()
{
	if (getBody() != nullptr)
	{
		getBody()->SetType(b2_staticBody);
	}

	registerComponent(&mComponent);
	attachComponent(&mComponent);

	mComponent.setShape({ { 0.f,0.f },{ 300.f, 0.f },{ 0.f, 20.f } });
}
