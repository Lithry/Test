#define CATCH_CONFIG_MAIN

#include "EnumSalary.h"
#include "SalaryRiser.hpp"
#include "Position.hpp"
#include "Employee.hpp"
#include "catch.hpp"

TEST_CASE("SalaryRiser Class Check") {
    std::unique_ptr<SalaryRiser> r = std::make_unique<SalaryRiser>();
    float t1 = r->riseSalary(100, CEO, JUNIOR);
    float t2 = r->riseSalary(100, CEO, SEMI_SENIOR);
    float t3 = r->riseSalary(100, CEO, SENIOR);
    REQUIRE(t1 == 100);
    REQUIRE(t1 == t2);
    REQUIRE(t1 == t3);
    REQUIRE(r->riseSalary(100, CEO, EMPTY) == 200);
}

TEST_CASE("Position Class Check"){
    std::unique_ptr<Position> p = std::make_unique<Position>(Engineering, SEMI_SENIOR, 1500);
    REQUIRE(p->getSalary() == 1500);
    REQUIRE(p->getPosition() == Engineering);
    REQUIRE(p->getSeniority() == SEMI_SENIOR);
    
    p->setSalary(2000);
    p->setPosition(PM);
    p->setSeniority(SENIOR);
    REQUIRE(p->getSalary() == 2000);
    REQUIRE(p->getPosition() == PM);
    REQUIRE(p->getSeniority() == SENIOR);
}

TEST_CASE("Employee Class Check"){
    std::unique_ptr<Empleoyee> e = std::make_unique<Empleoyee>("NameTest", "LastnameTest", "SurnameTest");
    REQUIRE(e->getFirstName() == "NameTest");
    REQUIRE(e->getLastName() == "LastnameTest");
    REQUIRE(e->getSurname() == "SurnameTest");
    REQUIRE(e->getFullName() == "NameTest LastnameTest SurnameTest");
    REQUIRE(e->getPosition() == nullptr);
    
    e->setEmpleoyee("NameTest2", "LastnameTest2", "SurnameTest2", HR, JUNIOR, 1000);
    REQUIRE(e->getFirstName() == "NameTest2");
    REQUIRE(e->getLastName() == "LastnameTest2");
    REQUIRE(e->getSurname() == "SurnameTest2");
    REQUIRE(e->getFullName() == "NameTest2 LastnameTest2 SurnameTest2");
    REQUIRE(e->getPosition() != nullptr);
    REQUIRE(e->getSalary() == 1000);
    REQUIRE(e->getPositionOnly() == HR);
    REQUIRE(e->getPositionStrOnly() == "HR");
    REQUIRE(e->getSeniorityOnly() == JUNIOR);
    REQUIRE(e->getSeniorityStrOnly() == "JUNIOR");
}
