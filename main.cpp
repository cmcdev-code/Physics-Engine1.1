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

void mouseToCartesian(float mouseX, float mouseY, float& x, float& y, sf::RenderWindow& window, sf::View& view) {
    // Get the position and size of the window
    sf::Vector2u windowSize = window.getSize();

    // Convert the mouse coordinates to window coordinates
    x = (20.0f * mouseX / windowSize.x) - 10.0f;
    y = -((14.0f * mouseY / windowSize.y) - 7.0f);
}
int main()
{
    
    particleVectors Particles;

    particle p1(-9, -7, 0, 0, 0.00, 0.000, 0, 0, 0, 100000.0, 0, 300);
    particle p2(-9, -7, 0, 0, 0.00, 0.000, 0, 0, 0, 100000.0, 0, 300);

  
    Particles.particles.push_back(p1);
    Particles.particles.push_back(p2);

    sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(2560 * 10, 1440 * 10));
    view.setCenter(sf::Vector2f(1280.0f, 720.0f));
    sf::Font font;
    if (!font.loadFromFile("LiberationSans.ttf"))
    {
        std::cerr << "Error loading font" << std::endl;
        return 1;
    }
    

    int a = 0;

    //sf::Text text;
    //text.setFont(font);
    //text.setCharacterSize(24);
    //text.setFillColor(sf::Color::White);
    ////text.setPosition(10, 10);

    sf::RenderWindow window(sf::VideoMode(2560, 1440), "Stuff");
  
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }  

        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            Particles.particles.at(1).setXposition(Particles.particles.at(1).getXposition() - 0.01);
          //  Particles.particles.at(1).setMass(Particles.particles.at(1).getMass() + 5000);
           ////std::cout << "Mass is " << Particles.particles.at(1).getMass() << '\n';
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
        {
            Particles.particles.at(0).setXposition(Particles.particles.at(0).getXposition() - 0.01);
            //  Particles.particles.at(1).setMass(Particles.particles.at(1).getMass() + 5000);
             ////std::cout << "Mass is " << Particles.particles.at(1).getMass() << '\n';
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            Particles.particles.at(1).setXposition(Particles.particles.at(1).getXposition() + 0.01);
           // Particles.particles.at(1).setMass(Particles.particles.at(1).getMass() - 5000);
            ////std::cout << "Mass is " << Particles.particles.at(1).getMass() << "\n";
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
        {
            Particles.particles.at(0).setXposition(Particles.particles.at(0).getXposition() + 0.01);
            // Particles.particles.at(1).setMass(Particles.particles.at(1).getMass() - 5000);
             ////std::cout << "Mass is " << Particles.particles.at(1).getMass() << "\n";
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            Particles.particles.at(1).setYposition(Particles.particles.at(1).getYposition() + 0.01);
            //Particles.particles.at(1).setMass(Particles.particles.at(1).getMass() - 5000);
             ////std::cout << "Mass is " << Particles.particles.at(1).getMass() << "\n";
           
        } if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
        {
            Particles.particles.at(0).setYposition(Particles.particles.at(0).getYposition() + 0.01);
            //Particles.particles.at(1).setMass(Particles.particles.at(1).getMass() - 5000);
             ////std::cout << "Mass is " << Particles.particles.at(1).getMass() << "\n";

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            Particles.particles.at(1).setYposition(Particles.particles.at(1).getYposition() - 0.01);
            //Particles.particles.at(1).setMass(Particles.particles.at(1).getMass() - 5000);
             ////std::cout << "Mass is " << Particles.particles.at(1).getMass() << "\n";
       }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
        {
            Particles.particles.at(0).setYposition(Particles.particles.at(0).getYposition() - 0.01);
            //Particles.particles.at(1).setMass(Particles.particles.at(1).getMass() - 5000);
             ////std::cout << "Mass is " << Particles.particles.at(1).getMass() << "\n";
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
           // Particles.particles.at(1).setMass(Particles.particles.at(1).getMass() + 50);
            Particles.particles.at(1).circle.setRadius(Particles.particles.at(1).circle.getRadius() + 0.2);
            Particles.particles.at(1).setMass(Particles.particles.at(1).getMass()*1.1);
            //std::cout << "Mass is " << Particles.particles.at(1).getMass() << '\n';
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        {
            Particles.particles.at(1).setMass(Particles.particles.at(1).getMass() /1.1);
            Particles.particles.at(1).circle.setRadius(Particles.particles.at(1).circle.getRadius() - 0.2);
            //Particles.particles.at(1).setMass(Particles.particles.at(1).getMass() + 5000);
            //std::cout << "Mass is " << Particles.particles.at(1).getMass() << '\n';
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
        {
            Particles.particles.at(1).setVelocity(0, 0, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
        {
            for (int i = 0; i < Particles.particles.size(); i++) {
                Particles.particles.at(i).setPosition(0, 0, 0);
          }
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i XY = sf::Mouse::getPosition();
            float x, y;
            //std::cout << XY.x << "  " << XY.y << '\n';
            mouseToCartesian(XY.x, XY.y, x, y,window,view);

            auto time = std::chrono::high_resolution_clock::now();
            std::mt19937 rng1(time.time_since_epoch().count());
            std::uniform_int_distribution<int> dist1(10, 200000000000000);
            int randomNumber1 = dist1(rng1);
            std::mt19937 rng2(time.time_since_epoch().count());
            std::uniform_int_distribution<int> dist2(30, 200);
            int randomNumber2 = dist2(rng2);


            particle *p = new particle(x,y,0,0,0,0,0,0,0,randomNumber1,0,randomNumber2);
            Particles.particles.push_back(*p);
            for (int i = 0; i < Particles.particles.size(); i++)
            {
            

                // Seed the random number generator with the time
                std::mt19937 rng(time.time_since_epoch().count());

                // Generate a random number
                std::uniform_int_distribution<int> dist(1, 10);
                int randomNumber = dist(rng);

                if (Logic::getDistanceBetweenParticle(Particles.particles.at(Particles.particles.size() - 1), Particles.particles.at(i)) <=
                    (Particles.particles.at(Particles.particles.size() - 1).getRadius() + Particles.particles.at(i).getRadius()) / 100) {
                    Particles.particles.at(Particles.particles.size() - 1).setPosition(x + randomNumber/20 * (a % 2 == 0 ? 1 : -1),y+ randomNumber / 20 * (a % 2 == 0 ? 1 : -1), 0);
                    Particles.particles.at(Particles.particles.size() - 1).setVelocity(randomNumber/10* (a%2==0 ? 1:-1), randomNumber / 10*(a % 2 == 0 ? 1 : -1), 0);
                    a++;
                }
            }
            //std::cout << x << "  " << y << '\n';
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
            
        }

        window.clear();
               window.setView(view);
               Particles.drawAllParticles(window);
        
            
        Particles.updateGravityOnParticles();

       /* //std::cout << "This is in main " << Particles.particles.at(0).getXposition() << "   " << Particles.particles.at(0).getYposition() << std::endl;
        //std::cout << "This is in main2 " << Particles.particles.at(1).getXposition() << "   " << Particles.particles.at(1).getYposition() << std::endl;*/

      
      

        ////std::cout << "Acceleration of particle 1 " << p1.getXacceleration() << "  " << p1.getYacceleration() << std::endl;
       // //std::cout << "Acceleration of particle 2 " << p2.getXacceleration() << "  " << p2.getYacceleration() << std::endl;
      
        
    }

    return 0;
}