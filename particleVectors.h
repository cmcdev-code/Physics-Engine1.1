#pragma once
#include "particle.h"
#include <SFML/Graphics.hpp>
#include <vector>

class particleVectors
{

public:
	
	
	void updateGravityOnParticles(const int & numberOfThreads);

	void drawAllParticles(sf::RenderWindow& window);

	std::vector<particle> particles;

};

