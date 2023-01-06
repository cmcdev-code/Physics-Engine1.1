#include "particleVectors.h"
#include "logic.h"
#define WINDOWSIZE 2560, 1440
#include <iostream>




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
void particleVectors::collisions() {
	for (int i = 0; i < particles.size(); i++)
	{
		for (int j = 0; j < particles.size(); j++) {
			if (i != j)
				if (Logic::getDistanceBetweenParticle(particles.at(i), particles.at(j)) <= (particles.at(i).getRadius() + particles.at(j).getRadius())/1300) {

					particles.at(i).setVelocity((particles.at(i).getMass() * particles.at(i).getXvelocity() + particles.at(j).getMass() * particles.at(j).getXvelocity()) / (particles.at(i).getMass() * particles.at(j).getMass()),
						(particles.at(i).getMass() * particles.at(i).getYvelocity() + particles.at(j).getMass() * particles.at(j).getYvelocity() )/ (particles.at(i).getMass() * particles.at(j).getMass()),

						(particles.at(i).getMass() * particles.at(i).getZvelocity() + particles.at(j).getMass() * particles.at(j).getZvelocity()) / (particles.at(i).getMass() * particles.at(j).getMass())
					);
					particles.at(j).setVelocity((particles.at(i).getMass() * particles.at(i).getXvelocity() + particles.at(j).getMass() * particles.at(j).getXvelocity()) / (particles.at(i).getMass() * particles.at(j).getMass()),
						(particles.at(i).getMass() * particles.at(i).getYvelocity() + particles.at(j).getMass() * particles.at(j).getYvelocity() )/ (particles.at(i).getMass() * particles.at(j).getMass()),

						(particles.at(i).getMass() * particles.at(i).getZvelocity() + particles.at(j).getMass() * particles.at(j).getZvelocity()) / (particles.at(i).getMass() * particles.at(j).getMass()));
				}


		}

	}
}
