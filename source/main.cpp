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

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.display();
    }
    return EXIT_SUCCESS;
}
