#include "Level.h"

Level::Level(sf::RenderWindow* hwnd)
{
	window = hwnd;

	if (!font.loadFromFile("font/arial.ttf")) {
		std::cout << "Couldn't load font from file\n";
	}

	text.setFont(font);
	text.setString("Hello world");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);
	text.setPosition(sf::Vector2f(window->getSize().x / 2 - text.getLocalBounds().width/2, 10));

	int size=0;
	for (int i = 0; i < 3; i++) {
		size = 30 * (i + 1);
		rect[i].setSize(sf::Vector2f(size, size));
		rect[i].setPosition(window->getSize().x / 2 - size / 2, window->getSize().y / 2 - size / 2);
	}

	rect[2].setFillColor(sf::Color::Red);
	rect[1].setFillColor(sf::Color::Green);
	rect[0].setFillColor(sf::Color::Blue);

	resizeRect.setSize(sf::Vector2f(40, 40));
	resizeRect.setFillColor(sf::Color::Green);

	circle.setRadius(50);
	circle.setPosition(window->getSize().x/2 - 50, window->getSize().y/2 - 50);
	circle.setFillColor(sf::Color::Blue);
	circle.setOutlineColor(sf::Color::Red);
}

Level::~Level()
{
}

// handle user input
void Level::handleInput()
{

}

// Update game objects
void Level::update()
{
	resizeRect.setPosition(sf::Vector2f(window->getSize().x - 40, window->getSize().y - 40));
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(circle);
		
	for (int i = 2; i >= 0; i--) {
		window->draw(rect[i]);
	}

	window->draw(resizeRect);

	window->draw(text);

	endDraw();
}

void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}