#pragma once
#include "Vector2.h"
#include <vector>
//#include "Behaviour.h"
//#include "Behaviour.h"
class Behaviour;
class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

	//movement functions
	void setPosition(Vector2 m_vec) { m_pos.x = m_vec.x; m_pos.y = m_vec.y;}
	void getPosition(Vector2& m_vec) const { m_vec = m_pos; }
	void getPosition(float& a, float& b ) const { a = m_pos.x; b = m_pos.x;}
	void translate(Vector2 m_vec) { m_pos.x += m_vec.x; m_pos.y += m_vec.y;}
	void translate(float ox, float oy) { m_pos.x += ox; m_pos.y += oy; }

	//physics functions
	void getVelocity(float& a, float& b) const { a = m_velocity.x; b = m_velocity.x; }
	void getVelocity(Vector2& m_vec) const { m_vec = m_velocity; }
	void setVelocity(Vector2 m_vec) { m_velocity.x = m_vec.x; m_velocity.y = m_vec.y; }
	void getAcceleration(float& a, float& b) const { a = m_acceleration.x; b = m_acceleration.x; }
	void getMass(float& m) const { m = m_mass; }
	void getSpeed(float& s) const { s = m_speed; }
	void setSpeed(float s){ m_speed = s; }

	//update physics
	void addForce(Vector2 dir, float f, float deltaTime);
	void addForce(Vector2 dir);
	void decelerate(float d);

	//add behavoiur
	void addBehaviour(Behaviour* behaviour);

	//update game object and execute behaviours
	virtual void update(float deltaTime);
	
protected:

	Vector2 m_pos;
	Vector2 m_velocity;
	Vector2 m_acceleration;
	float m_force;
	float m_mass;
	float m_speed;

	std::vector<Behaviour*> m_behaviours;
};

