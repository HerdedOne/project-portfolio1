#include "Cooking.h"
#include <iostream>
#include <string>

void Cooking::startCooking()
{
	//main interface making ingrediants to choose from
    std::cout << "Lets get cooking!\n"; //lets you know what we are doing
    bool running = true; //makes game run

    std::string input; //will hold user input and change to menu choice
    int choice;
    Cooking myFood;

    //the ingrediant options
    Ingrediant egg("Egg");
    Ingrediant milk("Milk");
    Ingrediant flour("Flour");
    Ingrediant sugar("Sugar");

    while (running)
    {
        std::cout << "would you like to add to the bowl? \n1) Eggs \n2) Milk \n3) Flour \n4) Sugar \n5) Mix\n\n";
        std::cin >> input;
        choice = std::stoi(input);

        switch (choice) //menu directory for adding
        {
        case 1:
            std::cout << "Egg added\n";
            myFood.addToBowl(egg);
            break;
        case 2:
            std::cout << "Milk added\n";
            myFood.addToBowl(milk);
            break;
        case 3:
            std::cout << "Flour added\n";
            myFood.addToBowl(flour);
            break;
        case 4:
            std::cout << "Sugar added\n";
            myFood.addToBowl(sugar);
            break;
        case 5:
            std::cout << "mixing ingrediants together...\n\n";
            running = false;
            break;
        default: //entered something invalid
            std::cout << "You added air, it did nothoing. \n\n";
            break;
        }
    }
}
