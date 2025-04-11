#include "Flower.hpp"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

Flower::Flower(sf::RenderWindow *window)
{
    this->window = window;
    
    this->sunGrow = true;
    this->sunSize = 15;

    this->initShapes();
}

Flower::~Flower(){ }

void Flower::initShapes()
{
    this->sun.setRadius(this->sunSize);
    this->sun.setFillColor(sf::Color::Yellow);
    this->sun.setOutlineColor(sf::Color::Red);
    this->sun.setOutlineThickness(2);
    this->sun.setPosition({ 50 - this-> sunSize, 50 - this->sunSize });

    this->stem.setSize({ 3, 150 });
    this->stem.setFillColor({ 0, 200, 0 });
    this->stem.setPosition({ 198.5, 250 });
    
    this->leave.setPointCount(4);
    this->leave.setFillColor({ 0, 200, 0 });
    this->leave.setPoint(0, { 200, 300 });
    this->leave.setPoint(1, { 150, 310 });
    this->leave.setPoint(2, { 120, 350 });
    this->leave.setPoint(3, { 170, 340 });

    this->flowerHead.setPosition({ 150, 150 });
    this->flowerHead.setFillColor(sf::Color::Magenta);
    this->flowerHead.setOutlineColor(sf::Color::Cyan);
    this->flowerHead.setRadius(50);
    this->flowerHead.setOutlineThickness(20);
}

void Flower::draw()
{ 
    if (this->clock.getElapsedTime().asMilliseconds() >= 100) // 10 FPS
    {
        this->sun.setPosition({ 50 - this->sunSize, 50 - this->sunSize });
        this->sun.setRadius(this->sunSize);

        if (this->sunSize >= 20)
            this->sunGrow = false;
        else if (this->sunSize <= 15)
            this->sunGrow = true;

        this->sunSize += this->sunGrow ? 1 : -1;

        this->clock.restart();
    }

    window->draw(this->leave);
    window->draw(this->stem);
    window->draw(this->flowerHead);
    window->draw(this->sun);
}