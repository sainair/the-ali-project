#include <SFML/Graphics.hpp>
#include <iostream>

sf::Image loadImage(sf::String path)
{
    sf::Image image;
    if(!image.loadFromFile(path))
    {
        std::cout<<"No image\n";
    }
    return image;
}

sf::Font loadFont(sf::String path)
{
    sf::Font font;
    if(!font.loadFromFile(path))
    {
        std::cout<<"The path provided is wrong\n";
    }
    return font;
}

sf::Image getImg(sf::String path)
{
    sf::Image image;
    if(!image.loadFromFile(path))
    {
        std::cout<<"No image\n";
    }
    return image;
}

sf::Texture getTexture(sf::Image image)
{
    sf::Texture t;
    if(!t.loadFromImage(image))
    {
        std::cout<<"No image\n";
    }
    return t;
}