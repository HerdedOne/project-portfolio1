#pragma once
#include "Ingrediant.h"
#include <vector>

class Recipe; //forward declaration
class Customer;

class Cooking
{
public:
	void addToBowl(Ingrediant thing) //adding ingrediants to the vector
	{
		for (auto& b : bowl_)
		{
			if (b.getName() == thing.getName())
			{
				b.addMore(); //makes sure extra items of the same name are added to the amount
				return;
			}
		}
		bowl_.push_back(thing);
	}

	std::vector<Ingrediant> getIngrediants()
	{
		return bowl_;
	}

	void emptyBowl()
	{
		bowl_.clear();
	} //added for recipe sake, emptys vector

	static Recipe startCooking(const Customer& bro); //will boot up the screen


private:
	std::string dish_;
	std::vector<Ingrediant> bowl_;
};

