#include "logic.h"
#include <cmath>;

//#define gravity 0.000000000066743
//#define gravity -0.000000000066743
#define gravity  0.0000066743
//#define gravity -0.000066743

#define time .1

void getLastPosition(particle &p1,long double& x, long double& y,long double& z) {
	x = p1.getXposition() - p1.getXvelocity();
	y = p1.getYposition() - p1.getYvelocity();
	z = p1.getZposition() - p1.getZvelocity();
}

long double getMagnitudeOfVelocity(particle	&p1) {
	return pow(p1.getXvelocity() * p1.getXvelocity() + p1.getYvelocity() * p1.getYvelocity() + p1.getZvelocity() * p1.getZvelocity(), .5);
}


double Logic::getDistanceBetweenParticle(particle& P1, particle& P2) 
{
	double distance =std::pow(
		(P1.getXposition() - P2.getXposition()) * (P1.getXposition() - P2.getXposition())
		+ (P1.getYposition() - P2.getYposition()) * (P1.getYposition() - P2.getYposition())
		+ ((P1.getZposition() - P2.getZposition()) * (P1.getZposition() - P2.getZposition())), 0.5);
	
	if (isnan(distance)) {
		return 0.0001;
	}
	return distance;
}

double Logic::getForceFromGravity(particle& P1, particle& P2) 
{
	return -gravity * P1.getMass() * P2.getMass() / getDistanceBetweenParticle(P1, P2);
}

double Logic::getForceFromGravity_X(particle& P1, particle& P2) 
{
	//calculating unit vector just for the x 
	double MagnitudeOFVector = (getDistanceBetweenParticle(P1, P2));
	if (MagnitudeOFVector <= ((P1.getRadius() + P2.getRadius()) / 1000) ){
		return 0;
	}
	return    (getForceFromGravity(P1, P2) * (P1.getXposition() - P2.getXposition())) / (MagnitudeOFVector * MagnitudeOFVector);
}
double Logic::getForceFromGravity_Y(particle& P1, particle& P2) 
{
	double MagnitudeOFVector = (getDistanceBetweenParticle(P1, P2));
	if (MagnitudeOFVector <= ((P1.getRadius() + P2.getRadius()) / 1000)) {
		return 0;
	}
	return (getForceFromGravity(P1, P2) * (P1.getYposition() - P2.getYposition())) / (MagnitudeOFVector * MagnitudeOFVector);
}
double Logic::getForceFromGravity_Z(particle& P1, particle& P2) 
{
	double MagnitudeOFVector = (getDistanceBetweenParticle(P1, P2));
	if (MagnitudeOFVector <= ((P1.getRadius() + P2.getRadius()) / 1000)) {
		return 0;
	}
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
	double x, y, z;
	P1.getPosition(x, y, z);


	P1.setPosition
		(
		P1.getXposition() + P1.getXvelocity()* time,
		P1.getYposition() + P1.getYvelocity() * time,
		P1.getZposition() + P1.getZvelocity() * time
		);
}
void Logic::updateVelocity(particle& P1)
{
	double x, y, z;
	P1.getPosition(x, y, z);

	if (x + P1.getXvelocity() <= -28) {
		long double angle = asin(((P1.getXvelocity()) / getMagnitudeOfVelocity(P1)));


		double cosineOfAngle = cos(angle);
		double sineOfAngel = sin(angle);

		P1.setVelocity
		(
			P1.getXvelocity() * sineOfAngel + P1.getXacceleration() * time
			,
			P1.getYvelocity() * cosineOfAngle + P1.getYacceleration() * time,
			P1.getZvelocity() + P1.getZvelocity() * time

		);
	}
		if (x + P1.getXvelocity() >= 28) {
			long double angle = asin(((P1.getXvelocity()) / getMagnitudeOfVelocity(P1)));


			double cosineOfAngle = -cos(angle);
			double sineOfAngel = sin(angle);

			P1.setVelocity
			(
				P1.getXvelocity() *-sineOfAngel + P1.getXacceleration() * time
				,
				P1.getYvelocity() * cosineOfAngle + P1.getYacceleration() * time,
				P1.getZvelocity() + P1.getZvelocity() * time

			);
	}
	if (y + P1.getYvelocity() >= 28 or y + P1.getYvelocity() <= -28) {
		long double angle = acos(((P1.getXvelocity()) / getMagnitudeOfVelocity(P1)));


		double cosineOfAngle = cos(angle);
		double sineOfAngel = sin(angle);

		P1.setVelocity
		(
			P1.getXvelocity() * sineOfAngel + P1.getXacceleration() * time
			,
			P1.getYvelocity() * cosineOfAngle + P1.getYacceleration() * time,
			P1.getZvelocity() + P1.getZvelocity() * time

		);
	}
	else
	 {
		P1.setVelocity
		(
			P1.getXvelocity() + P1.getXacceleration() * time,
			P1.getYvelocity() + P1.getYacceleration() * time,
			P1.getZvelocity() + P1.getZacceleartion() * time

		);

	
	}
}
