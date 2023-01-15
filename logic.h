#pragma once
#include "particle.h"

class Logic {

public:
	//will return the distance between two particles as a double
	static double getDistanceBetweenParticle(particle& P1, particle& P2);
	
	//will calculate the force from gravity between two particles
	static double getForceFromGravity(particle& P1, particle& P2);
	
	//will calculate the force of gravity between two particles just for x 
	static double getForceFromGravity_X(particle& P1, particle& P2);
	//will calculate the force of gravity between two particles just for y 
	static double getForceFromGravity_Y(particle& P1, particle& P2);
	//will calculate the force of gravity between two particles just for z
	static double getForceFromGravity_Z(particle& P1, particle& P2);

	static void changePosition(particle& P1, const double& X, const  double& Y, const double& Z);
	static void changeVelocity(particle& P1, const double& X, const  double& Y, const double& Z);
	static void changeAccleration(particle& P1, const double& X, const  double& Y, const double& Z);
	
	//will update the position of the particle by adding the current velocity to it
	static void updatePosition(particle& P1);
	//will update the velocity of a particle by adding the current acceleartion of the particlle to the velocity
	static void updateVelocity(particle& P1);
	static sf::Color getGradientColor(const particle& P1);
};