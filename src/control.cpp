#ifndef CONTROL_CPP
#define CONTROL_CPP

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

class ControlWindow {
	RenderWindow window;
	RectangleShape slider;
	RectangleShape sliderValue;
	Font font;
	Text text;
	bool isSliderPressed = false;

	void updateSliderValue(int mouseX) {
		if (mouseX < slider.getPosition().x) mouseX = slider.getPosition().x;
		if (mouseX > slider.getPosition().x + slider.getSize().x)
			mouseX = slider.getPosition().x + slider.getSize().x;
		sliderValue.setSize(Vector2f(mouseX - sliderValue.getPosition().x, 20));
	}

public:
	ControlWindow() :
		window(VideoMode(300, 180), "Control Window", Style::Close),
		slider(Vector2f(200, 20)),
		sliderValue(Vector2f(100, 20)) {
		window.setPosition(Vector2i(1320,300));
		window.setFramerateLimit(30);
		slider.setPosition(50, 100);
		slider.setFillColor(Color::White);
		sliderValue.setPosition(50, 100);
		sliderValue.setFillColor(Color::Green);
		text.setString("Speed Slider");
		text.setCharacterSize(20);
		text.setFillColor(Color::White);
		text.setPosition(90, 40);
		if (!font.loadFromFile("DejaVuSans.ttf")) {
			std::cerr << "Error: could not load font";
			exit(1);
		}
		text.setFont(font);
	}

	void clearAndDisplay() {
		window.clear();
		window.draw(slider);
		window.draw(sliderValue);
		window.draw(text);
		window.display();
	}

	bool isOpen() {
		return window.isOpen();
	}

	void handleEvents() {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
				isSliderPressed = true;
				updateSliderValue(event.mouseButton.x);
			}
			if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left) {
				isSliderPressed = false;
			}
			if (event.type == Event::MouseMoved && isSliderPressed) {
				updateSliderValue(event.mouseMove.x);
			}
		}
	}

	float getSpeed() {
		return sliderValue.getSize().x / 200;
	}
};

#endif /* CONTROL_CPP */
