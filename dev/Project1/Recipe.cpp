#include "Recipe.h"
#include "Ingrediant.h"
#include <vector>
#include <algorithm> //lets me sort vectors
#include "Graphics.h"
#include <filesystem>

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

            if (choice < 0 || choice > recipes.size()) //checks if this answer is invalid
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
    if (dish.getName() == "Slop")
    {
        std::cout << "Cannot add slop to the cookbook!\n";
        return;
    }

    char value = ',';
    std::ifstream inFile(path); 
    std::string line;
    std::vector<Recipe> recipes;
    bool isDuplicate = false;

    if (inFile.is_open())
    {
        while (std::getline(inFile, line))
        {
            if (line.empty()) continue; // Skip empty lines safely

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

            // Check if the recipe already exists in the file by name, and if it is slop
            if (rName == dish.getName())
            {
                isDuplicate = true;
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
        inFile.close(); 
    }
    else
    {
        std::cout << "Failed to FIND recipe file!!\n";
        return; 
    }

    // If it's a new recipe, add it to our list before saving
    if (!isDuplicate)
    {
        recipes.push_back(dish);
    }
    else
    {
        std::cout << "Recipe already exists in the cookbook.\n";
        return; 
    }

    // Open file for overwriting
    std::ofstream outFile(path);
    if (outFile.is_open())
    {
        for (auto& r : recipes)
        {
            // Loop through ingredients and format back into CSV rows
            auto ingredients = r.getBowl();
            outFile << r.getName();
            for (const auto& ingredient : ingredients)
            {
                for (int i = 0; i < ingredient.getAmount(); i++)
                {
                    outFile << "," << ingredient.getName();
                }
            }
            outFile << "\n";
        }
        outFile.close();
        std::cout << "Cookbook updated successfully!\n";
    }
    else
    {
        std::cout << "Failed to OPEN recipe file for writing!!\n";
    }
}

//create a new cookbook file
void Recipe::CreateCookBook()
{
    std::string fileName;
    Graphics::clear();
    std::cout << "Please enter the name of your save file \n";
    std::cin >> fileName;
    fileName = fileName + ".csv";

    std::ofstream myFile(fileName);

    if (!myFile.is_open())
    {
        std::cout << "Error: Could not create or open " << fileName << "\n";
        return;
    }

    myFile << "Pancake,Flour,Flour,Egg,Milk\n";

    myFile.close();

    std::cout << "File created successfully!\n";
}

//select a cookbook file
std::string Recipe::SelectCookBook()
{
    bool choosing = true;
    while (choosing)
    {
        namespace fs = std::filesystem;

        std::vector<fs::path> csvFiles;
        std::string searchPath = "."; // Current directory

        // Find all CSV files
        for (const auto& entry : fs::directory_iterator(searchPath)) {
            if (entry.path().extension() == ".csv" && entry.path().filename() != "RecipeBook.configSV") {
                csvFiles.push_back(entry.path());
            }
        }

        // Check if any files exist
        if (csvFiles.empty()) {
            std::cout << "No Cook books found.\n";
            return "default.csv";
        }

        // Show files to user
        std::cout << "Select a Cookbook:\n";
        for (size_t i = 0; i < csvFiles.size(); ++i) {
            std::cout << i + 1 << ") " << csvFiles[i].filename().string() << "\n";
        }

        // Get selection
        std::string input;
        int choice = 0;
        std::cout << "Choice a book from the numbers: ";
        std::cin >> input;

        try {
            choice = std::stoi(input);
        }
        catch (const std::invalid_argument& e) {
            choice = 0; //banana test
        }

        if (choice > 0 && choice <= static_cast<int>(csvFiles.size())) {
            int index = choice - 1; //changes user input to fit vector size
            std::cout << "You picked: " << csvFiles[index].filename().string() << "\n";
            return csvFiles[index].string();
        }
        else {
            Graphics::clear();
            std::cout << "Invalid choice, please enter a number seen above.\n";
        }
    }
    return "default.csv";
}
