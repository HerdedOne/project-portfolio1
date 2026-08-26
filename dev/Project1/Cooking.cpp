#include "Cooking.h"
#include <iostream>
#include <string>
#include "Graphics.h"
#include "Recipe.h"
#include "Customer.h"

Recipe Cooking::startCooking(std::string playerFile, const Customer& bro)
{
    bool running = true;
    Recipe myDish;
    while (running)
    {


        //main interface making ingrediants to choose from
        Graphics::clear();
        std::cout << "Lets get cooking!\n"; //lets you know what we are doing

        std::string input; //will hold user input and change to menu choice
        int choice;
        Cooking myFood; //what we are adding to
        Cooking options; //the list of ingredients to choose from

        //the ingrediant options
        Ingrediant flour("Flour");
        Ingrediant sugar("Sugar");
        Ingrediant molasses("Molasses");
        Ingrediant honey("Honey");
        Ingrediant water("Water");
        Ingrediant egg("Egg");
        Ingrediant eggYolk("Egg Yolk");
        Ingrediant eggWhite("Egg White");
        Ingrediant yeast("Yeast");
        Ingrediant butter("Butter");
        Ingrediant oil("Oil");
        Ingrediant milk("Milk");
        Ingrediant cheese("Cheese");
        Ingrediant oats("Oats");

        options.addToBowl(flour);
        options.addToBowl(sugar);
        options.addToBowl(molasses);
        options.addToBowl(honey);
        options.addToBowl(water);
        options.addToBowl(egg);
        options.addToBowl(eggYolk);
        options.addToBowl(eggWhite);
        options.addToBowl(yeast);
        options.addToBowl(butter);
        options.addToBowl(oil);
        options.addToBowl(milk);
        options.addToBowl(cheese);
        options.addToBowl(oats);

        for (int count = 0; count < 4; count++)
        {
            //shows us what we already have
            std::cout << "\n------------------\nIn bowl: \n";
            for (auto& b : myFood.getIngrediants())
            {
                std::cout << b.getName() << ": " << b.getAmount() << "\n";
            }
            std::cout << "------------------\n";


            std::cout << "You may add only 4 Ingredients\n"; //ingredient cap meets for loop conditions
            std::cout << "The customer wants a \033[36m" << bro.GetWant().getName() << "\033[0m\n";
            std::cout << "would you like to add to the bowl? \n";
            std::cout << "\n\n\033[1m ENTER C FOR COOKBOOK! \033[0m\n";
            int num = 1;
            for (auto& o : options.getIngrediants()) //shows list of options
            {
                std::cout << num << ") " << o.getName() << "\n";
                num += 1;
            }
            std::cin >> input;

            if (input == "c" || input == "C")
            {
                Recipe::OpenCookBook(playerFile, ',');
            }

            try
            {
                choice = std::stoi(input);

                if (choice <= 0 || choice > options.bowl_.size()) //checks if this answer is invalid
                {
                    Graphics::clear();
                    std::cout << "You added air, it did nothing. \n\n";
                    count--; //this was not actually an ingredient....
                }
                else //converts user answer to ingredient
                {
                    Graphics::clear();
                    std::cout << "\033[35m" << options.bowl_.at(choice - 1).getName() << " added\033[0m\n\n";
                    myFood.addToBowl(options.bowl_.at(choice - 1));
                }
            }
            catch (const std::invalid_argument& e)
            {
                Graphics::clear();
                std::cout << "You added air, it did nothing. \n\n";
                count--; //this was not actually an ingredient....
            }
        }

        std::cout << "mixing ingrediants together...\n\n";
        //creating something

        Cooking creation = myFood;
        Recipe myDish = Recipe::CookSomething(creation);

        std::cout << "You made: \033[1m" << myDish.getName() << "\033[0m\n";

        for (auto& b : myDish.getBowl()) //see what we are mixing together
        {
            std::cout << b.getName() << ":\t" << b.getAmount() << "\n";
        }
        std::cout << "\n\n";

        
        std::cout << "Would you like to throw this away?\n(Y/N)\n";
        std::string yesOrNo;
        while (yesOrNo != "Y" && yesOrNo != "y" && yesOrNo != "N" && yesOrNo != "n")
        {
            std::cin >> yesOrNo;
        }
        if (yesOrNo == "n" || yesOrNo == "N")
        {
            return myDish;
            running = false;
        }
    }
    //return myDish;
}

