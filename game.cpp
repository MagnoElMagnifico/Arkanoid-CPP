/*
 * File:   game.cpp
 * Author: Magno El Magnifico
 *
 * Created on 30/12/2020, 14:25
 *
 * Main file and entry point of Arkanoid
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Event.hpp>

using namespace sf;

const int blocks_number  = 9;
const float paddle_speed = 30;
Vector2f ball_movement(-3, -3);

bool isColiding(Sprite a, Sprite b)
{
    return a.getGlobalBounds().intersects(b.getGlobalBounds());
}

//// GAME OBJECTS ////
Sprite paddle;
Sprite ball;
std::vector <Sprite> blocks;

int main()
{
    //// SET UP ////
    RenderWindow window(VideoMode(600, 600), "Arkanoid");
    window.setVerticalSyncEnabled(true);

    Texture paddle_texture, ball_texture, block_texture;
    paddle_texture.loadFromFile("resources/images/paddle.png");
    ball_texture  .loadFromFile("resources/images/ball.png");
    block_texture .loadFromFile("resources/images/block01.png");

    paddle.setTexture(paddle_texture, true);
    paddle.setPosition(
            (window.getSize().x + paddle.getTextureRect().width) / 2,
             window.getSize().y - paddle.getTextureRect().height * 2);

    ball.setTexture(ball_texture, true);
    ball.setPosition(window.getSize().x / 2, window.getSize().y / 2);

    for (int i = 0; i < blocks_number; i++)
    {
        blocks.push_back(Sprite());
        blocks.back().setTexture(block_texture);
        blocks.back().setPosition(
            i % int(std::sqrt(blocks_number)) * blocks.back().getTextureRect().width,
            i / int(std::sqrt(blocks_number)) * blocks.back().getTextureRect().height);
    }

    //// GAME LOOP ////
    while (window.isOpen())
    {
        //// EVENT LOOP ////
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed) window.close();
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
        ball.move(ball_movement.x, 0);
        if (ball.getPosition().x <= 0 || ball.getPosition().x + ball.getTextureRect().width >= window.getSize().x)
            ball_movement.x = -ball_movement.x;
        else
        {
            for (int i = 0; i < blocks.size(); i++)
            {
                if (isColiding(ball, blocks[i]))
                {
                    ball_movement.x = -ball_movement.x;
                    blocks.erase(blocks.begin() + i);
                    break;
                }
            }
        }
        
        ball.move(0, ball_movement.y);
        if (isColiding(ball, paddle) || ball.getPosition().y <= 0) ball_movement.y = -ball_movement.y;
        else
        {
            for (int i = 0; i < blocks.size(); i ++)
            {
                if (isColiding(ball, blocks[i]))
                {
                    ball_movement.y = -ball_movement.y;
                    blocks.erase(blocks.begin() + i);
                    break;
                }
            }
        }
        
        // Check for the game state
        if (blocks.empty())
        {
            std::cout << "VICTORY" << std::endl;
            window.close();
        }
        else if (ball.getPosition().y + ball.getTextureRect().width >= window.getSize().y)
        {
            std::cout << "GAME OVER" << std::endl;
            window.close();
        }

        //// RENDER ////
        window.clear(Color(50, 50, 50));

        for (auto& block : blocks) window.draw(block);
        window.draw(paddle);
        window.draw(ball);

        window.display();
    }
    return EXIT_SUCCESS;
}
