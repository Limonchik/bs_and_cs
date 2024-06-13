#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "GameStats.h"

TEST_CASE("GameStats initialization")
{
    GameStats stats;
    CHECK(stats.games_played == 0);
    CHECK(stats.games_won == 0);
}

TEST_CASE("GameStats save and load from file")
{
    GameStats stats;
    stats.games_played = 5;
    stats.games_won = 3;
    stats.SaveToFile("test_stats.txt");

    GameStats loaded_stats;
    loaded_stats.LoadFromFile("test_stats.txt");

    CHECK(loaded_stats.games_played == 5);
    CHECK(loaded_stats.games_won == 3);
}
