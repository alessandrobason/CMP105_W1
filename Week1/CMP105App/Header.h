#pragma once

#include <SFML/Graphics.hpp>
#include <string.h>
#include <iostream>


class Rectangle {
public:
	Rectangle(sf::RenderWindow* hwnd);
	~Rectangle();

private:
	sf::RenderWindow* window;

	sf::RectangleShape rect;
	sf::CircleShape circle;
};