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
    Cooking myFood; //what we are adding to
    Cooking options; //the list of ingredients to choose from

    //the ingrediant options
    Ingrediant egg("Egg");
    Ingrediant milk("Milk");
    Ingrediant flour("Flour");
    Ingrediant sugar("Sugar");

    options.addToBowl(egg);
    options.addToBowl(milk);
    options.addToBowl(flour);
    options.addToBowl(sugar);

    for (int count = 0; count < 4; count++)
    {

        std::cout << "You may add only 4 Ingredients\n"; //ingredient cap meets for loop conditions
        std::cout << "would you like to add to the bowl? \n";
        int num = 1;
        for (auto& o : options.getIngrediants()) //shows list of options
        {
            std::cout << num << ") " << o.getName() << "\n"; 
            num += 1;
        }
        std::cin >> input;
        choice = std::stoi(input);

        if (choice < 0 || choice > options.bowl_.size() + 1) //checks if this answer is invalid
        {
            Graphics::clear();
            std::cout << "You added air, it did nothing. \n\n";
            count--; //this was not actually an ingredient....
        }
        else //converts user answer to ingredient
        {
            Graphics::clear();
            std::cout << options.bowl_.at(choice -1).getName() <<" added\n";
            myFood.addToBowl(options.bowl_.at(choice - 1));
        }
    }

    std::cout << "mixing ingrediants together...\n\n"; 
    for (auto& b : myFood.getIngrediants()) //see what we are mixing together
    {
        std::cout << b.getName() << ":\t" << b.getAmount() << "\n";
    }
}

