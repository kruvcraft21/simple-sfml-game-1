#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "drawable.h"
#include <string>
#include <math.h>

using namespace std;

constexpr float INACCURACY_CAT_MOVE = 1.f;
constexpr float INACCURACY_TIME_FPS = 0.1f;

class Cat final : public MyDrawable
{
private:
    Cat() = delete;
    float speed = 50.f;
    sf::Clock clock;

public:
    Cat(string texturePath);
    void move(sf::Vector2f& finalPos) override;
};