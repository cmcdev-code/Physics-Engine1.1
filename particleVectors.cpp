#include "particleVectors.h"
#include "logic.h"
#define WINDOWSIZE 2560, 1440
#include <iostream>
#include "particle.h"




void particleVectors::drawAllParticles(sf::RenderWindow& window)
{
	for (int i = 0; i < particles.size(); i++) {
		window.draw(particles.at(i).circle);
	}
	window.display();
}


void particleVectors::updateGravityOnParticles()
	{
	collisions();
		for (int i = 0; i < particles.size(); i++)
		{
			for (int j = 0; j < particles.size(); j++) {
				if (i != j) {
					Logic::changeAccleration(particles.at(i), (Logic::getForceFromGravity_X(particles.at(i), particles.at(j)) / particles.at(i).getMass()) + particles.at(i).getXacceleration(),
						(Logic::getForceFromGravity_Y(particles.at(i), particles.at(j)) / particles.at(i).getMass()) + particles.at(i).getYacceleration(), 0);
				}

			}
		}

		for (int i = 0; i < particles.size(); i++) {
			particles.at(i).circle.setPosition(particles.at(i).transformPoint(particles.at(i).getXposition(), particles.at(i).getYposition(), WINDOWSIZE));
			Logic::updatePosition(particles.at(i));
			Logic::updateVelocity(particles.at(i));
			//std::cout << "Acceleration  :" << particles.at(i).getXacceleration() << "  " << particles.at(i).getYacceleration() << "\n";
			//std::cout << "Velocity  :" << particles.at(i).getXvelocity() << "  " << particles.at(i).getYvelocity() <<"\n";
		}

	
	}
void collision1(particle& p1, particle& p2) {
	// Calculate the velocities of the particles after the collision in the x-dimension
	float v1x = (p1.getMass() * p1.getXvelocity() + p2.getMass() * p2.getXvelocity() - p1.getMass() * (p1.getXvelocity() - p2.getXvelocity())) / (p1.getMass() + p2.getMass());
	float v2x = (p1.getMass() * p1.getXvelocity() + p2.getMass() * p2.getXvelocity() - p2.getMass() * (p1.getXvelocity() - p2.getXvelocity())) / (p1.getMass() + p2.getMass());

	// Calculate the velocities of the particles after the collision in the y-dimension
	float v1y = (p1.getMass() * p1.getYvelocity() + p2.getMass() * p2.getYvelocity() - p1.getMass() * (p1.getYvelocity() - p2.getYvelocity())) / (p1.getMass() + p2.getMass());
	float v2y = (p1.getMass() * p1.getYvelocity() + p2.getMass() * p2.getYvelocity() - p2.getMass() * (p1.getYvelocity() - p2.getYvelocity())) / (p1.getMass() + p2.getMass());

	// Calculate the velocities of the particles after the collision in the z-dimension
	float v1z = (p1.getMass() * p1.getZvelocity() + p2.getMass() * p2.getZvelocity() - p1.getMass() * (p1.getZvelocity() - p2.getZvelocity())) / (p1.getMass() + p2.getMass());
	float v2z = (p1.getMass() * p1.getZvelocity() + p2.getMass() * p2.getZvelocity() - p1.getMass() * (p1.getZvelocity() - p2.getZvelocity())) / (p1.getMass() + p2.getMass());
	p1.setVelocity(v1x, v1y, v1z);
	p2.setVelocity(v2x, v2y, v2z);
}
void particleVectors::collisions() {
	for (int i = 0; i < particles.size(); i++)
	{
		for (int j = 0; j < particles.size(); j++) {
			if (i != j)
				if (Logic::getDistanceBetweenParticle(particles.at(i), particles.at(j)) <= (particles.at(i).getRadius() + particles.at(j).getRadius())/1000) {

					//particles.at(i).setVelocity((particles.at(i).getMass() * particles.at(i).getXvelocity() + particles.at(j).getMass() * particles.at(j).getXvelocity()) / (particles.at(i).getMass() * particles.at(j).getMass()),
					//	(particles.at(i).getMass() * particles.at(i).getYvelocity() + particles.at(j).getMass() * particles.at(j).getYvelocity() )/ (particles.at(i).getMass() * particles.at(j).getMass()),

					//	(particles.at(i).getMass() * particles.at(i).getZvelocity() + particles.at(j).getMass() * particles.at(j).getZvelocity()) / (particles.at(i).getMass() * particles.at(j).getMass())
					//);
					//particles.at(j).setVelocity((particles.at(i).getMass() * particles.at(i).getXvelocity() + particles.at(j).getMass() * particles.at(j).getXvelocity()) / (particles.at(i).getMass() * particles.at(j).getMass()),
					//	(particles.at(i).getMass() * particles.at(i).getYvelocity() + particles.at(j).getMass() * particles.at(j).getYvelocity() )/ (particles.at(i).getMass() * particles.at(j).getMass()),
		
					//	(particles.at(i).getMass() * particles.at(i).getZvelocity() + particles.at(j).getMass() * particles.at(j).getZvelocity()) / (particles.at(i).getMass() * particles.at(j).getMass()));
					collision1(particles.at(i), particles.at(j));
				}


		}

	}
}
