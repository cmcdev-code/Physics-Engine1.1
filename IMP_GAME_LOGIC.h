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


class IMP_GAME_LOGIC
{

	public:
		void pullKeyBoardEvents(sf::RenderWindow & window,sf::View& view);

		void createNewParticleDynamically(sf::RenderWindow & window,  sf::View& view);

		void drawAll(sf::RenderWindow& window);

		void updateGravity();

		int returnSize() const;
		private:
		particleVectors Particles;









};

