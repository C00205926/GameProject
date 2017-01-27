#include "Game.h"
#include <iostream>
#include <fstream>

Game::Game() :
	m_window(sf::VideoMode(800,480), "Credits"),
	m_currentState(State::License)
{
	if (!m_comicSans.loadFromFile("C:\\Windows\\Fonts\\comic.ttf"))
	{
		std::cout << "problem loading text" << std::endl;
	}
	m_licenseScreen = new License(*this, m_comicSans);
	m_splashScreen = new Splash(*this, m_comicSans);
	m_creditScreen = new Credits(*this, m_comicSans);
	
}

Game::~Game()
{
	delete(m_licenseScreen);
	delete(m_splashScreen);
	delete(m_creditScreen);
	std::cout << "destructing game" << std::endl;

}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);

	while (m_window.isOpen())
	{
		ProcessEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			Update(timePerFrame);
		}
		render();
	}
}

void Game::setGameState(State gameState)
{
	m_currentState = gameState;
}

void Game::Update(sf::Time time)
{
	switch (m_currentState)
	{
	case State::None:
		
		break;

	case State::License:
		m_licenseScreen->update(time);
	
		break;

	case State::Splash:
		ProcessEvents();
		m_splashScreen->update(time);
		break;

	case State::Credits:
		m_creditScreen->update(time);
		break;

	default:
		break;
	}
}

void Game::ProcessEvents()
{
	sf::Event event;

	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}
		if (event.type == sf::Event::KeyPressed && m_currentState == State::Splash)
		{
			m_splashScreen->getNextScreen();
		}
	}
}

void Game::render()
{
	switch (m_currentState)
	{
	case State::License:
		m_licenseScreen->render(m_window);
		break;
	case State::Splash:
		m_splashScreen->render(m_window);
		break;
	case State::Credits:
		m_creditScreen->render(m_window);
		break;
	default:
		m_window.clear(sf::Color::Blue);
		m_window.display();
		break;
	}
}