#include "WanderForce.h"



WanderForce::WanderForce()
{
}


WanderForce::~WanderForce()
{
}

Vector2 WanderForce::getForce(GameObject * gameObject)
{
	srand(time(NULL));
	Vector2 pos;
	Vector2 wanderDir = m_dir;
	gameObject->getPosition(pos);
	if (m_target.pythag(pos) >= m_jitter * m_jitter) {
		wanderDir.x = rand() % 100;//should redo this with sin rotation cirlce thingo
		wanderDir.y = rand() % 100;
		wanderDir.normalise();
		
	}
		return wanderDir;

}
