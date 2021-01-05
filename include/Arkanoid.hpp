///////////////////////////////////////////////////////////
//
// File:   Arkanoid.hpp
// Author: Magno El Magnifico
// Created on 4/1/2021, 18:10
// 
// Arkanoid Game class
//
///////////////////////////////////////////////////////////

#ifndef ARKANOID_HPP
#define ARKANOID_HPP    

///////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////
#include <functional>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Texture.hpp>

class Arkanoid
{
public:
    ///////////////////////////////////////////////////////
    ///
    /// \brief Set up the Arkanoid game.
    /// \param window sf::RenderWindow instance where the game will be rendered in.
    ///
    ///////////////////////////////////////////////////////
    Arkanoid(sf::RenderWindow & window);
    
    ///////////////////////////////////////////////////////
    /// 
    /// \brief Implement the game events.
    /// 
    /// This function sould be implemented into the event
    /// loop and inside the Event::KeyPressed if:
    ///
    /// <code>
    /// sf::Event event;
    /// while (window.pullEvent(event))
    /// {
    ///   if (event.type == sf::Event::KeyPressed)
    ///   {
    ///     arkanoid_game.keyEvent(event);
    ///   }
    /// }
    /// </code>
    ///
    /// \param event sf:Event instance.
    ///
    ///////////////////////////////////////////////////////
    void keyEvent(sf::Event & event);
    
    ///////////////////////////////////////////////////////
    /// 
    /// \brief Update the game.
    /// \param onVictory  Function to call when the player wins.
    /// \param onGameOver Function to call when the player loses.
    ///
    ///////////////////////////////////////////////////////
    void update(std::function<void()> onVictory, std::function<void()> onGameOver);
    
    ///////////////////////////////////////////////////////
    /// 
    /// \brief Displays the game on the window given on the constructor
    ///
    ///////////////////////////////////////////////////////
    void render();
    
private:
    sf::RenderWindow * window;

    ////// GAME OBJECTS //////

    sf::Sprite paddle;
    sf::Sprite ball;
    std::vector <sf::Sprite> blocks;
    
    ////// TEXTURES //////
    
    sf::Texture paddle_texture;
    sf::Texture ball_texture;
    sf::Texture block_texture;

    ////// CONSTANTS AND VALUES //////

    const int    blocks_number = 9;
    const float  paddle_speed  = 30;
    sf::Vector2f ball_movement = sf::Vector2f(-3.f, -3.f);

    ////// METHODS //////

    bool isColiding(sf::Sprite a, sf::Sprite b)
    {
        return a.getGlobalBounds().intersects(b.getGlobalBounds());
    }
}; // Arkanoid class

#endif // ARKANOID_HPP
