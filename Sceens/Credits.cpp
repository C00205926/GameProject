/// <summary>
/// Author Jake Comiskey
/// date December 2016
/// version 1
/// time taken 2hr 35mins
/// Outputs license splash and credits onto the screen.
/// </summary>
#include<iostream>
#include"Credits.h"
#include <fstream>

Credits::Credits(Game & game, sf::Font font) :
	m_game(&game),
	m_comicSans(font),
	m_textMessage("Credits: ", m_comicSans),
	m_credits("", m_comicSans)
{
	loadText();
	m_textMessage.setPosition(100.0f, 480.f);
	m_textMessage.setColor(sf::Color::White);
}

Credits::~Credits()
{
	std::cout << "destructing License" << std::endl;
}


/// <summary>
/// To load the text from the credits file
/// But cant seem to display it.
/// </summary>
void Credits::loadText()
{
	std::ifstream credits("credits.txt");

	for (int i = 0; !credits.eof(); i++)
	{
		std::string cred;
		
		std::getline(credits, cred);
		

		m_credits.setString(cred);
		m_credits.setColor(sf::Color::White);
		m_credits.setPosition(100.0f, 400.0f);
	}
	credits.close();
	
}

void Credits::update(sf::Time dt)
{
	m_cumulativeTime += dt;

	if (m_cumulativeTime.asSeconds() > 10)
	{
		m_game->setGameState(State::None);
	}
	m_textMessage.move(0, -2);
}

void Credits::render(sf::RenderWindow & window)
{
	window.clear(sf::Color::Black);
	window.draw(m_credits);
	window.draw(m_textMessage);
	window.display();
}