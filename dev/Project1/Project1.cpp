#include <iostream>
#include <string>

int main()
{
    std::cout << "Welcome to Secret Ingrediant!\n";
    bool running = true;

    std::string input;
    int choice;

    while (running)
    {
        std::cout << "What would you like to do? \n1) PLAY \n2) EXIT \n\n";
        std::cin >> input;
        choice = std::stoi(input);

        switch (choice)
        {
        case 1:
            std::cout << "The game is playing\n";
            break;
        case 2:
            std::cout << "Goodbye\n";
            running = false;
            break;
        default:
            std::cout << "Whoopsie, you entered something in INCORRECTLY. >:C \n";
            break;
        }
    }
}
