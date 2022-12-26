#include "logic.h"
#include <cmath>;

#define gravity 0.000000000066743

double Logic::getDistanceBetweenParticle(particle& P1, particle& P2) 
{
	return std::pow(
		(P1.getXposition() - P2.getXposition()) * (P1.getXposition() - P2.getXposition())
		+ (P1.getYposition() - P2.getYposition()) * (P1.getYposition() - P2.getYposition())
		+ ((P1.getZposition() - P2.getZposition()) * (P1.getZposition() - P2.getZposition())), 0.5);
}

double Logic::getForceFromGravity(particle& P1, particle& P2) 
{
	return gravity * P1.getMass() * P2.getMass() / getDistanceBetweenParticle(P1, P2);
}

void Logic::changePosition(particle& P1, double X, double Y, double Z) 
{
	P1.setPosition(P1.getXposition() + X, P1.getYposition() + Y, P1.getZposition() + Z);
}
void Logic::changeVelocity(particle& P1, double X, double Y, double Z) 
{
	P1.setVelocity(P1.getXvelocity() + X, P1.getYvelocity() + Y, P1.getZvelocity() + Z);
}
void Logic::changeAccleration(particle& P1, double X, double Y, double Z) {

	P1.setAcceleration(P1.getXacceleration() + X, P1.getYacceleration() + Y, P1.getZacceleartion() + Z);
}
void Logic::updatePosition(particle& P1) 
{
	P1.setPosition
		(
		P1.getXposition() + P1.getXvelocity(),
		P1.getYposition() + P1.getYvelocity(),
		P1.getZposition() + P1.getZvelocity()
		);
}
void Logic::updateVelocity(particle& P1)
{
	P1.setVelocity
	(
		P1.getXvelocity() + P1.getXacceleration(),
		P1.getYvelocity() + P1.getYacceleration(),
		P1.getZvelocity() + P1.getZacceleartion()
	);
}
