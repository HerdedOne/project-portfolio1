#include "Customer.h"
#include <random>


Recipe Customer::findRandomRecipe()
{
	std::vector<Recipe> choices; //creates a vector for the recipes

	std::random_device rand; //random generation setup
	std::mt19937 gen(rand());

	std::ifstream file("RecipeBook.configSV"); //big folder for what I will use
	std::string line;

	if (file.is_open())
	{
		while (std::getline(file, line))
		{
			std::stringstream ss(line);
			char value = ',';
			Recipe option;

			std::string rName, ingrediant1, ingrediant2, ingrediant3, ingrediant4;
			std::getline(ss, rName, value);
			std::getline(ss, ingrediant1, value);
			std::getline(ss, ingrediant2, value);
			std::getline(ss, ingrediant3, value);
			std::getline(ss, ingrediant4, '\n');

			option.setName(rName); //sets the name for the option

			std::vector<Ingrediant> aBowl; //creates a bowl and adds to it
			aBowl.push_back(ingrediant1);
			aBowl.push_back(ingrediant2);
			aBowl.push_back(ingrediant3);
			aBowl.push_back(ingrediant4);

			option.setBowl(aBowl); //sets bowl to bowl I made

			choices.push_back(option); //adds option to vector
		}
		file.close();
	}
	if (choices.empty()) 
	{
		return Recipe();
	}

	std::uniform_int_distribution<size_t> distrib(0, choices.size() - 1); //range for generation

	return choices.at(distrib(gen)); //returns random recipe in range
}


Ingrediant findRandomTwist();

void Dialogue(Customer loyalCustomer)
{
	std::cout << "Hello! I am a loyal customer, and I would love a " << loyalCustomer.GetWant().getName() << ", MAKE IT FOR ME NOW!" << std::endl;
}

void satisfyCustomer(Customer loyalCustomer, Recipe whatYouMade)
{
    std::vector<Ingrediant> customerBowl = loyalCustomer.GetWant().getBowl();
    std::vector<Ingrediant> madeBowl = whatYouMade.getBowl();

    std::sort(customerBowl.begin(), customerBowl.end());
    std::sort(madeBowl.begin(), madeBowl.end());

    if (whatYouMade.getName() == loyalCustomer.GetWant().getName())
    {
        std::cout << "This is EXACTLY what I wanted!! Thank you so much for making me " << whatYouMade.getName() << "\n";
    }
    else if (whatYouMade.getName() == "Slop")
    {
        std::cout << "EWW, WHY DID YOU HAND ME THIS?? \n";
    }
    else
    {
        size_t matchCount = 0;
        size_t i = 0; // index for customerBowl
        size_t j = 0; // index for madeBowl

        //checks if an item is the same
        while (i < customerBowl.size() and j < madeBowl.size())
        {
            if (customerBowl[i] == madeBowl[j])
            {
                matchCount++;
                i++;
                j++; //it matches, checks the next one
            }
            else if (customerBowl[i] < madeBowl[j])
            {
                i++; //not even, so need to check next one
            }
            else
            {
                j++;
            }
        }

        // if 3 items matched, it will give you the recipe, TO BE IMPLIMENTED
        if (matchCount == 3)
        {
            std::cout << "This is almost what I wanted... Here's the recipe \n";
            //GIVE RECIPE TO PLAYER COOKBOOK
        }
        else
        {
            std::cout << "This isn't what I ordered at all.\n";
        }
    }
}

