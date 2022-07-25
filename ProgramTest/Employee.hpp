//
//  Employee.hpp
//  ProgramTest
//
//  Created by User on 27/05/2022.
//  Copyright © 2022 Facundo. All rights reserved.
//

#ifndef Employee_hpp
#define Employee_hpp

#include <stdio.h>
#include <string>
#include "EnumSalary.h"

class Position;
class Calculator;

class Empleoyee{
public:
    Empleoyee();
    Empleoyee(std::string name, std::string lastName, std::string surname);
    Empleoyee(std::string name, std::string lastName, std::string surname, POSITIONS position, SENIORITIS seniority, int salary);
    ~Empleoyee();
    void setEmpleoyee(std::string name, std::string lastName, std::string surname, POSITIONS post, SENIORITIS seniority, int salary);
    void setPosition(POSITIONS position, SENIORITIS seniority, int salary);
    std::string getFirstName();
    std::string getLastName();
    std::string getSurname();
    std::string getFullName();
    POSITIONS getPosition();
    SENIORITIS getSeniority();
    std::string getPositionStr();
    std::string getSeniorityStr();
    int getSalary();
    bool incrementSalary();
private:
    bool incrementCEOSalary();
    bool incrementHRSalary();
    bool incrementEngineeringSalary();
    bool incrementArtistSalary();
    bool incrementDesingSalary();
    bool incrementPMSalary();
    std::string mFirstName;
    std::string mLastName;
    std::string mSurname;
    std::unique_ptr<Position> m_pPosition;
    std::unique_ptr<Calculator> m_pCalculator;
};

#endif /* Employee_hpp */
