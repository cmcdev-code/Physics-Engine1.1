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
    x = (80.0f * mouseX / windowSize.x) - 40.0f;
    y = -((56.0f * mouseY / windowSize.y) - 28.0f);
}
//long double Logic::time = 1;
int main()
{
    
    particleVectors Particles;

     particle p1(-9, -7, 0, 0, 0.00, 10, 0, 0, 0, 1.0, 0, 3);
    particle p2(-9, -7, 0, 0, 0.00, 0.000, 0, 0, 0, 100.0, 0, 150.5);
    
 

 
    Particles.particles.push_back(p1);
    Particles.particles.push_back(p2);


    sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(2560 * 40, 1440 * 40));
    view.setCenter(sf::Vector2f(1280.0f, 720.0f));
    sf::Font font;
    if (!font.loadFromFile("LiberationSans.ttf"))
    {
        std::cerr << "Error loading font" << std::endl;
        return 1;
    }
    

    
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
            Particles.particles.at(1).setXposition(Particles.particles.at(1).getXposition() - 0.1);
       //     Particles.particles.at(1).setMass(Particles.particles.at(1).getMass() + 5000);
         //  std::cout << "Mass is " << Prticles.particles.at(1).getMass() << '\n';
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
        {
            Particles.particles.at(1).setXposition(Particles.particles.at(0).getXposition() - 0.1);
             /* Particles.particles.at(1).setMass(Particles.particles.at(1).getMass() + 5000);
             std::cout << "Mass is " << Particles.particles.at(1).getMass() << '\n';*/
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            Particles.particles.at(1).setXposition(Particles.particles.at(1).getXposition() + 0.1);
           /* Particles.particles.at(1).setMass(Particles.particles.at(1).getMass() - 5000);
            std::cout << "Mass is " << Particles.particles.at(1).getMass() << "\n";*/
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
        {
            Particles.particles.at(1).setXposition(Particles.particles.at(0).getXposition() + 0.1);
         /*    Particles.particles.at(1).setMass(Particles.particles.at(1).getMass() - 5000);
             std::cout << "Mass is " << Particles.particles.at(1).getMass() << "\n";*/
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            Particles.particles.at(1).setYposition(Particles.particles.at(1).getYposition() + 0.1);
      /*      Particles.particles.at(1).setMass(Particles.particles.at(1).getMass() - 5000);
             std::cout << "Mass is " << Particles.particles.at(1).getMass() << "\n";*/
           
        } if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
        {
            Particles.particles.at(1).setYposition(Particles.particles.at(0).getYposition() + 0.1);
     /*       Particles.particles.at(1).setMass(Particles.particles.at(1).getMass() - 5000);
             std::cout << "Mass is " << Particles.particles.at(1).getMass() << "\n";*/

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            Particles.particles.at(1).setYposition(Particles.particles.at(1).getYposition() - 0.1);
       /*     Particles.particles.at(1).setMass(Particles.particles.at(1).getMass() - 5000);
             std::cout << "Mass is " << Particles.particles.at(1).getMass() << "\n";*/
       }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
        {
            Particles.particles.at(1).setYposition(Particles.particles.at(0).getYposition() - 0.1);
      /*      Particles.particles.at(1).setMass(Particles.particles.at(1).getMass() - 5000);
             std::cout << "Mass is " << Particles.particles.at(1).getMass() << "\n";*/
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
 //           Particles.particles.at(1).setMass(Particles.particles.at(1).getMass() + 50);
          //w  Particles.particles.at(1).circle.setRadius(Particles.particles.at(1).circle.getRadius() *1.01);
          //  Particles.particles.at(1).setRadius(Particles.particles.at(1).getRadius()* 1.01);
           Particles.particles.at(1).setMass(Particles.particles.at(1).getMass()*1.1);
           std::this_thread::sleep_for(std::chrono::milliseconds(1));
      //      std::cout << "Mass is " << Particles.particles.at(1).getMass() << '\n';
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        {
            Particles.particles.at(1).setMass(Particles.particles.at(1).getMass() /1.1);
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
            //Particles.particles.at(1).circle.setRadius(Particles.particles.at(1).circle.getRadius()/1.01);*/
          //  Particles.particles.at(1).setRadius(Particles.particles.at(1).getRadius() / 1.1);
          //  Particles.particles.at(1).setMass(Particles.particles.at(1).getMass() + 5000);
            //std::cout << "Mass is " << Particles.particles.at(1).getMass() << '\n';
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            Particles.particles.at(1).setMass(Particles.particles.at(1).getMass() *-1);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            
          /*  Particles.particles.at(1).setMass(Particles.particles.at(1).getMass());
            std::cout << "Mass is " << Particles.particles.at(1).getMass() << '\n';*/
        }
   /*     if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
        {
            Particles.particles.at(1).setVelocity(0, 0, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
        {
            for (int i = 0; i < Particles.particles.size(); i++) {
                Particles.particles.at(i).setPosition(0, 0, 0);
          }
        }*/
        //if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
        //   // Logic::time * 1.01;



        //}
        //if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        //   //Logic::time / 1.01;
        //}

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i XY = sf::Mouse::getPosition();
            float x, y;
            //std::cout << XY.x << "  " << XY.y << '\n';
            mouseToCartesian(XY.x, XY.y, x, y,window,view);

            auto time = std::chrono::high_resolution_clock::now();
            std::mt19937 rng1(time.time_since_epoch().count());
            std::uniform_real_distribution<double> dist1(10,10001);
            double randomNumber1 = dist1(rng1);
            std::mt19937 rng2(time.time_since_epoch().count());
            std::uniform_int_distribution<int> dist2(300, 341);
            int randomNumber2 = dist2(rng2);
            std::uniform_int_distribution<int> Vx(-10, 10);
            std::uniform_int_distribution<int> Vy(-10, 10);
            std::uniform_int_distribution<int> Va(0, 1);



            std::uniform_real_distribution<double> Coef(0, 0.8);
            double coeficentofRest = Coef(rng1);

            int randomNumberVx = Vx(rng2);
            int randomNumberVy = Vy(rng1);

            particle *p = new particle(x,y,0,randomNumberVx,randomNumberVy,0,0,0,0,randomNumber1,0,randomNumber2,coeficentofRest);
            p->setVelocity(randomNumberVx, randomNumberVy, 0);
            Particles.particles.push_back(*p);
            for (int i = 0; i < Particles.particles.size(); i++)
            {
            

                // Seed the random number generator with the time
                std::mt19937 rng(time.time_since_epoch().count());
                std::mt19937 rngNegativeY(time.time_since_epoch().count());
                std::mt19937 rngNegativeX(time.time_since_epoch().count());

                std::uniform_int_distribution<int> distColor(1, 6);
                int randomNumberForColor = distColor(rng);
                if (randomNumberForColor == 1) {
                    Particles.particles.at(Particles.particles.size() - 1).circle.setFillColor(sf::Color::Red);
                }
                else if (randomNumberForColor == 2) {
                    Particles.particles.at(Particles.particles.size() - 1).circle.setFillColor(sf::Color::Green);
                }
                else if (randomNumberForColor == 3) {
                    Particles.particles.at(Particles.particles.size() - 1).circle.setFillColor(sf::Color::Magenta);
                }
                else if (randomNumberForColor == 4) {
                    Particles.particles.at(Particles.particles.size() - 1).circle.setFillColor(sf::Color::Yellow);
                }
                else if (randomNumberForColor == 5) {
                    Particles.particles.at(Particles.particles.size() - 1).circle.setFillColor(sf::Color::White);
                }
                else if (randomNumberForColor == 6) {
                    Particles.particles.at(Particles.particles.size() - 1).circle.setFillColor(sf::Color::Cyan);
                }

                // Generate a random number
                std::uniform_int_distribution<int> dist(1, 10);
                int randomNumber = dist(rng);
                std::uniform_int_distribution<int> distX(1, 2);
                std::uniform_int_distribution<int> distY(1, 2);
                int randomNumberX = distX(rngNegativeX);
                int randomNumberY = distY(rngNegativeY);
               
                if (Logic::getDistanceBetweenParticle(Particles.particles.at(Particles.particles.size() - 1), Particles.particles.at(i)) <=
                    (Particles.particles.at(Particles.particles.size() - 1).getRadius() + Particles.particles.at(i).getRadius()) / 100) {
                    Particles.particles.at(Particles.particles.size() - 1).setPosition(x + randomNumber/20 * (randomNumberX == 1 ? 1 : -1),y+ randomNumber / 20 * (randomNumberY == 1 ? 1 : -1), 0);
                    Particles.particles.at(Particles.particles.size() - 1).setVelocity(randomNumber/30 * (randomNumberX==1 ? 1:-1), randomNumber / 30*(randomNumberY  == 1 ? 1 : -1), 0);
                   
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