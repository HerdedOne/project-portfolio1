#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Ingrediant.h"
#include "Cooking.h"
#include <vector>

class Recipe
{
private:
	std::string recipeName_;
	Cooking bowl_;


public:
	//Constructor
	Recipe(const std::string& name, const Cooking& ingrediants)
	{
		recipeName_ = name;
		bowl_ = ingrediants;
	}

	//default constructor
	Recipe()
	{
		recipeName_ = "";
	}

	std::string getName()
	{
		return recipeName_;
	}

	std::vector<Ingrediant> getBowl()
	{
		return bowl_.getIngrediants();
	}

	void setName(std::string name)
	{
		recipeName_ = name;
	}

	void setBowl(std::vector<Ingrediant> bowl)
	{
		bowl_.emptyBowl();
		for (auto& ingr : bowl)
		{
			bowl_.addToBowl(ingr);
		}
	}

	//look at name of all recipes to choose from
	static int OpenCookBook(std::string path, char value);

	//insert bowl and decide what gets made
	static Recipe CookSomething(Cooking ingrediants);

	//update player cook book
	static void UpdateCookBook(Recipe dish, std::string path);
	
};

