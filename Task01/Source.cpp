#include <SFML/Graphics.hpp>
#include "Flower.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 400, 400 }), "SFML works!");
    Flower flower(&window);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        flower.draw();
        window.display();
    }
}