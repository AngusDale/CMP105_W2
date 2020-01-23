#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string.h>
#include <iostream>


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();
	
	int currentPosX;
	int currentPosY;
	int endPosX;
	int endPosY;

	void handleInput();
	void update();
	void render();	
	
private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;

	// Add your object here
	sf::Text text;
	sf::Font font;
	sf::CircleShape circle;
	bool once = true;
};