#pragma once

#include "SFML/Graphics.hpp"
#include "drawable.h"

class Beam final : public MyDrawable
{
private:
    Beam() = delete;
public: 
    Beam(std::string filePath);
    void move(sf::Vector2f& finaPos) override;
};