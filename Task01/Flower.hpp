#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>

class Flower 
{
private:
    sf::RenderWindow *window;
    sf::Clock clock;

    bool sunGrow;
    float sunSize;
    
    sf::CircleShape sun;
    sf::RectangleShape stem;
    sf::ConvexShape leave;
    sf::CircleShape flowerHead;
    
    void initShapes();

public:
    Flower(sf::RenderWindow *window);
    ~Flower();

    void draw();
};