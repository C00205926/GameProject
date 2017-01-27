#include<iostream>
#include"License.h"

License::License(Game & game, sf::Font font) :
	m_game(&game),
	m_comicSans(font),
	m_textMessage("A GAME", m_comicSans),
	m_by("by", m_comicSans),
	m_name("Jake & Brendon", m_comicSans)
{
	m_textMessage.setPosition(-100, 180);
	m_textMessage.setColor(sf::Color::White);
	m_by.setPosition(-100, 220);
	m_by.setColor(sf::Color::White);
	m_name.setPosition(-100, 260);
	m_name.setColor(sf::Color::White);

	if (!cannonBall.loadFromFile("M:\\Sceens\\CannonBall.png"))
	{
		std::string s("Error Loading Texture");
		throw std::exception(s.c_str());
	}

	ballSprite.setTexture(cannonBall);
	ballSprite.setPosition(-99, -99);


}

License::~License()
{
	std::cout << "destructing License" << std::endl;
}

void License::update(sf::Time dt)
{
	m_cumulativeTime += dt;

	if ()
	{
		m_game->setGameState(State::Splash);
	}

	if (m_textMessage.getPosition().x < 400)
	{
		m_textMessage.move(15, 0);
	}

	if (m_by.getPosition().x < 400)
	{
		m_by.move(15, 0);
	}

	if (m_name.getPosition().x < 400)
	{
		m_name.move(15, 0);
	}

	if (m_cumulativeTime.asSeconds() >=1)
	{
		ballSprite.move(9, 5);
	}
	
	if (m_cumulativeTime.asSeconds() >= 1.6)
	{
		m_textMessage.move(30, -20);
		m_by.move(30, 20);
		m_name.move(-30, 20);
	}
}

void License::render(sf::RenderWindow & window)
{
	window.clear(sf::Color(13, 61, 255));
	window.draw(m_textMessage);
	window.draw(m_by);
	window.draw(ballSprite);
	window.draw(m_name);
	window.display();
}