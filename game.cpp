/*
 * File:   game.cpp
 * Author: Magno El Magnifico
 *
 * Created on 30/12/2020, 14:25
 *
 * Main file and entry point of Arkanoid
 */

#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Event.hpp>

using namespace sf;

const float paddle_speed = 10;

bool isColiding(Sprite a, Sprite b)
{
    return a.getGlobalBounds().intersects(b.getGlobalBounds());
}

//// GAME OBJECTS ////
Sprite paddle;
Sprite ball;

int main()
{
    //// SET UP ////
    RenderWindow window(VideoMode(600, 600), "Arkanoid");
    window.setVerticalSyncEnabled(true);

    Texture paddle_texture, ball_texture;
    paddle_texture.loadFromFile("resources/images/paddle.png");
    ball_texture  .loadFromFile("resources/images/ball.png");
    
    paddle.setTexture(paddle_texture, true);
    paddle.setPosition(
        (window.getSize().x + paddle.getTextureRect().width) / 2,
        window.getSize().y - 2 * paddle.getTextureRect().height);

    ball.setTexture(ball_texture, true);
    ball.setPosition(window.getSize().x / 2, window.getSize().y / 2);
    Vector2f ball_movement = Vector2f(4, 3);
    
    //// GAME LOOP ////
    while (window.isOpen())
    {
        //// EVENT LOOP ////
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
                        if (paddle.getPosition().x - paddle_speed > 0)
                            paddle.move(-paddle_speed, 0);
                        break;
                    case Keyboard::Right:
                        if (paddle.getPosition().x + paddle.getTextureRect().width +
                                paddle_speed < window.getSize().x)
                            paddle.move(paddle_speed, 0);
                        break;
                }
            }
        }
        
        //// UPDATE ////
        if (ball.getPosition().x <= 0 || 
            ball.getPosition().x + ball.getTextureRect().width >= window.getSize().x)
        {
            ball_movement.x = -ball_movement.x;
        }
        else if (ball.getPosition().y <= 0 || isColiding(ball, paddle))
            ball_movement.y = -ball_movement.y;
        else if (ball.getPosition().y + ball.getTextureRect().width >= window.getSize().y)
        {
            std::cout << "GAME OVER" << std::endl;
            break;
        }
        
        ball.move(ball_movement);
        
        //// RENDER ////
        window.clear(Color(50, 50, 50));

        window.draw(paddle);
        window.draw(ball);

        window.display();
    }
    return EXIT_SUCCESS;
}
