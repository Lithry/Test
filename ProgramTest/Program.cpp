//
//  Program.cpp
//  ProgramTest
//
//  Created by User on 25/05/2022.
//  Copyright © 2022 Facundo. All rights reserved.
//

#include <algorithm>
#include "Program.hpp"
#include "Employee.hpp"
#include "ConsoleManager.hpp"
#include "Loader.hpp"

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
    _loader = new Loader();
    _employees = _loader->LoadUsers();
    
    return true;
}

bool Program::deinit(){
    delete _console;
    _console = NULL;
    delete _loader;
    _loader = NULL;

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
