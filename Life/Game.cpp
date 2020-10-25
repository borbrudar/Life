#include "Game.h"

void Game::draw(RenderWindow& window)
{
	for (int i = 0; i < field.size(); i++) {
		if (field[i] == State::alive) {
			box.setPosition(i % size * length, std::floor(i / size) * length);
			window.draw(box);
		}
	}
}

void Game::update(Mouse& m, RenderWindow& window, bool draw, bool start)
{
	
	//update
	if (start) {
		newField.resize(field.size());

		for (int i = 0; i < field.size(); i++) {
			//determined state of neighbours
			State neigh[4] = { State::dead,State::dead,  State::dead,  State::dead };
			if((i - 1) > 0) neigh[0] = field[i - 1];//left
			if ((i + 1) < size) neigh[1] = field[i + 1];//right
			if ((i - size) > 0) neigh[2] = field[i - size];//up
			if ((i + size) <= (size*size - size)) neigh[3] = field[i + size];//down
		
			//count how many are alive
			int count = 0;
			for (int j = 0; j < 4; j++) {
				if (neigh[j] == State::alive) count++;
			}

			//determine the new cell
			switch (count) {
			case 2:
				newField[i] = field[i];
				break;
			case 3:
				newField[i] = State::alive;
				break;
			default:
				newField[i] = State::dead;
				break;
			}
			
		}

		field = newField;
	}
	//check if out of bounds and draw
	else {
		Vector2i pos = m.getPosition(window);
		bool isOut = (pos.x >= width) || (pos.x <= 0) || (pos.y <= 0) || (pos.y >= width);
		if (draw && !isOut)
			field[floor(pos.x / length) + floor(pos.y / length) * size] = State::alive;

	}
}
