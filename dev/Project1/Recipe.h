#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Ingrediant.h"
#include "Cooking.h"
#include <vector>

struct Recipe
{
	std::string recipeName;
	Cooking bowl;

	static int LoadRecipe(std::string path, Recipe& food, char value)
	{
		std::ifstream file(path);
		std::string line;

		if (file.is_open())
		{
			while (std::getline(file, line))
			{

				std::stringstream ss(line);

				std::string rName, indregiant1, indregiant2, indregiant3, indregiant4;
				std::getline(ss, rName, value);
				std::getline(ss, indregiant1, value);
				std::getline(ss, indregiant2, value);
				std::getline(ss, indregiant3, value);
				std::getline(ss, indregiant4, '\n');

				food.recipeName = rName;
				food.bowl.addToBowl(indregiant1);
				food.bowl.addToBowl(indregiant2);
				food.bowl.addToBowl(indregiant3);
				food.bowl.addToBowl(indregiant4);

				std::cout << "FOR TESTING\n";
				std::cout << food.recipeName << ": \n";
				for (auto& b : food.bowl.getIngrediants()) //see what we are mixing together
				{
					std::cout << b.getName() << ":\t" << b.getAmount() << "\n";
				}
				std::cout << "\n\n";

				food.bowl.emptyBowl();
			}
		}
		else
		{
			std::cout << "Failed to FIND recipe file!!\n";
		}
		file.close();

		return 0;
	}
};

