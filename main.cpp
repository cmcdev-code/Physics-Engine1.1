#include "IMP_GAME_LOGIC.h"


int main()
{
    IMP_GAME_LOGIC game;


    sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(2560 * 40, 1440 * 40));
    view.setCenter(sf::Vector2f(1280.0f, 720.0f));
    int fps = 0;
    int frameCount = 0;
    sf::Clock lastTime;
    lastTime.restart();

    sf::Font font;
    if (!font.loadFromFile("LiberationSans.ttf")) {
        std::cerr << "Error loading font" << std::endl;
        return 1;
    }
    sf::Text fpsText;
    fpsText.setFont(font);
    fpsText.setCharacterSize(600);
    fpsText.setFillColor(sf::Color::White);
    fpsText.setPosition(-300, 200);

    sf::RenderWindow window(sf::VideoMode(2560, 1440), "Stuff");
    while (window.isOpen())
    {

        frameCount++;

        // Calculate the FPS
        sf::Time elapsed = lastTime.getElapsedTime();
        if (elapsed.asSeconds() >= 1.0f) {
            fps = frameCount / elapsed.asSeconds();
            frameCount = 0;
            lastTime.restart();
        }

        // Update the FPS text
        fpsText.setString("FPS: " + std::to_string(fps));

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        game.pullKeyBoardEvents(window, view);
        window.clear();
        window.setView(view);
        window.draw(fpsText);
        game.drawAll(window);
        game.updateGravity();
    }
    return 0;
}