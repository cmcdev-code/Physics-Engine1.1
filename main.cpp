#include "Scene.h"

int a = 0;
int main()
{
    Scene game;


    sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(2560 * 40, 1440 * 40));
    view.setCenter(sf::Vector2f(720.0f, 720.0f));

    sf::RenderWindow window(sf::VideoMode(2560, 1440), "Physics Engine");
    while (window.isOpen())
    {


        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        game.pullKeyBoardEvents(window, view);
        
        window.setView(view);

        game.drawAll(window);
        game.updateGravity();
        
        window.clear();
        
        

    }
    std::cout << game.returnSize();

    return 0;
    }
