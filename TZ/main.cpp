#include <SFML/Graphics.hpp>
#include "Classes.h"
#include "Functions.h"

#include <iostream>

using namespace sf;

RenderWindow window(VideoMode(800, 800), "Game");
Map element;

void show_map();
void show_text();
void show_win();

int main()
{
	int win = 0;

	Vector2i pixelPos;
	Vector2i pixelPosFinish;
	// collect chosen element of massive
	div_t x_position;
	div_t y_position;
	// which side element moved
	int dx = 0;
	int dy = 0;

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			// if mouse button pressed and pressed left mouse
			if (event.type == Event::MouseButtonPressed && event.key.code == Mouse::Left && win == 0)
			{
				pixelPos = Mouse::getPosition(window);
				// which element was chosen
				x_position = div(pixelPos.x, 100);
				y_position = div(pixelPos.y, 100);
				if (pixelPos.x - x_position.quot * 100 <= 10)
					--x_position.quot;
				if (pixelPos.y - y_position.quot * 100 <= 40)
					--y_position.quot;
			}
			if (event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left && win == 0)
			{
				pixelPosFinish = Mouse::getPosition(window);
				// update for coordinates
				dx = pixelPos.x - pixelPosFinish.x;
				dy = pixelPos.y - pixelPosFinish.y;
				move(&element, y_position.quot, x_position.quot, dx, dy);
				show_matrix(element);
			}
		}
		window.clear();

		show_map();
		show_text();

		// if no equal collons
		if (win_check(&element))
		{
			show_win();
			win = 1;
		}

		window.display();
	}

	return 0;
}

void show_map() // show the game map from massive
{
	// local variables for different sizes of images
	Image image;
	Texture texture;
	Sprite sprite;

	// running in massive
	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			// digits equals colors of elements
			switch (element.get_elem(i, j))
			{
			case 4:
			{
				image.loadFromFile("Images/Blocked_elem.png");
				break;
			}
			case 0:
			{
				image.loadFromFile("Images/Free_elem.png");
				break;
			}
			case 1:
			{
				image.loadFromFile("Images/Red_elem.png");
				break;
			}
			case 2:
			{
				image.loadFromFile("Images/Blue_elem.png");
				break;
			}
			case 3:
			{
				image.loadFromFile("Images/Green_elem.png");
				break;
			}
			default:
				break;
			}
			// create sprite from image for drawing in window
			texture.loadFromImage(image);
			sprite.setTexture(texture);
			sprite.setPosition((float)element.get_x_position(), (float)element.get_y_position());
			window.draw(sprite);
			// change x position for next element
			element.set_x_position(element.get_x_position() + 100);
		}
		// back to started x coordinate and up y coordinate
		element.set_x_position(10);
		if (i == 0)
			element.set_y_position(element.get_y_position() + 130);
		else
			element.set_y_position(element.get_y_position() + 100);
	}
	// back to start y coordinate for new drawing
	element.set_y_position(10);
}

void show_text() // show text for help
{
	// local variables for different sizes of images
	Image image;
	Texture texture;
	Sprite sprite;
	// create color, type and size of text
	Font font;
	font.loadFromFile("CyrilicOld.ttf");
	Text text("", font, 20);
	text.setFillColor(Color::White);

	//select position for colored block
	element.set_x_position(550);
	element.set_y_position(10);

	// create and draw colored block
	image.loadFromFile("Images/Little_red.png");
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setPosition((float)element.get_x_position(), (float)element.get_y_position());
	window.draw(sprite);

	// change x position for drawing text
	element.set_x_position(element.get_x_position() + 20);

	//drawing text
	text.setString(" - Element number 1");
	text.setPosition((float)element.get_x_position(), (float)element.get_y_position());
	window.draw(text);

	// later we do it again, but y coordinate is up
	element.set_x_position(550);
	element.set_y_position(40);

	image.loadFromFile("Images/Little_blue.png");
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setPosition((float)element.get_x_position(), (float)element.get_y_position());
	window.draw(sprite);

	element.set_x_position(element.get_x_position() + 20);

	text.setString(" - Element number 2");
	text.setPosition((float)element.get_x_position(), (float)element.get_y_position());
	window.draw(text);


	element.set_x_position(550);
	element.set_y_position(70);

	image.loadFromFile("Images/Little_green.png");
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setPosition((float)element.get_x_position(), (float)element.get_y_position());
	window.draw(sprite);

	element.set_x_position(element.get_x_position() + 20);

	text.setString(" - Element number 3");
	text.setPosition((float)element.get_x_position(), (float)element.get_y_position());
	window.draw(text);


	element.set_x_position(550);
	element.set_y_position(100);

	image.loadFromFile("Images/Little_white.png");
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setPosition((float)element.get_x_position(), (float)element.get_y_position());
	window.draw(sprite);

	element.set_x_position(element.get_x_position() + 20);

	text.setString(" - Free position");
	text.setPosition((float)element.get_x_position(), (float)element.get_y_position());
	window.draw(text);


	element.set_x_position(550);
	element.set_y_position(130);

	image.loadFromFile("Images/Little_blocked.png");
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setPosition((float)element.get_x_position(), (float)element.get_y_position());
	window.draw(sprite);

	element.set_x_position(element.get_x_position() + 20);

	text.setString(" - Blocked position");
	text.setPosition((float)element.get_x_position(), (float)element.get_y_position());
	window.draw(text);

	element.set_x_position(10);
	element.set_y_position(10);
}

void show_win()
{
	Font font;
	font.loadFromFile("CyrilicOld.ttf");
	Text text("", font, 40);
	text.setFillColor(Color::White);

	element.set_x_position(550);
	element.set_y_position(200);

	text.setString("You Win!");
	text.setPosition((float)element.get_x_position(), (float)element.get_y_position());
	window.draw(text);

	element.set_x_position(10);
	element.set_y_position(10);
}