#ifndef SIMUL_CPP
#define SIMUL_CPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include "particle.cpp"
#include "control.cpp"
using namespace sf;
using namespace std;

class SimulationWindow : public RenderWindow {
	vector<Particle> particles;
	ControlWindow& control;

public:
	SimulationWindow(ControlWindow& ctrlwin, ContextSettings settings) :
		RenderWindow(VideoMode(1200, 800), "Particle Simulation", Style::Close, settings),
		control(ctrlwin) {
		setPosition(Vector2i(100,100));
		setFramerateLimit(60);
	}

	void handleEvents() {
		static random_device rd;
		static mt19937 gen(rd());
		static uniform_int_distribution<> colorDist(0,255);

		Event event;
		static Vector2i pressPosition, releasePosition, positionDiff;
		while (pollEvent(event)) {
			if (event.type == Event::Closed)
				close();
		 	if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
				pressPosition = Mouse::getPosition(*this);
				cout << "handleEvents: left click at (" << pressPosition.x << ", " << pressPosition.y << ")\n";
			}
			if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left) {
				releasePosition = Mouse::getPosition(*this);
				positionDiff = pressPosition - releasePosition;
				particles.push_back(Particle(releasePosition, positionDiff, Color(colorDist(gen), colorDist(gen), colorDist(gen))));
			}
			if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Right) {
				pressPosition = Mouse::getPosition(*this);
				cout << "handleEvents: right click at (" << pressPosition.x << ", " << pressPosition.y << ")\n";
				for (auto p = particles.begin(); p != particles.end(); p++) {
					if (p->getGlobalBounds().contains(pressPosition.x, pressPosition.y)) {
						particles.erase(p);
						break;
					}
				}
			}
		}
	}

	void clearAndDisplay() {
		clear();
		for (Particle& particle : particles) {
			particle.update(control.getSpeed(), getSize());
			draw(particle);
		}
		display();
	}
};

#endif /* SIMUL_CPP */
