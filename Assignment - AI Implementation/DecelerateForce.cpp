#include "DecelerateForce.h"



DecelerateForce::DecelerateForce()
{
}


DecelerateForce::~DecelerateForce()
{
}

Vector2 DecelerateForce::getForce(GameObject * gameObject)
{
	Vector2 dir(0,0);
	Vector2 vel;
	float speed;
	gameObject->getSpeed(speed);
	gameObject->getVelocity(vel);
	dir.x -= vel.x;
	dir.y -= vel.y;
	dir.normalise();
	dir * (speed * 0.5f);
	return Vector2();
}
