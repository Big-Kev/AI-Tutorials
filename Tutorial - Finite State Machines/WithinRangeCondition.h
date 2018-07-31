#pragma once
#include "Condition.h"
#include "vector2.h"
#include "GameObject.h"//>>>????/
class WithinRangeCondition :
	public Condition
{
public:
	WithinRangeCondition(const  GameObject* target, float range) : m_target(target), m_range(range) {}

	virtual ~WithinRangeCondition() {}

	virtual bool test(GameObject* gameObject) const {
		Vector2  t_pos;
		m_target->getPosition(t_pos);

		Vector2 m_pos;
		gameObject->getPosition(m_pos);

		float xDiff = t_pos.x - m_pos.x;
		float yDiff = t_pos.y - m_pos.y;

		float distance = sqrtf(xDiff * xDiff + yDiff * yDiff);
		return distance <= m_range;
	}


private:

	const  GameObject* m_target;
	float m_range;
};

