#ifndef GAME_FUNCTIONS_H
#define GAME_FUNCTIONS_H

#include <vector>

/**
 * @brief Checks if a value is present in the sequence.
 * @param sequence The sequence to check.
 * @param value The value to look for.
 * @return True if the value is found, false otherwise.
 */
bool IsSequenceHasValue(const std::vector<int> &sequence, int value);

/**
 * @brief Creates a random sequence of unique digits.
 * @param sequence_length The length of the sequence to create.
 * @return A vector containing the random sequence.
 */
std::vector<int> CreateRandomSequence(int sequence_length);

/**
 * @brief Counts the number of bulls in the user's sequence.
 * @param sequence The generated sequence.
 * @param user_sequence The user's sequence.
 * @return The number of bulls.
 */
int GetCountBulls(const std::vector<int> &sequence, const std::vector<int> &user_sequence);

/**
 * @brief Counts the number of cows in the user's sequence.
 * @param sequence The generated sequence.
 * @param user_sequence The user's sequence.
 * @param count_bulls The number of bulls already counted.
 * @return The number of cows.
 */
int GetCountCows(const std::vector<int> &sequence, const std::vector<int> &user_sequence, int count_bulls);

/**
 * @brief Displays the number of bulls and cows to the console.
 * @param count_bulls The number of bulls.
 * @param count_cows The number of cows.
 */
void DisplayBullsAndCows(int count_bulls, int count_cows);

#endif // GAME_FUNCTIONS_H
