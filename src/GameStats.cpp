#include "GameStats.h"

#include <fstream>
#include <iostream>

GameStats::GameStats() : games_played(0), games_won(0) {}

void GameStats::SaveToFile(const std::string &filename) const
{
    std::ofstream out_file(filename);
    if (out_file.is_open())
    {
        out_file << games_played << std::endl;
        out_file << games_won << std::endl;
        out_file.close();
    }
}

void GameStats::LoadFromFile(const std::string &filename)
{
    std::ifstream in_file(filename);
    if (in_file.is_open())
    {
        in_file >> games_played;
        in_file >> games_won;
        in_file.close();
    }
}

void GameStats::Display() const
{
    std::cout << "Total games played: " << games_played << ", Total games won: " << games_won << "\n";
}
