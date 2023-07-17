#include "drawable.h"

MyDrawable::MyDrawable(std::string filePath)
{
    texture.loadFromFile(filePath);
    sprite.setTexture(texture);
}

const sf::Sprite& MyDrawable::getSprite() const
{
    return sprite;
}