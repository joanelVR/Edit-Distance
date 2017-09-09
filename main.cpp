// Copyright Joanel Vasquez 2017

#include <SFML/System.hpp>
#include "ED.hpp"

int main()
{

    sf::Clock clock;
    sf::Time time;
    std::string x_string, y_string;

    std::cin >> x_string;
    std::cin >> y_string;

    ED test(x_string,y_string);

    time = clock.getElapsedTime();
    
    std::cout << "Edit distance = " << test.OptDistance() << std::endl;
    
    std::cout << test.Alignment();

    std::cout << "Execution time is " << time.asSeconds() << " seconds" << std::endl;
  
    return 0;
}
