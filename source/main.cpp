/*
 * File:   main.cpp
 * Author: Magno El Magnifico
 *
 * Created on 30/12/2020, 14:25
 *
 * Main file and entry point of Arkanoid
 */

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

using namespace sf;

const float speed = 10;

int main()
{
    RenderWindow window(VideoMode(600, 600), "Arkanoid");

    RectangleShape paddle(Vector2f(50, 10));
    paddle.setPosition(window.getSize().x / 2, window.getSize().y - 2 * paddle.getSize().y);
    paddle.setFillColor(Color::Black);

    RectangleShape ball(Vector2f(10, 10));
    ball.setPosition(window.getSize().x / 2, window.getSize().y / 2);
    ball.setFillColor(Color::Black);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::KeyPressed)
            {
                switch (event.key.code)
                {
                    case Keyboard::Left:
                        if (paddle.getPosition().x - speed > 0)
                            paddle.move(-speed, 0);
                        break;
                    case Keyboard::Right:
                        if (paddle.getPosition().x + paddle.getSize().x + speed < window.getSize().x)
                            paddle.move(speed, 0);
                        break;
                }
            }
        }
        
        window.clear(Color::White);
        
        window.draw(paddle);
        window.draw(ball);
        
        window.display();
    }
    return EXIT_SUCCESS;
}
