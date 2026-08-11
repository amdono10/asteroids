#include "ship.hpp"
#include "spriteComponent.hpp"
#include "inputComponent.hpp"
#include "game.hpp"
#include "laser.hpp"

Ship::Ship(Game* game):
	Entity(game),
	mLaserCooldown(0.0f)
{
	// create a sprite component
	SpriteComponent* sc = new SpriteComponent(this);
	sc->SetTexture(game->GetTexture("Assets/Ship.png"));
	
	// create an input component and set keys/speed
	InputComponent* ic = new InputComponent(this);
	ic->SetForwardKey(SDL_SCANCODE_W);
	ic->SetBackKey(SDL_SCANCODE_S);
	ic->SetClockwiseKey(SDL_SCANCODE_A);
	ic->SetCounterClockwiseKey(SDL_SCANCODE_D);
	ic->SetMaxForwardSpeed(300.0f);
	ic->SetMaxAngularSpeed(Math::TwoPi);

}

void Ship::UpdateEntity(float deltaTime)
{
	mLaserCooldown -= deltaTime;	
}

void Ship::EntityInput(const bool* keyState)
{
	if(keyState[SDL_SCANCODE_SPACE] && mLaserCooldown <= 0.0f)
	{
		// create a laser and set its position/rotation to mine
		Laser* laser = new Laser(GetGame());
		laser->SetPosition(GetPosition());
		laser->SetRotation(GetRotation());
		
		// Reset laser cooldown (half second)
		mLaserCooldown = 0.5f;
	}
}
