#pragma once
#include "particle.h"
#include <SFML/Graphics.hpp>
#include <vector>

class particleVectors
{

public:
	void drawAllParticles(sf::RenderWindow& window);
	
	void updateGravityOnParticles(const int & numberOfThreads);


	std::vector<particle> particles;
	

	


};

