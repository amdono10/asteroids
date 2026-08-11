
#include "laser.hpp"
#include "entity.hpp"
#include "spriteComponent.hpp"
#include "moveComponent.hpp"
#include "circleComponent.hpp"
#include "game.hpp"
#include "asteroid.hpp"

Laser::Laser(Game* game):
Entity(game),
mDeathTimer(1.0f)
{
	// Create a sprite component
	SpriteComponent* sc = new SpriteComponent(this);
	sc->SetTexture(game->GetTexture("Assets/Laser.png"));

	// Create a move component and set a forward speed
	MoveComponent* mc = new MoveComponent(this);
	mc->SetForwardSpeed(800.0f);

	// Create a circle component (for collision)
	mCircle = new CircleComponent(this);
	mCircle->SetRadius(11.0f);
}

void Laser::UpdateEntity(float deltaTime)
{
	// if we run out of time, laser is dead
	mDeathTimer -= deltaTime;
	if (mDeathTimer <= 0.0f)
	{
		SetState(EDead);
	}
	else
	{
		// do we intersect with an asteroid?
		for (auto ast : GetGame()->GetAsteroid())
		{
			if (Intersect(*mCircle, *(ast->GetCircle())))
			{
				// the first asteroid we intersect with, 
				// set ourselves and the asteroid to dead
				SetState(EDead);
				ast->SetState(EDead);
				break;
			}	
		}
	}
}
