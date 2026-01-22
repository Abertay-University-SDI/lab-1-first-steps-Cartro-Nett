#include "Level.h"

Level::Level(sf::RenderWindow& hwnd, Input& in) :
	BaseLevel(hwnd, in)
{
	// initialise game objects
	//sf::CircleShape m_player;
	m_player.setRadius(10);
	m_player.setFillColor(sf::Color::Red);
	m_player.setPosition({ 300, 300 });
}

// handle user input
void Level::handleInput(float dt)
{
	if (m_input.isLeftMousePressed())
	{
		std::cout << "left mouse pressed" << std::endl;
	}
	if (m_input.isKeyDown(sf::Keyboard::Scancode::D))
	{
		m_directon = direction::RIGHT;
	}
	if (m_input.isKeyDown(sf::Keyboard::Scancode::A))
	{
		m_directon = direction::LEFT;
	}
	if (m_input.isKeyDown(sf::Keyboard::Scancode::W))
	{
		m_directon = direction::UP;
	}
	if (m_input.isKeyDown(sf::Keyboard::Scancode::S))
	{
		m_directon = direction::DOWN;
	}

}

// Update game objects
void Level::update(float dt)
{
	sf::Vector2f pos = m_player.getPosition();
	float radius = m_player.getRadius();
	sf::Vector2u window_size = m_window.getSize();
	if (pos.x > window_size.x - radius * 2 || pos.x < 0)
	{
		m_player.setPosition({ window_size.x * 0.5f, window_size.y * 0.5f });
	}
	if (pos.y > window_size.y - radius * 2 || pos.y < 0)
	{
		m_player.setPosition({ window_size.y * 0.5f, window_size.y * 0.5f });
	}
	switch (m_directon)
	{
	case Level::direction::UP:
		m_player.move({ 0.0f, dt * -m_speed });
		break;
	case Level::direction::DOWN:
		m_player.move({ 0.0f, dt * m_speed });
		break;
	case Level::direction::LEFT:
		m_player.move({ -m_speed * dt, 0.0f });
		break;
	case Level::direction::RIGHT:
		m_player.move({ m_speed * dt, 0.0f });
		break;
	default:
		break;
	}
}

// Render level
void Level::render()
{
	beginDraw();
	m_window.draw(m_player);
	endDraw();
}

