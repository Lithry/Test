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


using namespace std;

class Position;
class Calculator;

class Empleoyee{
public:
    Empleoyee();
    Empleoyee(string name, string lastName, string surname);
    Empleoyee(string name, string lastName, string surname, POSITIONS position, SENIORITIS seniority, int salary);
    ~Empleoyee();
    void setEmpleoyee(string name, string lastName, string surname, POSITIONS post, SENIORITIS seniority, int salary);
    void setPosition(POSITIONS position, SENIORITIS seniority, int salary);
    string getFirstName();
    string getLastName();
    string getSurname();
    string getFullName();
    POSITIONS getPosition();
    SENIORITIS getSeniority();
    string getPositionStr();
    string getSeniorityStr();
    int getSalary();
    bool incrementSalary();
private:
    bool incrementCEOSalary();
    bool incrementHRSalary();
    bool incrementEngineeringSalary();
    bool incrementArtistSalary();
    bool incrementDesingSalary();
    bool incrementPMSalary();
    string mFirstName;
    string mLastName;
    string mSurname;
    Position* m_pPosition;
    Calculator* m_pCalculator;
};

#endif /* Employee_hpp */
