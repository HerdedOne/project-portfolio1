#include "Recipe.h"
#include "Ingrediant.h"
#include <vector>
#include <algorithm> //lets me sort vectors

int Recipe::OpenCookBook(std::string path, char value)
{
	//open player cook book and display all data
	std::ifstream file(path);
	std::string line;


	if (file.is_open())
	{
		while (std::getline(file, line))
		{
			std::stringstream ss(line);

			Recipe food;

			std::string rName, indregiant1, indregiant2, indregiant3, indregiant4;
			std::getline(ss, rName, value);
			std::getline(ss, indregiant1, value);
			std::getline(ss, indregiant2, value);
			std::getline(ss, indregiant3, value);
			std::getline(ss, indregiant4, '\n');

			food.recipeName_ = rName;
			food.bowl_.addToBowl(indregiant1);
			food.bowl_.addToBowl(indregiant2);
			food.bowl_.addToBowl(indregiant3);
			food.bowl_.addToBowl(indregiant4);

			std::cout << food.recipeName_ << ": \n";
			for (auto& b : food.bowl_.getIngrediants()) //see what we are mixing together
			{
				std::cout << b.getName() << ":\t" << b.getAmount() << "\n";
			}
			std::cout << "\n\n";
		}
	}
	else
	{
		std::cout << "Failed to FIND recipe file!!\n";
	}
	file.close();

	return 0;
}

Recipe Recipe::CookSomething(Cooking creation)
{
    std::ifstream file("RecipeBook.configSV");
    char value = ',';
    std::string line;
    std::vector<Ingrediant> creationBowl = creation.getIngrediants();
    std::sort(creationBowl.begin(), creationBowl.end());

    if (file.is_open())
    {
        while (std::getline(file, line))
        {
            std::stringstream ss(line);

           
            std::string rName, ingredient1, ingredient2, ingredient3, ingredient4;
            std::getline(ss, rName, value);
            std::getline(ss, ingredient1, value);
            std::getline(ss, ingredient2, value);
            std::getline(ss, ingredient3, value);
            std::getline(ss, ingredient4, '\n');

            if (!ingredient4.empty() && ingredient4.back() == '\r') 
            {
                ingredient4.pop_back();
            }

            Cooking bowl;
   
            bowl.addToBowl(ingredient1);
            bowl.addToBowl(ingredient2);
            bowl.addToBowl(ingredient3);
            bowl.addToBowl(ingredient4);

            std::vector<Ingrediant> cookingBowl = bowl.getIngrediants();
            std::sort(cookingBowl.begin(), cookingBowl.end());

            if (cookingBowl == creationBowl)
            {
                Recipe food(rName, bowl);
                file.close();
                return food;
            }
        }
        file.close();

        // If file finishes reading but no recipe matched
        Recipe food("Slop", creation);
        return food;
    }

   // Fallback if the file failed to open entirely
    Recipe food("Slop", creation);
    return food;
}

void Recipe::UpdateCookBook(Recipe dish, std::string path)
{
	//check if dish is in player cookbook, if not, add it.

}