#include "beam.h"

Beam::Beam(std::string filePath) : MyDrawable(filePath)
{
    sprite.setOrigin(16, 16);
}

void Beam::move(sf::Vector2f& finalPos)
{
    sprite.setPosition(finalPos);
}