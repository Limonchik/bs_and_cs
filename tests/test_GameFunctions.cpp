#include <set>

#include "doctest.h"

#include "GameFunctions.h"

TEST_CASE("IsSequenceHasValue")
{
    std::vector<int> sequence = {1, 2, 3, 4, 5};
    CHECK(IsSequenceHasValue(sequence, 3) == true);
    CHECK(IsSequenceHasValue(sequence, 6) == false);
}

TEST_CASE("CreateRandomSequence")
{
    int sequence_length = 4;
    std::vector<int> sequence = CreateRandomSequence(sequence_length);
    CHECK(sequence.size() == sequence_length);
    std::set<int> unique_digits(sequence.begin(), sequence.end());
    CHECK(unique_digits.size() == sequence_length);
}

TEST_CASE("GetCountBulls")
{
    std::vector<int> sequence = {1, 2, 3, 4};
    std::vector<int> user_sequence = {1, 2, 0, 4};
    CHECK(GetCountBulls(sequence, user_sequence) == 3);
}

TEST_CASE("GetCountCows")
{
    std::vector<int> sequence = {1, 2, 3, 4};
    std::vector<int> user_sequence = {1, 3, 0, 4};
    int count_bulls = GetCountBulls(sequence, user_sequence);
    CHECK(GetCountCows(sequence, user_sequence, count_bulls) == 1);
}
