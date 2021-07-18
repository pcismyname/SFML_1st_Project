#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

int ball();

int main()
{
   sf::RenderWindow window(sf::VideoMode(400,400),"IT's Work");
   sf::CircleShape shape1(100.f);
   sf::CircleShape shape2(50.f);
   sf::CircleShape shape3(150.f);

   shape1.setFillColor(sf::Color::Green);
   shape2.setFillColor(sf::Color::Red);
   shape3.setFillColor(sf::Color::Blue);

   while (window.isOpen())
   {
       sf::Event event;
       while( window.pollEvent(event))
       {
           if (event.type == sf::Event::Closed)
            window.close();
       }
       window.clear();
       window.draw(shape1);
       window.draw(shape2);
       window.draw(shape3);
       window.display();
    }
}
