#ifndef TUTOSTATE_HPP
#define TUTOSTATE_HPP

#include "../Keengine/Application/Application.hpp"

class TutoState : public ke::State
{
	public:
		TutoState();
		~TutoState();

		bool handleEvent(sf::Event const& event);
		bool update(sf::Time dt);
		void render(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default);
};

#endif // TUTOSTATE_HPP
