#include <SFML/Graphics.hpp>
#include <iostream>

sf::RectangleShape createRect(sf::Color color, float width, float length, float posX=0, float posY=0)
{
    sf::RectangleShape rect({width, length});
    rect.setFillColor(color);
    rect.setOrigin({posX, posY});
    return rect;
}