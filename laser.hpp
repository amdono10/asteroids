
#ifndef _LASER_HPP
#define _LASER_HPP

#include "entity.hpp"

class Laser : public Entity
{
public:
	Laser(class Game* game);

	void UpdateEntity(float deltaTime) override;

private:
	class CircleComponent* mCircle;
	float mDeathTimer;
};

#endif	// _LASER_HPP