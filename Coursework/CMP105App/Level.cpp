#include "Level.h"

Level::Level(sf::RenderWindow& hwnd, Input& in) :
	BaseLevel(hwnd, in)
{
	// initialise game objects
	//sf::CircleShape m_player;
	m_player.setRadius(10);
	m_player.setFillColor(sf::Color::Red);
	m_player.setPosition({ 300, 300 });
	// set food up
	m_food.setRadius(5.f);
	m_food.setFillColor(sf::Color::Green);
	spawnFood();

}
void Level::spawnFood()
{
	float x = rand() % m_window.getSize().x;
	float y = rand() % m_window.getSize().y;
	m_food.setPosition({ x, y });
	
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
	if (m_IsGameOver == true)
	{
		return;
	}
	if (m_IsGameOver == false)
	{
	
	}
	
	sf::Vector2f pos = m_player.getPosition();
	float radius = m_player.getRadius();
	sf::Vector2u window_size = m_window.getSize();
	if (pos.x > window_size.x - radius * 2 || pos.x < 0)
	{
		m_player.setPosition({ window_size.x * 0.1f, window_size.y * 0.5f });
		std::cout << "Game Over!";
		std::cout << "\nYour Score is: " << m_score;
		m_IsGameOver = true;
	}
	if (pos.y > window_size.y - radius * 2 || pos.y < 0)
	{
		m_player.setPosition({ window_size.y * 0.1f, window_size.y * 0.5f });
		std::cout << "Game Over!";
		std::cout << m_score;
		m_IsGameOver = true;

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
	float x_distance = (pos.x + radius) - (m_food.getPosition().x + m_food.getRadius());
	float y_distance = (pos.y + radius) - (m_food.getPosition().y + m_food.getRadius());
	float total_distance = (x_distance * x_distance) + (y_distance * y_distance);
	float radius_sum = radius + m_food.getRadius();
	if (total_distance < radius_sum * radius_sum)
	{
		spawnFood();
		m_speed *= 1.1f;
		m_score += 1;
	}

}

// Render level
void Level::render()
{
	
	beginDraw();
	m_window.draw(m_food);
	m_window.draw(m_player);
	endDraw();
}

