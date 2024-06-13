#include "GameFunctions.h"
#include <iostream>
#include <algorithm>
#include <random>

bool IsSequenceHasValue(const std::vector<int> &sequence, int value)
{
    return std::find(sequence.begin(), sequence.end(), value) != sequence.end();
}

std::vector<int> CreateRandomSequence(int sequence_length)
{
    std::vector<int> sequence(sequence_length, -1);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 9);

    for (int i = 0; i < sequence_length; ++i)
    {
        int temp;
        do
        {
            temp = dis(gen);
        } while (IsSequenceHasValue(sequence, temp));
        sequence[i] = temp;
    }

    return sequence;
}

int GetCountBulls(const std::vector<int> &sequence, const std::vector<int> &user_sequence)
{
    int count_bulls = 0;
    for (size_t i = 0; i < sequence.size(); ++i)
    {
        if (user_sequence[i] == sequence[i])
        {
            ++count_bulls;
        }
    }
    return count_bulls;
}

int GetCountCows(const std::vector<int> &sequence, const std::vector<int> &user_sequence, int count_bulls)
{
    int count_coincidences = 0;
    for (int val : user_sequence)
    {
        if (IsSequenceHasValue(sequence, val))
        {
            ++count_coincidences;
        }
    }
    return count_coincidences - count_bulls;
}

void DisplayBullsAndCows(int count_bulls, int count_cows)
{
    std::cout << "Number of \"cows\": " << count_cows << ", number of \"bulls\": " << count_bulls << ".\n\n";
}
