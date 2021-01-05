/*
 * File:   game.cpp
 * Author: Magno El Magnifico
 *
 * Created on 4/1/2021, 18:10
 *
 * Definitions of the Arkanoid Game class
 */

#include "Arkanoid.hpp"

#include <cmath>
#include <iostream>

using namespace sf;

Arkanoid::Arkanoid(RenderWindow & window_p)
{
    window = & window_p;

    ////// Load textures //////
    if (!paddle_texture.loadFromFile("resources/images/paddle.png"))
        std::cerr << "Error to load the paddle texture" << std::endl;
    if (!ball_texture.loadFromFile("resources/images/ball.png"))
        std::cerr << "Error to load the ball texture" << std::endl;
    if (!block_texture.loadFromFile("resources/images/block01.png"))
        std::cerr << "Error to load the block texture" << std::endl;

    ////// Paddle set up //////
    paddle.setTexture(paddle_texture);
    paddle.setPosition(
            (window->getSize().x + paddle.getTextureRect().width) / 2,
             window->getSize().y - paddle.getTextureRect().height * 2);

    ////// Ball set up //////
    ball.setTexture(ball_texture);
    ball.setPosition(window->getSize().x / 2, window->getSize().y / 2);

    ////// Blocks set up //////
    for (int i = 0; i < blocks_number; i++)
    {
        blocks.push_back(Sprite());
        blocks.back().setTexture(block_texture);
        blocks.back().setPosition(
                i % int(std::sqrt(blocks_number)) * blocks.back().getTextureRect().width,
                i / int(std::sqrt(blocks_number)) * blocks.back().getTextureRect().height);
    }
}

void Arkanoid::keyEvent(sf::Event & event)
{
    switch (event.key.code)
    {
        case Keyboard::Left:
            if (paddle.getPosition().x - paddle_speed > 0)
                paddle.move(-paddle_speed, 0);
            break;
        case Keyboard::Right:
            if (paddle.getPosition().x + paddle.getTextureRect().width + paddle_speed < window->getSize().x)
                paddle.move(paddle_speed, 0);
            break;
    }
}

void Arkanoid::update(std::function<void()> onVictory, std::function<void()> onGameOver)
{
    // Check firts the X movement (this ways it is easier to determine
    // in which direction should bounce the ball)
    ball.move(ball_movement.x, 0);
    if (ball.getPosition().x <= 0 || ball.getPosition().x + ball.getTextureRect().width >= window->getSize().x)
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

    // Now check the Y movement
    ball.move(0, ball_movement.y);
    if (isColiding(ball, paddle) || ball.getPosition().y <= 0)
        ball_movement.y = -ball_movement.y;
    else
    {
        for (int i = 0; i < blocks.size(); i++)
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
        onVictory();
    else if (ball.getPosition().y + ball.getTextureRect().width >= window->getSize().y)
        onGameOver();
}

void Arkanoid::render()
{
    for (auto & block : blocks)
        window->draw(block);
    window->draw(paddle);
    window->draw(ball);
}
