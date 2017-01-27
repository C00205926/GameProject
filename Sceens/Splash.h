#pragma once
#ifndef SPLASH
#define SPLASH

#include<SFML\Graphics.hpp>
#include"Game.h"

class Game;

class Splash
{
public:
	Splash(Game& game, sf::Font font);
	~Splash();
	void update(sf::Time dt);
	void getNextScreen();
	void render(sf::RenderWindow& window);
private:
	Game *m_game;
	sf::Time m_cumulativeTime;
	sf::Font m_comicSans;
	sf::Text m_textMessage;
	int alpha;
	sf::Sprite m_sprite;
	sf::Texture m_texture;
};

#endif // !SPLASH