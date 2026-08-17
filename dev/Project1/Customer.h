#pragma once
#include <iostream>
#include <string>
#include "Ingrediant.h"
#include "Cooking.h"
#include "Recipe.h"
class Customer
{
private:
	Recipe want_; //what they ask for
public:

	Customer()
	{
		want_ = findRandomRecipe(); //sets the random recipe
	}

	Recipe GetWant()
	{
		return want_; //find out what they want
	}
	void SetWant(Recipe newWant)
	{
		want_ = newWant; //set what they want
	}

	Recipe findRandomRecipe();
	Ingrediant findRandomTwist();
	void Dialogue(Customer loyalCustomer);
	void satisfyCustomer(Customer loyalCustomer, Recipe whatYouMade);
};

