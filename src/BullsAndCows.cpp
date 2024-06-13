#include "BullsAndCows.h"

#include "GameFunctions.h"
#include "UserInput.h"
#include <iostream>

void PlayNewGame(GameStats &stats)
{
    int sequence_length = GetSequenceLength();
    int attempts_left = GetDifficultyLevel();
    std::vector<int> sequence = CreateRandomSequence(sequence_length);
    bool game_won = false;

    while (attempts_left > 0)
    {
        std::vector<int> user_sequence = GetUserSequence(sequence_length);
        int count_bulls = GetCountBulls(sequence, user_sequence);
        int count_cows = GetCountCows(sequence, user_sequence, count_bulls);
        DisplayBullsAndCows(count_bulls, count_cows);

        if (count_bulls == sequence_length)
        {
            std::cout << "Good Game Well Played:) Congratulations on your victory!\n";
            std::cout << "Thank you for playing!\n";
            game_won = true;
            ++stats.games_won;
            break;
        }

        --attempts_left;
        if (attempts_left > 0)
        {
            std::cout << "Attempts left: " << attempts_left << "\n";
        }
        else
        {
            std::cout << "No attempts left. Better luck next time!\n";
            std::cout << "The correct sequence was: ";
            for (int num : sequence)
            {
                std::cout << num;
            }
            std::cout << "\n";
        }
    }

    ++stats.games_played;
    stats.SaveToFile("game_stats.txt");

    stats.Display();

    std::cout << "Do you want to play again? (yes/no): ";
    std::string response;
    while (true)
    {
        std::cin >> response;
        if (response == "yes" || response == "y")
        {
            PlayNewGame(stats);
            break;
        }
        else if (response == "no" || response == "n")
        {
            std::cout << "Thank you for playing Bulls and Cows!\n";
            break;
        }
        else
        {
            std::cout << "Invalid input! Please enter 'yes' or 'no': ";
        }
    }
}
