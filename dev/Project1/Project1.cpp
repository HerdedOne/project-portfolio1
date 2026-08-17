#include <iostream>
#include <string>
#include "Cooking.h"
#include "Graphics.h"
#include "Recipe.h"
#include "Customer.h"

int main()
{
    Graphics myGraphics; //allows me to use the graphics class and methods
    std::cout << "Welcome to Secret Ingrediant!\n"; //title of game
    bool running = true; //makes game run

    std::string input; //will hold user input and change to menu choice
    std::string something; //meaningless input
    int choice;

    Cooking food;
    Customer bro;
    Recipe myDish;

    while (running)
    {
        std::cout << "What would you like to do? \n1) PLAY \n2) EXIT \n3) RECIPE BOOK \n\n";
        std::cin >> input;

        try 
        {
            choice = std::stoi(input);
            switch (choice) //actual menu directory
            {
            case 1:
                std::cout << "The game is playing\n\n";
                // will start cooking
                bro.SetWant(bro.findRandomRecipe());
                bro.Dialogue(bro);

                std::cout << "\nEnter something to begin cooking!\n";
                std::cin >> something;
                myDish = food.startCooking();
                bro.satisfyCustomer(bro, myDish);
                break;
            case 2:
                std::cout << "Goodbye\n";
                running = false;
                break;
            case 3: //testing recipes
                std::cout << "Opening Recipe Book....\n";
                Recipe::OpenCookBook("RecipeBook.configSV", ',');
                break;
            default: //entered something invalid
                Graphics::clear();
                std::cout << "Whoopsie, you entered something in INCORRECTLY. >:C \n\n";
                break;
            }
        }
        catch (const std::invalid_argument& e)
        {
            Graphics::clear();
            std::cout << """Whoopsie, you entered something in INCORRECTLY. >:C \n\n";
        }

    }
}

