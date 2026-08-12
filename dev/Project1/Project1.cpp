#include <iostream>
#include <string>
#include "Cooking.h"
#include "Graphics.h"

int main()
{
    Graphics myGraphics; //allows me to use the graphics class and methods
    std::cout << "Welcome to Secret Ingrediant!\n"; //title of game
    bool running = true; //makes game run

    std::string input; //will hold user input and change to menu choice
    int choice;

    Cooking food;

    while (running)
    {
        std::cout << "What would you like to do? \n1) PLAY \n2) EXIT \n\n";
        std::cin >> input;
        choice = std::stoi(input);

        switch (choice) //actual menu directory
        {
        case 1:
            std::cout << "The game is playing\n\n";
            // will start cooking
            food.startCooking();
            break;
        case 2:
            std::cout << "Goodbye\n";
            running = false;
            break;
        default: //entered something invalid
            Graphics::clear();
            std::cout << "Whoopsie, you entered something in INCORRECTLY. >:C \n\n";
            break;
        }
    }
}

