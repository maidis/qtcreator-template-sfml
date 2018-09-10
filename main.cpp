#include <SFML/Graphics.hpp>

// The frequency at which our update step will execute
#define UPDATE_RATE 1.0f / 60.0f


int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 768), "%{ProjectName}", sf::Style::Close);

    // This forces our window to draw at refresh rate of the monitor
    // Uncomment the line below to check out the fps counter
    //window.setVerticalSyncEnabled(true);

    sf::RectangleShape player(sf::Vector2f(50.0f, 50.0f));
    player.setOrigin(player.getSize().x / 2, player.getSize().y / 2);
    player.setPosition(window.getSize().x / 2, window.getSize().y /2);
    player.setFillColor(sf::Color::Green);

    // The sf::Clock class will allow us to keep track of time
    sf::Clock clock;
    // This variable accumulates the time spent during render steps
    float total_time = 0.0f;
    // This variable holds the amount of time the last render step took
    float frame_time = 0.0f;
    // This variable keeps track of how many times the update step ran
    int update_limit = 0;


    while(window.isOpen())
    {
        // Get how long it took to draw the last frame
        frame_time = clock.restart().asSeconds();
        // Add that time to the total time
        total_time += frame_time;
        // Reset our counter
        update_limit = 0;

        // While the total amount of time spend on the render step is
        // greater or equal to the update rate (1/60) and we have
        // not executed the update step 10 times then do the loop
        // If the counter hits 10 we break because it means that the 
        // render step is lagging behind the update step
        while(total_time >= UPDATE_RATE && update_limit < 10)
        {
            sf::Event evt;

            while(window.pollEvent(evt))
            {
                if(evt.type == sf::Event::Closed)
                    window.close();
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                player.move(0.0f, -5.0f);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                player.move(0.0f, 5.0f);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                player.move(-5.0f, 0.0f);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                player.move(5.0f, 0.0f);

            player.rotate(1.0f);

            // Subtract the udpate frequency from the total time
            total_time -= UPDATE_RATE;
            // Increase the counter
            update_limit++;
        }

        window.clear();
        window.draw(player);
        window.display();
    }

    return 0;
}
