set(TEST_SOURCES
    test_GameStats.cpp
    test_GameFunctions.cpp
    test_UserInput.cpp
)

add_executable(BullsAndCowsTests ${TEST_SOURCES})

target_link_libraries(BullsAndCowsTests BullsAndCowsLib doctest)

add_test(NAME BullsAndCowsTests COMMAND BullsAndCowsTests)
