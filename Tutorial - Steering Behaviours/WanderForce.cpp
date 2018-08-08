#include "WanderForce.h"



WanderForce::WanderForce()
{
	m_target = Vector2(515, 515);
	target_accuracy_rec = 3;
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
	if (pos.x >= m_target.x - target_accuracy_rec && pos.x <= m_target.x + target_accuracy_rec) {
		if (pos.x >= m_target.x - target_accuracy_rec && pos.x <= m_target.x + target_accuracy_rec) {
			wanderDir.x = (rand() % 100)- 50;//should redo this with sin rotation cirlce thingo
			wanderDir.y = (rand() % 100)- 50;
			wanderDir.normalise();
			m_target = pos - (wanderDir * m_radius);
		}
	}
	wanderDir = m_target - pos;
	wanderDir.normalise();
	return wanderDir;
	
}

void WanderForce::setPeram(float o, float r, float j)
{
	m_jitter = j;
	m_offset = o;
	m_radius = r;
}
