#ifndef USER_INPUT_H
#define USER_INPUT_H

#include <vector>

/**
 * @brief Displays the rules of the game to the console.
 */
void DisplayRulesToConsole();

/**
 * @brief Gets the length of the sequence from the user.
 * @return The length of the sequence.
 */
int GetSequenceLength();

/**
 * @brief Gets the difficulty level from the user.
 * @return The number of attempts based on the difficulty level.
 */
int GetDifficultyLevel();

/**
 * @brief Gets the user's guess as a sequence of digits.
 * @param sequence_length The length of the sequence to guess.
 * @return A vector containing the user's guess.
 */
std::vector<int> GetUserSequence(int sequence_length);

#endif // USER_INPUT_H
