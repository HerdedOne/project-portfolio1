#include "Recipe.h"
#include "Ingrediant.h"
#include <vector>
#include <algorithm> //lets me sort vectors
#include "Graphics.h"

int Recipe::OpenCookBook(std::string path, char value)
{
	//open player cook book and display all data
	std::ifstream file(path);
	std::string line;
    std::vector<Recipe> recipes;
    std::string input;
    int choice;
    bool reading = true;
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

            Recipe cookingRecipe;
            cookingRecipe.setBowl(bowl.getIngrediants());
            cookingRecipe.setName(rName);

            recipes.push_back(cookingRecipe);
        }
	}
	else
	{
		std::cout << "Failed to FIND recipe file!!\n";
	}
	file.close();

    Graphics::clear();

    while (reading)
    {
        std::cout << "Press 0 to LEAVE!\n";
        int num = 1;
        for (auto& r : recipes) //shows list of options
        {
            std::cout << num << ") " << r.getName() << "\n";
            num += 1;
        }
        std::cin >> input;

        try
        {
            choice = std::stoi(input);

            if (choice < 0 || choice > recipes.size() + 1) //checks if this answer is invalid
            {
                Graphics::clear();
                std::cout << "That is not a recipe, please enter a listed number.";
            }
            else if (choice == 0)
            {
                return 0;
            }
            else //converts user answer to ingredient
            {
                Graphics::clear();
                std::cout << recipes.at(choice - 1).getName() << " Recipe:\n";
                for (auto& i : recipes.at(choice - 1).getBowl())
                {
                    std::cout << i.getName() << ": " << i.getAmount() << "\n";
                }
                std::cout << "\n\n";

            }
        }
        catch (const std::invalid_argument& e)
        {
            Graphics::clear();
            std::cout << "That is not a recipe, please enter a listed number.";
        }
    }
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