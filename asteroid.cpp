
#include "asteroid.hpp"
#include "math.hpp"
#include "spriteComponent.hpp"
#include "moveComponent.hpp"
#include "circleComponent.hpp"
#include "game.hpp"
#include "random.hpp"

Asteroid::Asteroid(Game* game):
Entity(game),
mCircle(nullptr)
{
	// Initialize to random position / orientation
	Vector2 randPos = Random::GetVector(Vector2::Zero, Vector2(1024, 768));
	SetPosition(randPos);

	SetRotation(Random::GetFloatRange(0.0f, Math::TwoPi));

	// create a sprite component
	SpriteComponent* sc = new SpriteComponent(this);
	sc->SetTexture(game->GetTexture("Assets/Asteroid.png"));

	// create a move component, and set a forward speed
	MoveComponent* mc = new MoveComponent(this);
	mc->SetForwardSpeed(150.0f);

	// create a circle component (for collision)
	mCircle = new CircleComponent(this);
	mCircle->SetRadius(40.0f);

	// add to mAsteroids in game
	game->AddAsteroid(this);
}

Asteroid::~Asteroid()
{
	GetGame()->RemoveAsteroid(this);
}