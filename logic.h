#pragma once
#include "particle.h"



class Logic {

public:
	static double getDistanceBetweenParticle(particle& P1, particle& P2);
	
	static double getForceFromGravity(particle& P1, particle& P2);
	
	static double getForceFromGravity_X(particle& P1, particle& P2);
	static double getForceFromGravity_Y(particle& P1, particle& P2);
	static double getForceFromGravity_Z(particle& P1, particle& P2);

	static void changePosition(particle& P1,double X,double Y,double Z);
	static void changeVelocity(particle& P1,double X,double Y, double Z);
	static void changeAccleration(particle& P1,double X,double Y,double Z);
	
	static void updatePosition(particle& P1);
	static void updateVelocity(particle& P1);
	
	static void updateAccelerationDueToGravity(particle& P1, particle& P2);
	

	








};