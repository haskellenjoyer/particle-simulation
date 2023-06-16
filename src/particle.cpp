#ifndef PARTICLE_CPP
#define PARTICLE_CPP

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

class Particle : public CircleShape {
	static const int radius = 15;
	static const int maxVel = 20;
	Vector2i velocity;

public:
	Particle(Vector2i position, Vector2i v, Color color = Color::White) :
		CircleShape(radius), velocity(v) {
		setPosition(position.x, position.y);
		setFillColor(color);
		if (velocity.x > maxVel) velocity.x = maxVel;
		if (velocity.x < -maxVel) velocity.x = -maxVel;
		if (velocity.y > maxVel) velocity.y = maxVel;
		if (velocity.y < -maxVel) velocity.y = -maxVel;
		std::cout << "Particle generated at (" << getPosition().x << ", " << getPosition().y << ")\n";
	}

	void update(float speed, Vector2u windowSize) {
		move(speed*velocity.x, speed*velocity.y);
		// Bounce off the window edges
		Vector2f position = getPosition();
		if (position.x < 0) {
			position.x = 0;
			velocity.x *= -1;
		}
		if (position.x > windowSize.x - 2*radius) {
			position.x = windowSize.x - 2*radius;
			velocity.x *= -1;
		}
		if (position.y < 0) {
			position.y = 0;
			velocity.y *= -1;
		}
		if (position.y > windowSize.y - 2*radius) {
			position.y = windowSize.y - 2*radius;
			velocity.y *= -1;
		}
		setPosition(position);
	}

	void setSpeed(float speed) {
		velocity = Vector2i(speed, speed);
	}
};

#endif /* PARTICLE_CPP */
