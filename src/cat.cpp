#include "cat.h"

Cat::Cat(string texturePath) : MyDrawable(texturePath)
{
    sprite.setPosition(400, 400);
    sprite.setOrigin(19, 17.5f); // Предпологаемый центр картинки
}

void Cat::move(sf::Vector2f &finalPos)
{
    auto delta = finalPos - sprite.getPosition();
    // Разворачиваем спрайт кота на 180 градусов
    if (delta.x < 0)
    {
        sprite.setScale(-1, 1);
    }
    else
    {
        sprite.setScale(1, 1);
    }
    const float magnituda = sqrt(delta.x * delta.x + delta.y * delta.y);
    const float time = clock.restart().asSeconds();
    if (time < INACCURACY_TIME_FPS && magnituda > INACCURACY_CAT_MOVE)
    {
        delta *= (speed * time) / magnituda;
        this->sprite.move(delta);
    }
}