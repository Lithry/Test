//
//  Program.cpp
//  ProgramTest
//
//  Created by User on 25/05/2022.
//  Copyright © 2022 Facundo. All rights reserved.
//

#include <algorithm>
#include <random>
#include "Program.hpp"
#include "Employee.hpp"
#include "ConsoleManager.hpp"

Program::Program(){
    init();
}

Program::~Program(){
    deinit();
}

bool Program::init(){
    _console = new ConsoleManager();
    _active = true;
    
    // LOAD EMPLEOYEES
    loadEmpleoyeesTest();
    
    _console->draw("Welcome!");
    return true;
}

bool Program::deinit(){
    _console->draw("PROGRAM END - GOODBYE!");
    delete _console;
    _console = NULL;
    for (size_t i = 0; i < _employees.size(); i++){
        delete _employees[i];
        _employees[i] = NULL;
    }
    return true;
}

void Program::run(){
    do{
        _console->clearConsole();
        options();
        _option = _console->enterNumberOption();
        
        switch (_option) {
            case 0:
                _active = false;
                break;
            case 1:
                _console->draw(to_string(_employees.size()));
                break;
            case 2:
                for (size_t i = 0; i < _employees.size(); i++){
                    _console->draw(_employees[i]->getFullName() + " " + _employees[i]->getPositionStr() + " " + _employees[i]->getSeniorityStr() + " Salary: " + to_string(_employees[i]->getSalary()));
                }
                break;
            case 3:
                for (size_t i = 0; i < _employees.size(); i++){
                    _employees[i]->incrementSalary();
                }
                _console->draw("Increment Employees salary DONE");
                break;
            default:
                _console->draw("Invalid Option");
                break;
        }
        _console->wait();
    }while(_active);
}

void Program::options(){
    _console->draw("OPTIONS");
    _console->draw("1 - Get number of Employees");
    _console->draw("2 - Get Employees full list");
    _console->draw("3 - Increment Employees salary");
    _console->draw("---------------------------------");
    _console->draw("0 - Exit Program");
}

void Program::loadEmpleoyeesTest(){
    for (size_t i = 0; i < 251; i++){
        Empleoyee* e = new Empleoyee("Empleoyee", "Nº", to_string(i+1));
        _employees.push_back(e);
    }
    
    Empleoyee* e = _employees.front();
    _employees.erase(_employees.begin());
    e->setPosition(CEO, EMPTY, 20000);
    _employees.push_back(e);
    
    for (size_t i = 0; i < 20; i++) {
        Empleoyee* e = _employees.front();
        _employees.erase(_employees.begin());
        if (i < 13)
            e->setPosition(HR, JUNIOR, 500);
        else if (i<15)
            e->setPosition(HR, SEMI_SENIOR, 1000);
        else
            e->setPosition(HR, SENIOR, 1500);
        _employees.push_back(e);
    }
    
    for (size_t i = 0; i < 150; i++) {
        Empleoyee* e = _employees.front();
        _employees.erase(_employees.begin());
        if (i < 32)
            e->setPosition(Engineering, JUNIOR, 1500);
        else if (i<100)
            e->setPosition(Engineering, SEMI_SENIOR, 3000);
        else
            e->setPosition(Engineering, SENIOR, 5000);
        
        _employees.push_back(e);
    }
    
    for (size_t i = 0; i < 25; i++) {
        Empleoyee* e = _employees.front();
        _employees.erase(_employees.begin());
        if (i<20)
            e->setPosition(Artist, SEMI_SENIOR, 1200);
        else
            e->setPosition(Artist, SENIOR, 2000);
        _employees.push_back(e);
    }
    
    for (size_t i = 0; i < 25; i++) {
        Empleoyee* e = _employees.front();
        _employees.erase(_employees.begin());
        if (i<15)
            e->setPosition(Desing, JUNIOR, 800);
        else
            e->setPosition(Desing, SENIOR, 2000);
        _employees.push_back(e);
    }
    
    for (size_t i = 0; i < 30; i++) {
        Empleoyee* e = _employees.front();
        _employees.erase(_employees.begin());
        if (i<20)
            e->setPosition(PM, SEMI_SENIOR, 2400);
        else
            e->setPosition(PM, SENIOR, 4000);
        _employees.push_back(e);
    }
    //RANDOM SHUFFLE
    std::shuffle(_employees.begin(), _employees.end(), std::random_device());
}
