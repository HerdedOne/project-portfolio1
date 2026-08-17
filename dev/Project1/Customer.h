#pragma once
#include <iostream>
#include <string>
#include "Ingrediant.h"
#include "Cooking.h"
#include "Recipe.h"
class Customer
{
private:
	Recipe want_;
public:

	Customer()
	{
	}

	Recipe GetWant()
	{
		return want_;
	}
	void SetWant(Recipe newWant)
	{
		want_ = newWant;
	}

	Recipe findRandomRecipe();
	Ingrediant findRandomTwist();
	void Dialogue();
};

