#include "SFML/Graphics.hpp"
#include "src/cat.h"
#include "src/beam.h"
#include "src/drawable.h"
#include <array>
#include <memory>

using namespace std;

constexpr unsigned int WINDOW_HEIGHT = 800;
constexpr unsigned int WINDOW_WIGTH = 800;

void onMouseMove(sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePos)
{
    mousePos = {static_cast<float>(event.x), static_cast<float>(event.y)};
}

void pollMouseEvent(sf::RenderWindow &window, sf::Vector2f &mousePos)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::EventType::Closed:
            window.close();
            break;
        case sf::Event::EventType::MouseMoved:
            onMouseMove(event.mouseMove, mousePos);
            break;

        default:
            break;
        }
    }
}

void renderWindow(sf::RenderWindow &window, const auto &objs)
{
    window.clear(sf::Color::White);
    for (auto &obj : objs)
    {
        window.draw(obj->getSprite());
    }
    window.display();
}

int main(int, char **)
{
    array<unique_ptr<MyDrawable>, 2> drawObjs;

    // Init cat
    drawObjs[0] = make_unique<Beam>("assets/red_pointer.png");
    // Init red beam
    drawObjs[1] = make_unique<Cat>("assets/cat.png");

    // Init window
    sf::RenderWindow window({WINDOW_HEIGHT, WINDOW_WIGTH},
                            "Cat following beam");
    window.setFramerateLimit(60);

    sf::Vector2f mousePos = {0, 0};

    while (window.isOpen())
    {
        pollMouseEvent(window, mousePos);
        for (auto &obj : drawObjs)
        {
            obj->move(mousePos);
        }
        renderWindow(window, drawObjs);
    }

    return 0;
}
