#pragma once
#include "particle.h"
#include <SFML/Graphics.hpp>
#include <vector>

class particleVectors
{

public:






	void drawAllParticles(sf::RenderWindow& window);
	
	void updateGravityOnParticles();


	std::vector<particle> particles;
	
	void collisions();



};
