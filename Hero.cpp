#include "Hero.h"

Hero::Hero(float t_X, float t_Y) {

	if(!texture.loadFromFile("hero.jpg")) {
		std::cout << "ERROR";
	}

	//Hero properties
	shape.setSize(sf::Vector2f(this->heroWidth, this->heroHeight));
	shape.setPosition(sf::Vector2f(t_X, t_Y));
	shape.setOrigin(sf::Vector2f(heroWidth/2.f, heroHeight/2.f));
	shape.setTexture(&texture);
}

void Hero::draw(sf::RenderTarget& target, sf::RenderStates state) const {
	target.draw(this->shape, state);
}

void Hero::update() {
	this->shape.move(this->velocity);
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && this->left()>0) {
		velocity.x = -heroVelocity;
	} else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && this->right() < 1300) {
		velocity.x = heroVelocity;
	} else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && this->shape.getPosition().y > 400){
		velocity.y = -heroVelocity;
	} else if (this->shape.getPosition().y < 450)  {
		velocity.y = heroVelocity;
	} else {
		velocity.x = 0;
		velocity.y = 0;
	}
}

void Hero::moveJump() {
	
}

sf::Vector2f Hero::getPosition() {
	return shape.getPosition();
}

float Hero::left() {
	return this->shape.getPosition().x - shape.getSize().x/2.f;
}
float Hero::right() {
	return this->shape.getPosition().x + shape.getSize().x/2.f;
}
float Hero::top() {
	return this->shape.getPosition().y + shape.getSize().y/2.0;
}
float Hero::bottom() {
	return this->shape.getPosition().y - shape.getSize().y/2.0;
}