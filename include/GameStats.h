#ifndef GAME_STATS_H
#define GAME_STATS_H

#include <string>

/**
 * @brief Struct to hold game statistics.
 */
struct GameStats
{
    int games_played;
    int games_won;

    GameStats();

    /**
     * @brief Saves the game statistics to a file.
     * @param filename Name of the file to save the statistics.
     */
    void SaveToFile(const std::string &filename) const;

    /**
     * @brief Loads the game statistics from a file.
     * @param filename Name of the file to load the statistics.
     */
    void LoadFromFile(const std::string &filename);

    /**
     * @brief Displays the game statistics to the console.
     */
    void Display() const;
};

#endif // GAME_STATS_H
