#include "logic.h"
#include <iostream>

#include "Sphere.h"
#include <cmath>
#include <SFML/Graphics.hpp>
#include <string>

sf::Vector2f transformPoint(float x, float y, float windowWidth, float windowHeight)
{
    // Invert the y-coordinate, since the y-axis in a Cartesian system increases upwards
    // but the y-axis in an SFML system increases downwards
    y = -y;

    // Scale the x and y coordinates to fit within the size of the window
    x = (x / 2.0f) * windowWidth;
    y = (y / 2.0f) * windowHeight;

    // Translate the origin from the center of the window to the top-left corner
    x += (windowWidth / 2.0f);
    y += (windowHeight / 2.0f);

    return sf::Vector2f(x, y);
}
int main()
{

    particle p1(.64,0.65 , 0, -0.0004, -0.0001, 0, 0, 0, 0, 3200, 0, 10);
    particle p2(-0.77, 0.5, 0, 0, 0.0001, -0.0001, 0, 0, 0, 4000, 0, 10);

    particle p3(0, -0.7, 0, 0, 0.0000034, 0, 0, 0, 0, 33400, 0, 100);

    // Define the properties of the circle
    float radius = 10.0f;
    float centerX = p1.getXposition();
    float centerY = p1.getYposition();

    float centerXp2 = p2.getXposition();
    float centerYp2 = p2.getYposition();

    float centerXp3 = p3.getXposition();
    float centerYp3 = p3.getYposition();
    // Transform the center point of the circle from a Cartesian coordinate system to an SFML coordinate system
    sf::Vector2f center = transformPoint(centerX, centerY, 2560.0f, 1080.0f);
    sf::Vector2f centerp2 = transformPoint(centerXp2, centerYp2, 2560.0f, 1080.0f);
    sf::Vector2f centerp3 = transformPoint(centerXp3, centerYp3, 2560.0f, 1080.0f);

    // Create the circle shape
    sf::CircleShape circle(radius);
    circle.setOrigin(radius, radius);
    circle.setPosition(center);
    circle.setFillColor(sf::Color::Yellow);

    sf::CircleShape circle2(radius);
    circle2.setOrigin(radius, radius);
    circle2.setPosition(centerp2);
    circle2.setFillColor(sf::Color::Red);
    
    sf::CircleShape circle3(radius*1.5);
    circle3.setOrigin(radius*1.5, radius*1.5);
    circle3.setPosition(centerp3);
    circle3.setFillColor(sf::Color::Magenta);

    int a = 0;

    sf::Font font;
    if (!font.loadFromFile("LiberationSans.ttf"))
    {
        std::cerr << "Error loading font" << std::endl;
        return 1;
    }
    

    

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(10, 10);

    sf::RenderWindow window(sf::VideoMode(2560, 1440), "Stuff");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }  

        std::string fpsString = "Mass: " + std::to_string(p3.getMass());
        text.setString(fpsString);
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            p3.setMass(p3.getMass() + 1000);
            std::cout << "Mass is " << p3.getMass() << '\n';
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            p3.setMass(p3.getMass() - 1000);
            std::cout << "Mass is " << p3.getMass() << "\n";
        }
        window.clear();
          
        window.draw(circle);
        window.draw(circle2);
        window.draw(circle3);
        window.draw(text);


        window.display();
        Logic::changeAccleration(p1, Logic::getForceFromGravity_X(p1, p2) / p1.getMass(), Logic::getForceFromGravity_Y(p1, p2) / p1.getMass(), 0);
        Logic::changeAccleration(p1, (Logic::getForceFromGravity_X(p1, p3) / p1.getMass()) + p1.getXacceleration(), (Logic::getForceFromGravity_Y(p1, p3) / p1.getMass()) + p1.getYacceleration(),0);



        Logic::changeAccleration(p2, Logic::getForceFromGravity_X(p2, p1) / p2.getMass(), Logic::getForceFromGravity_Y(p2, p1) / p2.getMass(), 0);
        Logic::changeAccleration(p2, Logic::getForceFromGravity_X(p2, p3) / p2.getMass() + p2.getXacceleration(), Logic::getForceFromGravity_Y(p2, p3) / p2.getMass() + p2.getYacceleration(), 0);

        Logic::changeAccleration(p3, Logic::getForceFromGravity_X(p3, p1) / p3.getMass(), Logic::getForceFromGravity_Y(p3, p1) / p2.getMass(), 0);
        Logic::changeAccleration(p3, Logic::getForceFromGravity_X(p3, p2) / p3.getMass() + p3.getXacceleration(), Logic::getForceFromGravity_Y(p3, p2) / p3.getMass() + p3.getYacceleration(), 0);



        circle.setPosition(transformPoint(p1.getXposition(), p1.getYposition(), 2560, 1080));
        circle2.setPosition(transformPoint(p2.getXposition(), p2.getYposition(), 2560, 1080));
        circle3.setPosition(transformPoint(p3.getXposition(), p3.getYposition(), 2560, 1080));
        Logic::updatePosition(p1);
        Logic::updatePosition(p2); 
        Logic::updatePosition(p3);
        Logic::updateVelocity(p1);
        Logic::updateVelocity(p2);
        Logic::updatePosition(p3);
        //std::cout << "Acceleration of particle 1 " << p1.getXacceleration() << "  " << p1.getYacceleration() << std::endl;
       // std::cout << "Acceleration of particle 2 " << p2.getXacceleration() << "  " << p2.getYacceleration() << std::endl;
      
        
    }

    return 0;
}