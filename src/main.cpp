#include <SFML/Graphics.hpp>
#include "control.cpp"
#include "simul.cpp"
#include "particle.cpp"

int main() {
	ControlWindow ctrlWindow;
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	SimulationWindow simWindow(ctrlWindow, settings);

	while (simWindow.isOpen() && ctrlWindow.isOpen()) {
		ctrlWindow.handleEvents();
		ctrlWindow.clearAndDisplay();

		simWindow.handleEvents();
		simWindow.clearAndDisplay();
	}
}
