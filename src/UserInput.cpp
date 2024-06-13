#include "UserInput.h"

#include <iostream>
#include <limits>
#include <set>
#include <string>

void DisplayRulesToConsole()
{
    std::cout << "Game \"Bulls and Cows\"\n";
    std::cout << "Game rules:\n";
    std::cout << "  1. The user enters the length of the sequence to be guessed (from 1 to 10).\n";
    std::cout << "  2. The user chooses a difficulty level which determines the number of attempts.\n";
    std::cout << "  3. The computer generates a sequence of the chosen length, consisting of unique digits (leading zero is possible).\n";
    std::cout << "  4. The user then tries to guess the generated sequence.\n";
    std::cout << "  5. The computer indicates how many digits (\"cows\") are correct but in the wrong place, and how many digits (\"bulls\") are correct and in the right place.\n";
    std::cout << "  6. The rounds continue until the user guesses the entire sequence correctly or runs out of attempts.\n";
    std::cout << "  7. For more detailed rules, please visit: https://en.wikipedia.org/wiki/Bulls_and_Cows.\n";
    std::cout << "Good Luck Have Fun:)\n";
}

int GetSequenceLength()
{
    std::cout << "Enter the desired length of the sequence (from 1 to 10):\n";
    int sequence_length;
    while (!(std::cin >> sequence_length) || sequence_length < 1 || sequence_length > 10)
    {
        std::cout << "Input error! Please try again.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return sequence_length;
}

int GetDifficultyLevel()
{
    std::cout << "Choose a difficulty level:\n";
    std::cout << "  1. Easy (20 attempts)\n";
    std::cout << "  2. Medium (15 attempts)\n";
    std::cout << "  3. Hard (10 attempts)\n";
    std::cout << "Enter 1, 2, or 3: ";
    int difficulty;
    while (!(std::cin >> difficulty) || difficulty < 1 || difficulty > 3)
    {
        std::cout << "Input error! Please try again.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    switch (difficulty)
    {
    case 1:
        return 20;
    case 2:
        return 15;
    case 3:
        return 10;
    default:
        return 10; // default to Hard if something goes wrong
    }
}

std::vector<int> GetUserSequence(int sequence_length)
{
    std::cout << "\nEnter your guess as a sequence of digits in one line! Remember, it can start with zero and should not contain repeating digits.\n";
    std::string user_input;
    std::cin >> user_input;
    while (user_input.length() != sequence_length || std::set<char>(user_input.begin(), user_input.end()).size() != sequence_length)
    {
        std::cout << "Input error! Please try again.\n";
        std::cout << "The sequence must consist of unique digits and its length should be " << sequence_length << ".\n";
        std::cin >> user_input;
    }

    std::vector<int> user_sequence(sequence_length);
    for (int i = 0; i < sequence_length; ++i)
    {
        user_sequence[i] = user_input[i] - '0';
    }

    return user_sequence;
}
