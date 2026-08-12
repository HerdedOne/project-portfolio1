#include "Cooking.h"
#include <iostream>
#include <string>
#include "Graphics.h"

void Cooking::startCooking()
{
	//main interface making ingrediants to choose from
    Graphics::clear();
    std::cout << "Lets get cooking!\n"; //lets you know what we are doing

    std::string input; //will hold user input and change to menu choice
    int choice;
    Cooking myFood;

    //the ingrediant options
    Ingrediant egg("Egg");
    Ingrediant milk("Milk");
    Ingrediant flour("Flour");
    Ingrediant sugar("Sugar");

    for (int count = 0; count < 4; count++)
    {
        std::cout << "You may add only 4 Ingredients\n"; //ingredient cap meets for loop conditions
        std::cout << "would you like to add to the bowl? \n1) Eggs \n2) Milk \n3) Flour \n4) Sugar \n\n";
        std::cin >> input;
        choice = std::stoi(input);

        switch (choice) //menu directory for adding
        {
        case 1:
            Graphics::clear();
            std::cout << "Egg added\n";
            myFood.addToBowl(egg);
            break;
        case 2:
            Graphics::clear();
            std::cout << "Milk added\n";
            myFood.addToBowl(milk);
            break;
        case 3:
            Graphics::clear();
            std::cout << "Flour added\n";
            myFood.addToBowl(flour);
            break;
   
        case 4:
            Graphics::clear();
            std::cout << "Sugar added\n";
            myFood.addToBowl(sugar);
            break;
        default: //entered something invalid
            Graphics::clear();
            std::cout << "You added air, it did nothing. \n\n";
            count--; //this was not actually an ingredient....
            break;
        }
    }
    //outside of for loop so this happens only after for loop conditions are met.
    std::cout << "mixing ingrediants together...\n\n"; 
    for (auto& b : myFood.getIngrediants()) //see what we are mixing together
    {
        std::cout << b.getName() << ":\t" << b.getAmount() << "\n";
    }
}

