#include "logic.h"
#include <cmath>;
#include <iostream>//debug

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
	return -gravity * P1.getMass() * P2.getMass() / getDistanceBetweenParticle(P1, P2);
}

double Logic::getForceFromGravity_X(particle& P1, particle& P2) 
{
	//calculating unit vector just for the x 
	double MagnitudeOFVector = getDistanceBetweenParticle(P1, P2);
	return (getForceFromGravity(P1, P2) * (P1.getXposition() - P2.getXposition())) /(MagnitudeOFVector * MagnitudeOFVector);
}
double Logic::getForceFromGravity_Y(particle& P1, particle& P2) 
{
	double MagnitudeOFVector = getDistanceBetweenParticle(P1, P2);

	return (getForceFromGravity(P1, P2) * (P1.getYposition() - P2.getYposition())) / (MagnitudeOFVector * MagnitudeOFVector);
}
double Logic::getForceFromGravity_Z(particle& P1, particle& P2) 
{
	double MagnitudeOFVector = getDistanceBetweenParticle(P1, P2);

	return (getForceFromGravity(P1, P2) * (P1.getZposition() - P2.getZposition())) / (MagnitudeOFVector * MagnitudeOFVector);
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

	P1.setAcceleration( X,  Y,  Z);
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
void Logic::updateAccelerationDueToGravity(particle& P1, particle& P2) 
{

	particle p0 = P1;

	P1.setAcceleration
	(
		 Logic::getForceFromGravity_X(P1, P2) / P1.getMass(),
		Logic::getForceFromGravity_Y(P1, P2) / P1.getMass(),
		 Logic::getForceFromGravity_Z(P1, P2) / P1.getMass()
	);
	P2.setAcceleration
	(
		Logic::getForceFromGravity_X(P2, p0) / P2.getMass(),
	 Logic::getForceFromGravity_Y(P2, p0) / P2.getMass(),
		 Logic::getForceFromGravity_Z(P2, p0) / P2.getMass()
	);


}