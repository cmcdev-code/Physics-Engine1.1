#include "Scene.h"

//

void mouseToCartesian(float mouseX, float mouseY, float& x, float& y, sf::RenderWindow& window, sf::View& view) {
    // Get the position and size of the window
    sf::Vector2u windowSize = window.getSize();

    // Convert the mouse coordinates to window coordinates
    x = (80.0f * mouseX / windowSize.x) - 40.0f;
    y = -((56.0f * mouseY / windowSize.y) - 28.0f);
}
void Scene::pullKeyBoardEvents(sf::RenderWindow& window, sf::View& view) {
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
        Particles.particles.at(1).setMass(Particles.particles.at(1).getMass() *1.1);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        Particles.particles.at(1).setMass(Particles.particles.at(1).getMass() / 1.1);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        Particles.particles.at(1).setMass(Particles.particles.at(1).getMass() * -1);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
    {
        for (int i = 0; i < Particles.particles.size(); i++) {
            Particles.particles.at(i).setVelocity(0.001, 0.001, 0);
     }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        createNewParticleDynamically(window, view);
        
    }
  
}

void Scene::createNewParticleDynamically(sf::RenderWindow & window, sf::View& view) {
        sf::Vector2i XY = sf::Mouse::getPosition();
        float x, y;
        //std::cout << XY.x << "  " << XY.y << '\n';
        mouseToCartesian(XY.x, XY.y, x, y, window, view);

        auto time = std::chrono::high_resolution_clock::now();
        std::mt19937 rng1(time.time_since_epoch().count());

        std::normal_distribution<double> dist1(1000, 100);
        double randomNumber1 = dist1(rng1);

     

        //Coefficent of restitution
        std::uniform_real_distribution<double> Coef(0, 0.8);
        double coeficentofRest = Coef(rng1);

      
            particle* p = new particle(x, y, 0, 0, 0, 0, 0, 0, 0, randomNumber1, 0, randomNumber1 / 3, coeficentofRest);


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


void Scene::drawAll(sf::RenderWindow& window) {
    Particles.drawAllParticles(window);
}
void Scene::updateGravity() {
    Particles.updateGravityOnParticles(15);
}
int Scene::returnSize() const {
    return Particles.particles.size();
}
//void Scene::setMassOfParticlesInArray() 
//{
//    for (int i = 0; i < Particles.particles.size(); i++) {
//        massOfparticlesInArray[int(Particles.particles.at(i).getXposition()) + 27][int(Particles.particles.at(i).getYposition() + 27)]+=Particles.particles.at(i).getMass();
//    }
//}
//void Scene::setArrayOfVectorParticlePointers() 
//{
//    for (int i = 0; i < returnSize(); i++) {
//        BoxesOfParticles[int(Particles.particles.at(i).getXposition()) + 27][int(Particles.particles.at(i).getYposition() + 27)].push_back(&Particles.particles.at(i));
//    }
//}

//void Scene::updateGravityOnParticles() {
//    setArrayOfVectorParticlePointers();
//    setMassOfParticlesInArray();
// 
//}