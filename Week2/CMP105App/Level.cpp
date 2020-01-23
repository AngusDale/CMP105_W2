#include "Level.h"
#include <math.h> 

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	if (!font.loadFromFile("font/arial.ttf")) {
		std::cout << "Error loading font";
	}

	text.setFont(font);
	text.setCharacterSize(24);
	circle.setRadius(20);
	circle.setFillColor(sf::Color::Green);
}

Level::~Level()
{
	input = nullptr;
}

// handle user input
void Level::handleInput()
{
	if (input->isKeyDown(sf::Keyboard::W)) {
		input->setKeyUp(sf::Keyboard::W);
		std::cout << "W has been pressed\n";
	   }

	if (input->isKeyDown(sf::Keyboard::J) && input->isKeyDown(sf::Keyboard::K) && input->isKeyDown(sf::Keyboard::L)) {
		input->setKeyUp(sf::Keyboard::J);
		input->setKeyUp(sf::Keyboard::K);
		input->setKeyUp(sf::Keyboard::L);
		std::cout << "JKL was pressed\n";
	}

	if (input->isKeyDown(sf::Keyboard::Escape)) {
		input->setKeyUp(sf::Keyboard::Escape);
		window->close();
	}

	
	int mousex = input->getMouseX();
	int mousey = input->getMouseY();
	text.setString("Mouse: " + std::to_string(mousex) + " " + std::to_string(mousey));
	
	bool mouseLPressed = input->isMouseLDown();
	

	if (mouseLPressed) {
		if (once) {
			currentPosX = input->getMouseX();
			currentPosY = input->getMouseY();
			once = false;
		}
	}

	if (!mouseLPressed && !once) {
		endPosX = input->getMouseX();
		endPosY = input->getMouseY();

		int distanceX = endPosX - currentPosX;
		int distanceY = endPosY - currentPosY;

		float final = sqrt(pow(distanceX, 2) + pow(distanceY, 2));
		std::cout << final << std::endl;
		once = true;
	}

	
	if (input->isMouseRDown()) {
		//input->isMouseRDown(false);
		currentPosX = input->getMouseX();
		currentPosY = input->getMouseY();
		circle.setPosition(currentPosX, currentPosY);
	}
}

// Update game objects
void Level::update()
{

}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(text);
	window->draw(circle);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}