#include "IMP_GAME_LOGIC.h"

void mouseToCartesian(float mouseX, float mouseY, float& x, float& y, sf::RenderWindow& window, sf::View& view) {
    // Get the position and size of the window
    sf::Vector2u windowSize = window.getSize();

    // Convert the mouse coordinates to window coordinates
    x = (80.0f * mouseX / windowSize.x) - 40.0f;
    y = -((56.0f * mouseY / windowSize.y) - 28.0f);
}
void IMP_GAME_LOGIC::pullKeyBoardEvents(sf::RenderWindow& window, sf::View& view) {
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
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        Particles.particles.at(1).setYposition(Particles.particles.at(1).getYposition() + 0.1);
      

    } if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
    {
        Particles.particles.at(1).setYposition(Particles.particles.at(0).getYposition() + 0.1);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        Particles.particles.at(1).setYposition(Particles.particles.at(1).getYposition() - 0.1);


    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
    {
        Particles.particles.at(1).setYposition(Particles.particles.at(0).getYposition() - 0.1);

    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        Particles.particles.at(1).setMass(Particles.particles.at(1).getMass() * 1.1);
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        Particles.particles.at(1).setMass(Particles.particles.at(1).getMass() / 1.1);
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        Particles.particles.at(1).setMass(Particles.particles.at(1).getMass() * -1);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        createNewParticleDynamically(window, view);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        Particles.particles.at(1).setZposition(Particles.particles.at(1).getZposition() + 0.1);
        std::cout << Particles.particles.at(1).getZposition()<<std::endl;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {
        Particles.particles.at(1).setZposition(Particles.particles.at(1).getZposition() - 0.1);
    }
}   


void IMP_GAME_LOGIC::createNewParticleDynamically(sf::RenderWindow & window, sf::View& view) {
        sf::Vector2i XY = sf::Mouse::getPosition();
        float x, y;
        //std::cout << XY.x << "  " << XY.y << '\n';
        mouseToCartesian(XY.x, XY.y, x, y, window, view);

        auto time = std::chrono::high_resolution_clock::now();
        std::mt19937 rng1(time.time_since_epoch().count());

        std::uniform_real_distribution<double> dist1(9, 10);
        double randomNumber1 = dist1(rng1);

        std::uniform_int_distribution<int> dist2(300, 341);
        int randomNumber2 = dist2(rng1);

        std::uniform_int_distribution<int> Vx(-10, 10);
        std::uniform_int_distribution<int> Vy(-10, 10);
      
        
        int randomNumberVx = Vx(rng1);
        int randomNumberVy = Vy(rng1);

       
        //Coefficent of restitution
        std::uniform_real_distribution<double> Coef(0, 0.8);
        double coeficentofRest = Coef(rng1);

     
        particle* p = new particle(x, y, 0, randomNumberVx, randomNumberVy, 0, 0, 0, 0, randomNumber1, 0, randomNumber2, coeficentofRest);

        p->setVelocity(randomNumberVx, randomNumberVy, 0);
        
      
        Particles.particles.push_back(*p);

        //determinaing color
        std::uniform_int_distribution<int> distColor(1, 6);
        int randomNumberForColor = distColor(rng1);
        
        switch (randomNumberForColor)
        {
        case 1:
            Particles.particles.at(Particles.particles.size() - 1).circle.setFillColor(sf::Color::Red);
            break;
        case 2:
            Particles.particles.at(Particles.particles.size() - 1).circle.setFillColor(sf::Color::Green);
            break;
        case 3:
            Particles.particles.at(Particles.particles.size() - 1).circle.setFillColor(sf::Color::Magenta);
            break;
        case 4:
            Particles.particles.at(Particles.particles.size() - 1).circle.setFillColor(sf::Color::Yellow);
            break;
        case 5:
            Particles.particles.at(Particles.particles.size() - 1).circle.setFillColor(sf::Color::White);
            break;
        case 6:
            Particles.particles.at(Particles.particles.size() - 1).circle.setFillColor(sf::Color::Cyan);
            break;

        }
        for (int i = 0; i < Particles.particles.size(); i++)
        { 
            if (Logic::getDistanceBetweenParticle(Particles.particles.at(Particles.particles.size() - 1), Particles.particles.at(i)) <= (Particles.particles.at(Particles.particles.size() - 1).getRadius() + Particles.particles.at(i).getRadius()) / 100) 
            {  // Generate a random number
                std::uniform_int_distribution<int> dist(1, 10);
                int randomNumber = dist(rng1);
                std::uniform_int_distribution<int> distX(1, 2);
                std::uniform_int_distribution<int> distY(1, 2);
                int randomNumberX = distX(rng1);
                int randomNumberY = distY(rng1);

                Particles.particles.at(Particles.particles.size() - 1).setPosition(x + randomNumber / 20 * (randomNumberX == 1 ? 1 : -1), y + randomNumber / 20 * (randomNumberY == 1 ? 1 : -1), 0);
                Particles.particles.at(Particles.particles.size() - 1).setVelocity(randomNumber / 30 * (randomNumberX == 1 ? 1 : -1), randomNumber / 30 * (randomNumberY == 1 ? 1 : -1), 0);

            }
        }
    } 

void IMP_GAME_LOGIC::drawAll(sf::RenderWindow &window){
    Particles.drawAllParticles(window);
}
void IMP_GAME_LOGIC::updateGravity() {
    Particles.updateGravityOnParticles(12);
}