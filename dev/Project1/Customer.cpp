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

void Dialogue();
