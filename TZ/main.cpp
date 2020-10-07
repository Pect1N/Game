#include <SFML/Graphics.hpp>
#include "Classes.h"
#include "Functions.h"

using namespace sf;

RenderWindow window(VideoMode(800, 800), "Game");
Map element;

void show_map();
void show_text();

int main()
{
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		window.clear();
		show_map();
		show_text();
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
			case -1:
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
			sprite.setPosition(element.get_x_position(), element.get_y_position());
			window.draw(sprite);
			// change x position for next element
			element.set_x_position(element.get_x_position() + 100);
		}
		// back to started x coordinate and up y coordinate
		element.set_x_position(10);
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
	sprite.setPosition(element.get_x_position(), element.get_y_position());
	window.draw(sprite);

	// change x position for drawing text
	element.set_x_position(element.get_x_position() + 20);

	//drawing text
	text.setString(" - Element number 1");
	text.setPosition(element.get_x_position(), element.get_y_position());
	window.draw(text);

	// later we do it again, but y coordinate is up
	element.set_x_position(550);
	element.set_y_position(40);

	image.loadFromFile("Images/Little_blue.png");
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setPosition(element.get_x_position(), element.get_y_position());
	window.draw(sprite);

	element.set_x_position(element.get_x_position() + 20);

	text.setString(" - Element number 2");
	text.setPosition(element.get_x_position(), element.get_y_position());
	window.draw(text);


	element.set_x_position(550);
	element.set_y_position(70);

	image.loadFromFile("Images/Little_green.png");
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setPosition(element.get_x_position(), element.get_y_position());
	window.draw(sprite);

	element.set_x_position(element.get_x_position() + 20);

	text.setString(" - Element number 3");
	text.setPosition(element.get_x_position(), element.get_y_position());
	window.draw(text);


	element.set_x_position(550);
	element.set_y_position(100);

	image.loadFromFile("Images/Little_white.png");
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setPosition(element.get_x_position(), element.get_y_position());
	window.draw(sprite);

	element.set_x_position(element.get_x_position() + 20);

	text.setString(" - Free position");
	text.setPosition(element.get_x_position(), element.get_y_position());
	window.draw(text);


	element.set_x_position(550);
	element.set_y_position(130);

	image.loadFromFile("Images/Little_blocked.png");
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setPosition(element.get_x_position(), element.get_y_position());
	window.draw(sprite);

	element.set_x_position(element.get_x_position() + 20);

	text.setString(" - Blocked position");
	text.setPosition(element.get_x_position(), element.get_y_position());
	window.draw(text);

	element.set_x_position(10);
	element.set_y_position(10);
}