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
    Empleoyee(string name, string lastName, string surname, POST post, SEN seniority, int salary);
    ~Empleoyee();
    void setEmpleoyee(string name, string lastName, string surname, POST post, SEN seniority, int salary);
    void setPosition(POST post, SEN seniority, int salary);
    string getFirstName();
    string getLastName();
    string getSurname();
    string getFullName();
    POST getPosition();
    SEN getSeniority();
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
    string _firstName;
    string _lastName;
    string _surname;
    Position* _post;
    Calculator* _cal;
};

#endif /* Employee_hpp */
