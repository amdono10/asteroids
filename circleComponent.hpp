
#ifndef _CIRCLE_COMPONENT_HPP
#define _CIRCLE_COMPONENT_HPP

#include "component.hpp"
#include "math.hpp"

class CircleComponent : public Component
{
public:
	CircleComponent(class Entity* owner);

	void SetRadius(float radius) { mRadius = radius; }
	float GetRadius() const;

	const Vector2& GetCenter() const;

private:
	float mRadius;

};

bool Intersect(const CircleComponent& a, const CircleComponent& b);


#endif	// _CIRCLE_COMPONENT_HPP