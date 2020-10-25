#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>

using namespace sf;

enum class State{
	dead,
	alive
};

class Game {
public:
	Game(int size, int width) : size(size), width(width) {
		field.resize(size * size);
		for (int i = 0; i < field.size(); i++) field[i] = State::dead;

		field[23] = State::alive;
		box.setSize(Vector2f(width / size, width / size));
		box.setFillColor(Color::Black);
		length = width / size;
	}


	void draw(RenderWindow& window);
	void update(Mouse& m, RenderWindow& window, bool draw = 0, bool start = 0);

	bool start = 0;
	std::vector<State> field, newField;
	int size = 0, length = 0, width = 0;
	RectangleShape box;
};
