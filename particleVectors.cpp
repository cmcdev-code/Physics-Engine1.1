#include "particleVectors.h"
#include "logic.h"
#define WINDOWSIZE 2560, 1440
#include <iostream>
#include "particle.h"
#include <thread>



void particleVectors::drawAllParticles(sf::RenderWindow& window)
{
	for (int i = 0; i < particles.size(); i++) {
        particles.at(i).circle.setRadius(particles.at(i).getRadius() * (particles.at(i).getZposition() >= 0 ? particles.at(i).getZposition() + 1 : 1 / (particles.at(i).getZposition() - 1)));
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
	Logic::updateVelocity(p1);
	Logic::updateVelocity(p2);
	Logic::updatePosition(p1);
	Logic::updatePosition(p2);

}


void particleVectors::updateGravityOnParticles(const int& numberOfThreads)
{
    int totalWork = particles.size() * particles.size();
    int workPerThread = totalWork / numberOfThreads;
    int start = 0;
    int end = workPerThread;
    std::vector<std::thread> threads;
    for (int i = 0; i < numberOfThreads; i++) {
        threads.push_back(std::thread([&](int start, int end) {
            for (int i = start; i < end; i++) {
                int x = i / particles.size();
                int y = i % particles.size();
                if (x != y) {
                    Logic::changeAccleration(particles.at(x), (Logic::getForceFromGravity_X(particles.at(x), particles.at(y)) / particles.at(x).getMass()) + particles.at(x).getXacceleration(),
                        (Logic::getForceFromGravity_Y(particles.at(x), particles.at(y)) / particles.at(x).getMass()) + particles.at(x).getYacceleration(), 
                        (Logic::getForceFromGravity_Z(particles.at(x), particles.at(y)) / particles.at(x).getMass()) + particles.at(x).getZacceleartion());
                }
                if (Logic::getDistanceBetweenParticle(particles.at(x), particles.at(y)) <= (particles.at(x).getRadius() + particles.at(y).getRadius()) / 1000) {
                    particles.at(x).circle.setPosition(particles.at(x).transformPoint(particles.at(x).getXposition(), particles.at(x).getYposition(), WINDOWSIZE));
                    collision1(particles.at(x), particles.at(y));

                    Logic::changeAccleration(particles.at(x), 0, 0, 0);
                }
                else {
                    particles.at(x).circle.setPosition(particles.at(x).transformPoint(particles.at(x).getXposition(), particles.at(x).getYposition(), WINDOWSIZE));
                    Logic::updateVelocity(particles.at(x));
                    Logic::updatePosition(particles.at(x));
                    Logic::changeAccleration(particles.at(x), 0, 0, 0);
                }
            }
            }, start, end));
        start = end;
        end += workPerThread;
    }
    for (int i = 0; i < numberOfThreads; i++) {
        threads.at(i).join();
    }
}