#include "drawable.h"

MyDrawable::MyDrawable(std::string filePath)
{
    texture.loadFromFile(filePath);
    sprite.setTexture(texture);
}

sf::Sprite& MyDrawable::getSprite()
{
    return sprite;
}