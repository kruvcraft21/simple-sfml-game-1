#pragma once

#include "SFML/Graphics.hpp"
#include <string>

class MyDrawable
{

private:
    sf::Texture texture;
protected:
    sf::Sprite sprite;
    MyDrawable(std::string filePath);
public:
    const sf::Sprite &getSprite() const;
    virtual void move(sf::Vector2f& finalPos) = 0;
    MyDrawable() = delete;
};