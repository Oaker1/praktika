#include <SFML/Graphics.hpp>


//Press S to start, press F to stop.


using namespace sf;

int main()
{
	RenderWindow window(VideoMode(800, 700), "SFML Test");
	bool condition = false, moving = true;
	float width = 200, h = 250;
	while (window.isOpen())
	{	Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::S)
					condition = true;
				if (event.key.code == sf::Keyboard::F)
					
					condition = false;
			}
		}
		if (condition) 
		{
			if (width < 100)
			{
				moving = false;
			}
			if (width > 250)
			{
				moving = true;
			}
			if (moving) 
			{
				width -= 0.1;
				h += 0.2;
			}
			else 
			{
				width += 0.1;
				h -= 0.2;
			}
		}
		window.clear();
		RectangleShape rectangle(Vector2f(200.f, h));
		rectangle.move(200, width);
		rectangle.setFillColor(Color::Green);
		window.draw(rectangle);
		window.display();
	}
	return 0;
}
