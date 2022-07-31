#define CATCH_CONFIG_MAIN

#include "EnumSalary.h"
#include "SalaryRiser.hpp"
#include "catch.hpp"

TEST_CASE( "Salary Rise % Chequed") {
    SalaryRiser r;
    POSITIONS p = NONE;
    SENIORITIS s = EMPTY;
    REQUIRE(r.riseSalary(100, p, s) == 0 );
}
