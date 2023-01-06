#include "logic.h"
#include <iostream>

#include "Sphere.h"
#include <cmath>
#include <SFML/Graphics.hpp>
#include <string>
#include "particleVectors.h"


int main()
{
    particleVectors Particles;

    particle p1(.64, 0.65, 0, -0.0004, -0.0001, 0, 0, 0, 0, 300, 0, 50);
    particle p2(-0.77, 0.5, 0, 0, 0.00, 0.000, 0, 0, 0, 150000.0, 0, 350);

    particle p3(0, -0.7, 0, 0, 0.0000034, 0, 0, 0, 0, 15, 0, 200);
    particle p4(1, 3, 0, 0, 0.0000034, 0, 0, 0, 0, 330, 0, 103);
    particle p5(0, 0.7, 0, 0, 0.0000034, 0, 0, 0, 0, 330, 0, 110);
    particle p6(1, -0.7, 0, 0, 0.0000034, 0, 0, 0, 0, 15, 0, 101);
    particle p7(1.7, 0, 0, 1, 1, 0, 0, 0, 0, 330, 0, 110);
    particle p8(2.4, 0, 0, -1, -1, 0, 0, 0, 0, 15, 0, 101);
    particle p9(3.1, 0, 0, 2, -1, 0, 0, 0, 0, 330, 0, 110);
    particle p10(3.8, 0, 0, 0, 3, 0, 0, 0, 0, 15, 0, 101);
    particle p11(4.5, 0, 0, 0, 4, 0, 0, 0, 0, 330, 0, 110);
    particle p12(5.2, 0, 0, 1, 1, 0, 0, 0, 0, 300, 0, 101);
    particle p13(5.9, 0, 0, 2, 0, 0, 0, 0, 0, 330, 0, 110);
    particle p14(6.6, 0, 0, 3,6, 0, 0, 0, 0, 15, 0, 101);
    particle p15(7.3, 0, 0, 0, 0, 0, 0, 0, 0, 330, 0, 110);
    particle p16(8.0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 0, 101);
    particle p17(8.7, 0, 0, 0, 0, 0, 0, 0, 0, 330, 0, 110);
    particle p18(8.9, -1, 0, 0, 0, 0, 0, 0, 0, 330, 0, 110);
    particle p19(9.1, -9, 0, 0, 0, 0, 0, 0, 0, 330, 0, 110);
    particle p20(9.3, -7, 0, 0, 0, 0, 0, 0, 0, 330, 0, 110);
    particle p21(9.5, 1, 0, 0, 0, 0, 0, 0, 0, 330, 0, 110);
    particle p22(-9.8, 5, 0, 0, 0, 0, 0, 0, 0, 330, 0, 110);


    //
    //   
    particle p23(-8.7, 4, 0, 0, 0, 0, 0, 0, 0, 330, 0, 110);
    particle p24(-8.5, 3, 0, 0, 0, 0, 0, 0, 0, 330, 0, 110);
    particle p25(-8.4, 2, 0, 0, 0, 0, 0, 0, 0, 330, 0, 110);
    particle p26(-8.2, 2, 0, 0, 0, 0, 0, 0, 0, 330, 0, 110);
   
    particle p27(-10, 7, 0, 0, 0, 0, 0, 0, 0, 330, 0, 110);

    Particles.particles.push_back(p1);
    Particles.particles.push_back(p2);
    Particles.particles.push_back(p3);
    Particles.particles.push_back(p4);
    Particles.particles.push_back(p5);
    Particles.particles.push_back(p6);
    //Particles.particles.push_back(p7);
    //Particles.particles.push_back(p8);
    //Particles.particles.push_back(p9);
    //Particles.particles.push_back(p10);
    //Particles.particles.push_back(p11);
    //Particles.particles.push_back(p12);
    //Particles.particles.push_back(p13);
    //Particles.particles.push_back(p14);
    //Particles.particles.push_back(p15);
    //Particles.particles.push_back(p16);
    //Particles.particles.push_back(p17);
    //Particles.particles.push_back(p18);
    //Particles.particles.push_back(p19);
    //Particles.particles.push_back(p20);
    //Particles.particles.push_back(p21);
    //Particles.particles.push_back(p22);
    //Particles.particles.push_back(p23);
    //Particles.particles.push_back(p24);
    //Particles.particles.push_back(p25);
    //Particles.particles.push_back(p26);
    //p27.circle.setFillColor(sf::Color::Red);
    //Particles.particles.push_back(p27);
    sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(2560 * 10, 1440 * 10));
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
            Particles.particles.at(1).setXposition(Particles.particles.at(1).getXposition() - 0.01);
          //  Particles.particles.at(1).setMass(Particles.particles.at(1).getMass() + 5000);
           //std::cout << "Mass is " << Particles.particles.at(1).getMass() << '\n';
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            Particles.particles.at(1).setXposition(Particles.particles.at(1).getXposition() + 0.01);
           // Particles.particles.at(1).setMass(Particles.particles.at(1).getMass() - 5000);
            //std::cout << "Mass is " << Particles.particles.at(1).getMass() << "\n";
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            Particles.particles.at(1).setYposition(Particles.particles.at(1).getYposition() + 0.01);
            //Particles.particles.at(1).setMass(Particles.particles.at(1).getMass() - 5000);
             //std::cout << "Mass is " << Particles.particles.at(1).getMass() << "\n";
           
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            Particles.particles.at(1).setYposition(Particles.particles.at(1).getYposition() - 0.01);
            //Particles.particles.at(1).setMass(Particles.particles.at(1).getMass() - 5000);
             //std::cout << "Mass is " << Particles.particles.at(1).getMass() << "\n";
       }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
           // Particles.particles.at(1).setMass(Particles.particles.at(1).getMass() + 50);
            Particles.particles.at(1).circle.setRadius(Particles.particles.at(1).circle.getRadius() + 0.2);
            Particles.particles.at(1).setMass(Particles.particles.at(1).getMass()*1.01);
            std::cout << "Mass is " << Particles.particles.at(1).getMass() << '\n';
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        {
            Particles.particles.at(1).setMass(Particles.particles.at(1).getMass() /1.01);
            Particles.particles.at(1).circle.setRadius(Particles.particles.at(1).circle.getRadius() - 0.2);
            //Particles.particles.at(1).setMass(Particles.particles.at(1).getMass() + 5000);
            std::cout << "Mass is " << Particles.particles.at(1).getMass() << '\n';
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

        window.clear();
               window.setView(view);
               Particles.drawAllParticles(window);
        
            
        Particles.updateGravityOnParticles();

       /* std::cout << "This is in main " << Particles.particles.at(0).getXposition() << "   " << Particles.particles.at(0).getYposition() << std::endl;
        std::cout << "This is in main2 " << Particles.particles.at(1).getXposition() << "   " << Particles.particles.at(1).getYposition() << std::endl;*/

      
      

        //std::cout << "Acceleration of particle 1 " << p1.getXacceleration() << "  " << p1.getYacceleration() << std::endl;
       // std::cout << "Acceleration of particle 2 " << p2.getXacceleration() << "  " << p2.getYacceleration() << std::endl;
      
        
    }

    return 0;
}