//
//  Contact.cpp
//
#include "Contact.h"

/*
====================================================
ResolveContact
====================================================
*/
void ResolveContact( contact_t & contact ) {
	Body* bodyA = contact.bodyA;
	Body* bodyB = contact.bodyB;
	
	const float invMassA = bodyA->m_invMass;
	const float invMassB = bodyB->m_invMass;
	
	//collision impulse
	const Vec3& normal = contact.normal;
	const Vec3 vab = bodyA->m_linearVelocity - bodyB->m_linearVelocity;
	const float impulseJ = -2.0f * vab.Dot(normal) / (invMassA + invMassB);
	const Vec3 vectorImpulseJ = normal * impulseJ;
	
	bodyA->ApplyImpulseLinear(vectorImpulseJ * 1.0f);
	bodyB->ApplyImpulseLinear(vectorImpulseJ * -1.0f);
	
	//move colliding objects out of each other
	const float tA = invMassA / (invMassA + invMassB);
	const float tB = invMassB / (invMassA + invMassB);
	
	const Vec3 ds = contact.ptOnB_WorldSpace - contact.ptOnA_WorldSpace;
	bodyA->m_position += ds * tA;
	bodyB->m_position -= ds * tB;
}