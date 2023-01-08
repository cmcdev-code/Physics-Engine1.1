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
		void pullKeyBoardEvents(sf::RenderWindow & window ,particleVectors& particles);

		void createNewParticleDynamically();














};

