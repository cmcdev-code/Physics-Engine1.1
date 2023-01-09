#include "logic.h"
#include <cmath>;
#include <iostream>//debug
//
//#define gravity 0.000000000066743
//#define gravity -0.000000000066743
//#define gravity 0.0000066743
#define gravity -0.0000066743
#define time 1

double debug(double a) {
	//std::cout << a << std::endl;
	return a;
}


void getLastPosition(particle & p1,double& x, double& y, double& z) {
	x = p1.getXposition() - p1.getXvelocity();
	y = p1.getYposition() - p1.getYvelocity();
	z = p1.getZposition() - p1.getZvelocity();
}
double distanceFromLast(particle& p1, double x, double y, double z) {
	double xd, yd, zd;
	p1.getPosition(xd, yd, zd);
	double xSquared = (p1.getXposition() - x) * (p1.getXposition() - x);
	double ySquared = (p1.getYposition() - y) * (p1.getYposition() - y);
	double zSquared = (p1.getZposition() - z) * (p1.getZposition() - z);
	double a= pow(xSquared +ySquared + zSquared, .5);
//	std::cout << "DISTANCE a: " << a << std::endl;
	return a;
}


//long double	Logic::time=1;
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
	double MagnitudeOFVector = debug(getDistanceBetweenParticle(P1, P2));
	if (MagnitudeOFVector <= ((P1.getRadius() + P2.getRadius()) / 1000) ){
		return 0;
	}
	return debug(getForceFromGravity(P1, P2) * (P1.getXposition() - P2.getXposition())) /(MagnitudeOFVector * MagnitudeOFVector);
}
double Logic::getForceFromGravity_Y(particle& P1, particle& P2) 
{
	double MagnitudeOFVector = debug(getDistanceBetweenParticle(P1, P2));
	if (MagnitudeOFVector <= ((P1.getRadius() + P2.getRadius()) / 1000)) {
		return 0;
	}
	return debug(getForceFromGravity(P1, P2) * (P1.getYposition() - P2.getYposition())) / (MagnitudeOFVector * MagnitudeOFVector);
}
double Logic::getForceFromGravity_Z(particle& P1, particle& P2) 
{
	double MagnitudeOFVector = debug(getDistanceBetweenParticle(P1, P2));
	if (MagnitudeOFVector <= ((P1.getRadius() + P2.getRadius()) / 1000)) {
		return 0;
	}
	return debug(getForceFromGravity(P1, P2) * (P1.getZposition() - P2.getZposition())) / (MagnitudeOFVector * MagnitudeOFVector);
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
		P1.getXposition() + P1.getXvelocity()* time,
		P1.getYposition() + P1.getYvelocity() * time,
		P1.getZposition() + P1.getZvelocity() * time
		);
}
void Logic::updateVelocity(particle& P1)
{
	double x, y, z;
	P1.getPosition(x, y, z);
	if (x <= -40 or x >= 40 or y <= -28 or y >=28) {
		double angle, xl, yl, zl;
		getLastPosition(P1, xl, yl, zl);
		 
		angle = asin((x <= -40 or x >= 40) ? ((xl - x) / distanceFromLast(P1, xl, yl, zl)) : ((yl - y) / distanceFromLast(P1, xl, yl, zl)));

		
		P1.setVelocity
		(



			0.1*cos(angle) + P1.getXacceleration() * time,
			0.1*sin(angle) + P1.getYacceleration() * time, 
			P1.getZvelocity() + P1.getZvelocity() * time
				
		);
	}else
	 {
		P1.setVelocity
		(
			P1.getXvelocity() + P1.getXacceleration() * time,
			P1.getYvelocity() + P1.getYacceleration() * time,
			P1.getZvelocity() + P1.getZacceleartion() * time

		);

	
	}
}
void Logic::updateAccelerationDueToGravity(particle& P1, particle& P2) 
{

	particle p0 = P1;

	P1.setAcceleration
	(
		 Logic::getForceFromGravity_X(P1, P2) / (P1.getMass()/time),
		Logic::getForceFromGravity_Y(P1, P2) / (P1.getMass()/time),
		 Logic::getForceFromGravity_Z(P1, P2) / (P1.getMass()/time)
	);
	P2.setAcceleration
	(
		Logic::getForceFromGravity_X(P2, p0) / (P2.getMass()/time),
	 Logic::getForceFromGravity_Y(P2, p0) / (P2.getMass()/time),
		 Logic::getForceFromGravity_Z(P2, p0) / (P2.getMass()*time)
	);


}