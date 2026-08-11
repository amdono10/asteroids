
#ifndef _MOVE_COMPONENT_HPP
#define _MOVE_COMPONENT_HPP

#include "component.hpp"
#include "entity.hpp"


class MoveComponent : public Component
{
public:
	// lower udate order to update first
	MoveComponent(class Entity* owner, int updateOrder = 10);

	void Update(float deltaTime) override;

	float GetAngularSpeed() const { return mAngularSpeed; }
	float GetForwardSpeed() const { return mForwardSpeed; }
	void SetAngularSpeed(float speed) { mAngularSpeed = speed; }
	void SetForwardSpeed(float speed) { mForwardSpeed = speed; }

private:
	// controls rotation (radians / second)
	float mAngularSpeed;
	// controls forward movement (units / second)
	float mForwardSpeed;
};

#endif	// _MOVE_COMPONENT_HPP