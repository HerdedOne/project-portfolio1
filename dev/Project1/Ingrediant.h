#pragma once
#include <string>
struct Ingrediant
{
	Ingrediant(std::string name) //constructor
	{
		name_ = name;
		amount_ = 1;
	}

	void addMore() //add another of it
	{
		amount_ += 1;
	}

	std::string getName() //get ingrediant name
	{
		return name_;
	}

	int getAmount() //get ingrediant amount
	{
		return amount_;
	}

	bool operator<(const Ingrediant& other) const {
		return name_ < other.name_;
	}

	bool operator==(const Ingrediant& other) const {
		return name_ == other.name_;
	}

	private: //private variables
		std::string name_;
		int amount_;
};

