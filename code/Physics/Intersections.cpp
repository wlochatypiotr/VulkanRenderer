//
//  Intersections.cpp
//
#include "Intersections.h"
#include "GJK.h"

/*
====================================================
Intersect
====================================================
*/
bool Intersect( Body * bodyA, Body * bodyB, contact_t & contact ) {
	// TODO: Add Code
	if (!bodyA || !bodyB)
	{
		return false;
	}
	
	contact.bodyA = bodyA;
	contact.bodyB = bodyB;
	
	const Vec3 ab =bodyB->m_position - bodyA->m_position;
	contact.normal = ab;
	contact.normal.Normalize();
	
	const ShapeSphere* sphereA = dynamic_cast<ShapeSphere*> (bodyA->m_shape);
	const ShapeSphere* sphereB = dynamic_cast<ShapeSphere*> (bodyB->m_shape);
	if (!sphereA || !sphereB)
	{
		return false;
	}
	contact.ptOnA_WorldSpace = bodyA->m_position + contact.normal * sphereA->m_radius;
	contact.ptOnB_WorldSpace = bodyB->m_position - contact.normal * sphereB->m_radius;
	
	const float radiusAB = sphereA->m_radius + sphereB->m_radius;
	const float distSquared = ab.GetLengthSqr();
	if (distSquared <=  (radiusAB * radiusAB))
	{
		return true;
	}
	
	return false;
}

/*
====================================================
Intersect
====================================================
*/
bool Intersect( Body * bodyA, Body * bodyB, const float dt, contact_t & contact ) {
	// TODO: Add Code

	return false;
}

// bool Intersect(Body* bodyA, Body* bodyB)
// {
// 	if (!bodyA || !bodyB)
// 	{
// 		return false;
// 	}
// 	
// 	const Vec3 ab =bodyA->m_position - bodyB->m_position;
// 	
// 	const ShapeSphere* sphereA = dynamic_cast<ShapeSphere*> (bodyA->m_shape);
// 	const ShapeSphere* sphereB = dynamic_cast<ShapeSphere*> (bodyB->m_shape);
// 	if (!sphereA || !sphereB)
// 	{
// 		return false;
// 	}
// 	
// 	const float radiusAB = sphereA->m_radius + sphereB->m_radius;
// 	const float distSquared = ab.GetLengthSqr();
// 	if (distSquared <=  (radiusAB * radiusAB))
// 	{
// 		return true;
// 	}
// 	
// 	return false;
// }
//
//
//



















