#include"Splash.h"
#include<iostream>

Splash::Splash(Game & game, sf::Font font) :
	m_game(&game),
	m_comicSans(font),
	m_textMessage("Pess Any Button, cuz", m_comicSans)
{
	m_textMessage.setPosition(500.0f, 400.f);
	m_textMessage.setColor(sf::Color::Black);

	if (!m_texture.loadFromFile("M:\\Sceens\\Yurt.jpg"))
	{
		std::string s("Error Loading Texture");
		throw std::exception(s.c_str());
	}
	alpha = 0;
	m_sprite.setTexture(m_texture);
}

Splash::~Splash()
{
	std::cout << "destructing splash" << std::endl;
}

void Splash::update(sf::Time dt)
{
	if (alpha < 255)
	{
		alpha ++;
		m_sprite.setColor(sf::Color(255, 255, 255, alpha));
	}

	m_cumulativeTime += dt;
}

void Splash::getNextScreen()
{
	m_game->setGameState(State::Credits);
}

void Splash::render(sf::RenderWindow & window)
{
	window.clear(sf::Color::Black);
	if (alpha > 0)
	{
		window.draw(m_sprite);
	}
	window.draw(m_textMessage);
	window.display();
}