#include "Hero.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

int main()
{
    // Create the main window
    Hero hero(150, 450);
    sf::RenderWindow window(sf::VideoMode(1300, 600), "GAMETIME!");

	// create an array of 3 vertices that define a triangle primitive
	sf::VertexArray quad(sf::Quads, 4);

	// define the position of the triangle's points
	quad[0].position = sf::Vector2f(0.f, 480.f);
	quad[1].position = sf::Vector2f(1300.f, 480.f);
	quad[3].position = sf::Vector2f(0.f, 600.f);
	quad[2].position = sf::Vector2f(1300.f, 600.f);

	// define the color of the triangle's points
	quad[0].color = sf::Color::Cyan;
	quad[1].color = sf::Color::Cyan;
	quad[2].color = sf::Color::Cyan;
	quad[3].color = sf::Color::Cyan;

	// no texture coordinates here, we'll see that later

    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }

        hero.update();

        window.clear();
        window.draw(hero);
        window.draw(quad);
        window.display();
    }

    return EXIT_SUCCESS;
}