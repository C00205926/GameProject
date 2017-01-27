#pragma once
#ifndef CREDITS
#define CREDITS

#include<SFML\Graphics.hpp>
#include"Game.h"

class Game;

class Credits
{
public:
	Credits(Game& game, sf::Font font);
	~Credits();
	void update(sf::Time dt);
	void render(sf::RenderWindow& window);
	void loadText();
private:
	Game *m_game;
	sf::Time m_cumulativeTime;
	sf::Font m_comicSans;
	sf::Text m_textMessage;
	sf::Text m_credits;
};

#endif // !Credits