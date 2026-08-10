
#ifndef _ASTEROID_HPP
#define _ASTEROID_HPP

#include "circleComponent.hpp"
#include "entity.hpp"

class Asteroid : public Entity
{
public:
	Asteroid(class Game* game);
	~Asteroid();

	class CircleComponent* GetCircle() { return mCircle; }

private:
	class CircleComponent* mCircle;
};

#endif	// _ASTEROID_HPP