#include "doctest.h"
#include "UserInput.h"
#include <sstream>
#include <iostream>

TEST_CASE("DisplayRulesToConsole")
{
    std::stringstream buffer;
    std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());

    DisplayRulesToConsole();

    std::cout.rdbuf(old);

    CHECK(buffer.str().empty() == false);
}