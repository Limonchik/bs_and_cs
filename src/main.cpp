#include "BullsAndCows.h"

#include "GameStats.h"
#include "UserInput.h"
#include <iostream>

int main()
{
    GameStats stats;
    stats.LoadFromFile("game_stats.txt");

    std::cout << "Welcome to Bulls and Cows!\n";
    std::cout << "Would you like to view the rules (r) or view your stats (s) or start a new game (n)? ";
    char choice;
    std::cin >> choice;
    while (choice != 'r' && choice != 's' && choice != 'n')
    {
        std::cout << "Invalid input! Please enter 'r' for rules, 's' for stats, or 'n' for a new game: ";
        std::cin >> choice;
    }

    if (choice == 'r')
    {
        DisplayRulesToConsole();
    }
    else if (choice == 's')
    {
        stats.Display();
    }

    PlayNewGame(stats);
    return 0;
}
