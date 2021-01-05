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
#include <SFML/Window/Event.hpp>

#include "Arkanoid.hpp"

using namespace sf;

int main()
{
    ////// SET UP //////
    RenderWindow window(VideoMode(600, 600), "Arkanoid");
    window.setVerticalSyncEnabled(true);
    
    Arkanoid game(window);

    ////// GAME LOOP //////
    while (window.isOpen())
    {
        ////// EVENT LOOP //////
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed) window.close();
            if (event.type == Event::KeyPressed)
            {
                game.keyEvent(event);
            }
        }

        ////// UPDATE //////
        game.update([&window]()
        {
            std::cout << "VICTORY" << std::endl;
            window.close();
        }, [&window]()
        {
            std::cout << "GAME OVER" << std::endl;
            window.close();
        });

        ////// RENDER //////
        window.clear(Color(50, 50, 50));
        game.render();
        window.display();
    }
    return EXIT_SUCCESS;
}
