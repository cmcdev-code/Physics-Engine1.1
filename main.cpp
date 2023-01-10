#include "IMP_GAME_LOGIC.h"


int main()
{
    IMP_GAME_LOGIC game;


    sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(2560 * 40, 1440 * 40));
    view.setCenter(sf::Vector2f(1280.0f, 720.0f));
  
    sf::RenderWindow window(sf::VideoMode(2560, 1440), "Stuff");
    while (window.isOpen())
    {


        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        game.pullKeyBoardEvents(window, view);
        window.clear();
        window.setView(view);

        game.drawAll(window);
        game.updateGravity();
    }
    return 0;
}
