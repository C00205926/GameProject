#pragma once
#ifndef GAME
#define GAME

#include<SFML\Graphics.hpp>
#include"Splash.h"
#include "License.h"
#include"Credits.h"
class Splash;
class License;
class Credits;
enum class State
{
	None, 
	License,
	Splash,
	Credits
};


class Game
{
public:
	Game();
	void run();
	~Game();
	State m_currentState;
	void setGameState(State gameState);

private:
	void ProcessEvents();
	void Update(sf::Time);
	void render();

	sf::RenderWindow m_window;
	Splash *m_splashScreen;
	License *m_licenseScreen;
	Credits *m_creditScreen;
	sf::Font m_comicSans;
};

#endif