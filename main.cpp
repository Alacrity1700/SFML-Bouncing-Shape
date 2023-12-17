#include <SFML/Graphics.hpp>
#include <Windows.h>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML Test Drawing");
    window.setFramerateLimit(144);
    
    sf::CircleShape shape(100.f);    //set circle radius
    shape.setFillColor(sf::Color::Magenta);
    sf::Vector2f shapePos(100, 100); //original position of shape
    shape.setPosition(shapePos);
    float velocityX = 3, velocityY = 3; 


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (GetAsyncKeyState(VK_DELETE)) window.close();
        }


        //shape movement
        if (shapePos.x < 0 || shapePos.x > 1280 - 200) velocityX *= -1; 
        if (shapePos.y < 0 || shapePos.y > 720 - 200) velocityY *= -1;
        shapePos.x += velocityX;
        shapePos.y += velocityY;
        shape.setPosition(shapePos);
        
        //drawing window
        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
