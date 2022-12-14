#include <SFML/Graphics.hpp>

#include <array>
#include <format>
#include <iostream>

#include "utils.h"

int main()
{
    // setup
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    const int n{ 10 };
    std::array<std::array<int, n>, n> costs;
    std::array<std::array<int, n>, n> valueCache;
    int callCounter{ 0 };

    // create costs array
    for (auto& ar : costs)
        for (auto& val : ar)
            val = 1 + std::rand() % 10;
    std::cout << "Costs array:\n";
    printArray(costs);
    std::cout << "\n";

    // initialize cache array
    for (auto& ar : valueCache)
        for (auto& val : ar)
            val = -1;
    valueCache[0] = costs[0];

    // calculate minimum costs for each bottom position
    for (int i = n - 1; i >= 0; i--)
    {
        callCounter = 0;
        int cost = minCost<n>(n - 1, i, costs, valueCache, callCounter);
        std::cout << std::format("MinCost[{},{}]= {} with {} calls\n", n - 1, i, cost, callCounter);
    }

    // print cache array
    std::cout << "\nValue cache array:\n";
    printArray(valueCache);

    //main loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}