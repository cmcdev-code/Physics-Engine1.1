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
void collision1(particle& p1, particle& p2) {
	// Calculate the velocities of the particles after the collision in the x-dimension
	float v1x = (p1.getMass() * p1.getXvelocity() * (p1.getMass() - p2.getMass()) + (1 + .98) * p2.getMass() * p2.getMass() * p2.getXvelocity()) / ((p1.getMass() + p2.getMass()) * p1.getMass());
	float v2x = (p2.getMass() * p2.getXvelocity() * (p2.getMass() - p1.getMass()) + (1 + .98) * p1.getMass() * p1.getMass() * p1.getXvelocity()) / ((p2.getMass() + p1.getMass()) * p2.getMass());

	// Calculate the velocities of the particles after the collision in the y-dimension
	float v1y = (p1.getMass() * p1.getYvelocity() * (p1.getMass() - p2.getMass()) + (1 + .98) * p2.getMass() * p2.getMass() * p2.getYvelocity()) / ((p1.getMass() + p2.getMass()) * p1.getMass());
	float v2y = (p2.getMass() * p2.getYvelocity() * (p2.getMass() - p1.getMass()) + (1 + .98) * p1.getMass() * p1.getMass() * p1.getYvelocity()) / ((p2.getMass() + p1.getMass()) * p2.getMass());

	// Calculate the velocities of the particles after the collision in the z-dimension
	float v1z = (p1.getMass() * p1.getZvelocity() * (p1.getMass() - p2.getMass()) + (1 + .98) * p2.getMass() * p2.getMass() * p2.getZvelocity()) / ((p1.getMass() + p2.getMass()) * p1.getMass());
	float v2z = (p2.getMass() * p2.getZvelocity() * (p2.getMass() - p1.getMass()) + (1 + .98) * p1.getMass() * p1.getMass() * p1.getZvelocity()) / ((p2.getMass() + p1.getMass()) * p2.getMass());
	p1.setVelocity(v1x, v1y, v1z);
	p2.setVelocity(v2x, v2y, v2z);
	Logic::updatePosition(p1);
	Logic::updatePosition(p2);
	Logic::updateVelocity(p1);
	Logic::updateVelocity(p2);
}

void particleVectors::updateGravityOnParticles()
	{
	
		for (int i = 0; i < particles.size(); i++)
		{
			for (int j = 0; j < particles.size(); j++) {
				if (i != j) {
					Logic::changeAccleration(particles.at(i), (Logic::getForceFromGravity_X(particles.at(i), particles.at(j)) / particles.at(i).getMass()) + particles.at(i).getXacceleration(),
						(Logic::getForceFromGravity_Y(particles.at(i), particles.at(j)) / particles.at(i).getMass()) + particles.at(i).getYacceleration(), 0);
				}

			}
		}
		//collisions();
		for (int i = 0; i < particles.size(); i++) {
			for (int j = 0; j < particles.size(); j++) {

				if (Logic::getDistanceBetweenParticle(particles.at(i), particles.at(j)) <= (particles.at(i).getRadius() + particles.at(j).getRadius()) / 1000) {
					
					particles.at(i).circle.setPosition(particles.at(i).transformPoint(particles.at(i).getXposition(), particles.at(i).getYposition(), WINDOWSIZE));
					collision1(particles.at(i), particles.at(j));
				
					Logic::changeAccleration(particles.at(i), 0, 0, 0);


				}
				else {
					particles.at(i).circle.setPosition(particles.at(i).transformPoint(particles.at(i).getXposition(), particles.at(i).getYposition(), WINDOWSIZE));

					
					Logic::updatePosition(particles.at(i));
					Logic::updateVelocity(particles.at(i));
					Logic::changeAccleration(particles.at(i), 0, 0, 0);
				//	std::cout << "Position x: " << particles.at(i).getXposition() << " y: " << particles.at(i).getYposition() << " z: " << particles.at(i).getZposition() << std::endl;
					//std::cout << "velocity x: " << particles.at(i).getXvelocity() << " y: " << particles.at(i).getYvelocity() << " z: " << particles.at(i).getZvelocity() << std::endl;
				}
			}
			////std::cout << "Acceleration  :" << particles.at(i).getXacceleration() << "  " << particles.at(i).getYacceleration() << "\n";
			////std::cout << "Velocity  :" << particles.at(i).getXvelocity() << "  " << particles.at(i).getYvelocity() <<"\n";
		}
		
		//particles.at(1).setVelocity(0, 0, 0);
	}

//void particleVectors::collisions() {
//	for (int i = 0; i < particles.size(); i++)
//	{
//		for (int j = 0; j < particles.size(); j++) {
//			if (i != j)
//				if (Logic::getDistanceBetweenParticle(particles.at(i), particles.at(j)) <= (particles.at(i).getRadius() + particles.at(j).getRadius())/1000) {
//
//					//particles.at(i).setVelocity((particles.at(i).getMass() * particles.at(i).getXvelocity() + particles.at(j).getMass() * particles.at(j).getXvelocity()) / (particles.at(i).getMass() * particles.at(j).getMass()),
//					//	(particles.at(i).getMass() * particles.at(i).getYvelocity() + particles.at(j).getMass() * particles.at(j).getYvelocity() )/ (particles.at(i).getMass() * particles.at(j).getMass()),
//
//					//	(particles.at(i).getMass() * particles.at(i).getZvelocity() + particles.at(j).getMass() * particles.at(j).getZvelocity()) / (particles.at(i).getMass() * particles.at(j).getMass())
//					//);
//					//particles.at(j).setVelocity((particles.at(i).getMass() * particles.at(i).getXvelocity() + particles.at(j).getMass() * particles.at(j).getXvelocity()) / (particles.at(i).getMass() * particles.at(j).getMass()),
//					//	(particles.at(i).getMass() * particles.at(i).getYvelocity() + particles.at(j).getMass() * particles.at(j).getYvelocity() )/ (particles.at(i).getMass() * particles.at(j).getMass()),
//		
//					//	(particles.at(i).getMass() * particles.at(i).getZvelocity() + particles.at(j).getMass() * particles.at(j).getZvelocity()) / (particles.at(i).getMass() * particles.at(j).getMass()));
//					collision1(particles.at(i), particles.at(j));
//					//particles.at(1).setVelocity(0, 0, 0);
//				//	particles.at(0).setVelocity(0, 0, 0);
//				}
//
//
//		}
//
//	}
//}
