#pragma once

#include "Framework/BaseLevel.h"

class Level : BaseLevel{
public:
	Level(sf::RenderWindow& window, Input& input);
	~Level() override = default;

	void handleInput(float dt) override;
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	float m_speed = 200.f;
	// Default variables for level class.
	sf::CircleShape m_player;
private:
	enum class direction{UP, DOWN, LEFT, RIGHT};
	direction m_directon;
};