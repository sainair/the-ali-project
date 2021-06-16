#include "includes/Loader.h"
#include "includes/Helpers.h"

int main()
{
    sf::RenderWindow window = sf::RenderWindow(sf::VideoMode(800,600),"ALI");

    sf::Image image = loadImage("src/util/rich_boi.jpg");

    sf::Texture texture = getTexture(image);
    texture.setSmooth(true);

    sf::Sprite ali(texture);
    ali.setScale({ali.getScale().x+5, ali.getScale().y+5});
    ali.setOrigin({ali.getPosition().x-25, ali.getPosition().y-10});

    sf::RectangleShape mb1 = createRect(sf::Color(0,0,0), 100, 50, -350, -200);
    sf::RectangleShape mb2 = createRect(sf::Color(0,0,0), 100, 50, -350, -300);
    sf::RectangleShape mb3 = createRect(sf::Color(0,0,0), 100, 50, -350, -400);

    sf::RectangleShape backbutton = createRect(sf::Color(0,0,0), 50.0f, 50.0f);

    sf::Font aliFont = loadFont("src/util/OpenSans-Regular.ttf");

    sf::Text text;
    text.setFont(aliFont);
    text.setString("Look at ALI!!!!");
    text.setOrigin({mb1.getPosition().x-700, mb1.getPosition().y-430});
    text.setFillColor(sf::Color::Cyan);
    text.setScale(text.getScale().x-0.5, text.getScale().y-0.5);
    
    sf::Text useless;
    useless.setFont(aliFont);
    useless.setScale({useless.getScale().x-0.5f, useless.getScale().y-0.5f});
    useless.setPosition({text.getPosition().x+370, text.getPosition().y+315});
    useless.setString("Credits");
    useless.setFillColor(sf::Color::Cyan);

    sf::Text quit;
    quit.setFont(aliFont);
    quit.setScale({quit.getScale().x-0.5f, quit.getScale().y-0.5f});
    quit.setPosition({useless.getPosition().x+10, useless.getPosition().y+100});
    quit.setString("Quit");
    quit.setFillColor(sf::Color::Cyan);

    sf::Text back;
    back.setFont(aliFont);
    back.setFillColor(sf::Color::Cyan);
    back.setScale({back.getScale().x, back.getScale().y});
    back.setString("<");
    back.setPosition({back.getPosition().x+10,0});

    sf::Text Credits;
    Credits.setFillColor(sf::Color::Cyan);
    Credits.setFont(aliFont);
    Credits.setString("Credits: \n Sai Nair for development of the app \n Sai Nair for the graphics \n SFML for their wonderful library \n Ali Absolute on youtube for the picture");
    Credits.setOrigin({Credits.getPosition().x-150, Credits.getPosition().y-150});

    if(!texture.loadFromFile("src/util/rich_boi.jpg"))
    {
        std::cout<<"No texture\n";
    }

    sf::Sprite sprite(texture);
    sprite.scale({8, 7.5});
    sprite.setOrigin({-150, sprite.getPosition().y});

    bool mainmenu = true;
    bool credits =false;

    while(window.isOpen())
    {
        sf::Event e;
        while(window.pollEvent(e))
        {
            sf::Vector2i mpos = sf::Mouse::getPosition(window);
            if(e.type==sf::Event::Closed)
            {
                window.close();
            }
            if(mb1.getGlobalBounds().contains(mpos.x, mpos.y))
            {
                mb1.setFillColor(sf::Color(150,150,150));
            }else{
                mb1.setFillColor(sf::Color::Black);
            }if(mb2.getGlobalBounds().contains(mpos.x, mpos.y))
            {
                mb2.setFillColor(sf::Color(150,150,150));
            }else{
                mb2.setFillColor(sf::Color(0,0,0));
            }if(mb3.getGlobalBounds().contains(mpos.x, mpos.y))
            {
                mb3.setFillColor(sf::Color(150,150,150));
            }else{
                mb3.setFillColor(sf::Color(0,0,0));
            }if(backbutton.getGlobalBounds().contains(mpos.x, mpos.y))
            {
                backbutton.setFillColor(sf::Color(150,150,150));
            }else{
                backbutton.setFillColor(sf::Color::Black);
            }
            if(e.type==sf::Event::MouseButtonPressed)
            {
                if(e.mouseButton.button == sf::Mouse::Left)
                {
                    if(mb3.getGlobalBounds().contains(mpos.x, mpos.y))
                    {
                        window.close();
                    }else if(mb1.getGlobalBounds().contains(mpos.x, mpos.y))
                    {
                        mainmenu=false;
                        credits=false;
                    }else if(backbutton.getGlobalBounds().contains(mpos.x, mpos.y))
                    {
                        mainmenu=true;
                        credits=false;
                    }else if(useless.getGlobalBounds().contains(mpos.x, mpos.y))
                    {
                        mainmenu=false;
                        credits=true;
                    }
                }
            }
        }
        if(mainmenu==true && credits==false)
        {
            window.setFramerateLimit(10);
        
            window.clear(sf::Color(100,100,100));
            window.draw(mb1);
            window.draw(mb2);
            window.draw(mb3);
            window.draw(text);
            window.draw(text);
            window.draw(useless);
            window.draw(quit);
            window.display();
        }else if(mainmenu==false && credits==true)
        {
            window.clear(sf::Color(150,150,150));
            window.draw(Credits);
            window.draw(backbutton);
            window.draw(back);
            window.display();
        }
        else if(mainmenu==false && credits==false)
        {
            window.clear(sf::Color(100,100,100));
            window.draw(backbutton);
            window.draw(back);
            window.draw(ali);
            window.display();
        }
        
    }
}