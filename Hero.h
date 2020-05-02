#ifndef HERO_H
#define HERO_H
#include <SFML/Graphics.hpp>
#include <iostream>

class Hero : public sf::Drawable {
public:
	Hero(float t_X, float t_Y);
	Hero() = delete;
	~Hero() = default;

	void update();

	float left();
	float right();
	float top();
	float bottom();

	void moveJump();

	sf::Vector2f getPosition();

private:
	sf::RectangleShape shape;
	float heroWidth = 40;
	float heroHeight = 60;
	const float heroVelocity = 0.25f;
	sf::Vector2f velocity { heroVelocity, 0};

	sf::Texture texture;
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
};

#endif