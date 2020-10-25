#include <SFML/Graphics.hpp>
#include "Game.h"

using namespace sf;
const int WIDTH = 640, HEIGHT = WIDTH;

int main() {
	RenderWindow window;
	window.create(VideoMode(WIDTH, HEIGHT), "Game of Life");

	Event e;
	Mouse m;

	Game game(20,WIDTH);
	bool start = 0;

	//Game loop
	while (window.isOpen()) {
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed) window.close();
			if (Event::KeyPressed) 	if (e.key.code == Keyboard::S) {
				if (start) start = 0; else start = 1;
			}
		}

		game.update(m,window, m.isButtonPressed(Mouse::Left), start);

		window.clear(Color::White);
		game.draw(window);

		window.display();

	}

	return 0;
}