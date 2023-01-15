#pragma once
#include "logic.h"
#include <iostream>
#include "Sphere.h"
#include <cmath>
#include <SFML/Graphics.hpp>
#include <string>
#include "particleVectors.h"
#include <chrono>
#include <thread>
#include <random>
#include <vector>


class Scene
{

	public:
		void pullKeyBoardEvents(sf::RenderWindow & window,sf::View& view);

		void createNewParticleDynamically(sf::RenderWindow & window,  sf::View& view);

		void drawAll(sf::RenderWindow& window);

		void updateGravity();

		int returnSize() const;

		void setMassOfParticlesInArray();

		void setArrayOfVectorParticlePointers();

		void updateGravityOnParticles();

		double massOfparticlesInArray[56][56];
		std::vector<particle*> BoxesOfParticles[56][56];

		//private:
		particleVectors Particles;
		








};

