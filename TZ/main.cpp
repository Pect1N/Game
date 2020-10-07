#include <SFML/Graphics.hpp>
#include "Classes.h"
#include "Functions.h"

using namespace sf;

RenderWindow window(VideoMode(800, 800), "SFML Works!");
Image image;
Texture texture;
Sprite sprite;
Map element;

void show();

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
		show();
		window.display();
	}

	return 0;
}

void show()
{
	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
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
			texture.loadFromImage(image);
			sprite.setTexture(texture);
			sprite.setPosition(element.get_x_position(), element.get_y_position());
			window.draw(sprite);
			element.set_x_position(element.get_x_position() + 100);
		}
		element.set_x_position(10);
		element.set_y_position(element.get_y_position() + 100);
		if(i == 5)
			element.set_y_position(10);
	}
}