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

int main()
{
    RenderWindow window(VideoMode(800, 600), "Arkanoid");
    
    RectangleShape paddle(Vector2f(50, 10));
    paddle.setPosition(window.getSize().x / 2, window.getSize().y - 2 * paddle.getSize().y);
    paddle.setFillColor(Color::Black);
    const float speed = 5;
    
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::KeyPressed)
                switch(event.key.code)
                {
                    case Keyboard::Left:  paddle.move(-speed, 0); break;
                    case Keyboard::Right: paddle.move( speed, 0); break;
                }
        }
        window.clear(Color::White);
        window.draw(paddle);
        window.display();
    }
    return EXIT_SUCCESS;
}
