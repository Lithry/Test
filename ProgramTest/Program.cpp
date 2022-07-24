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
    p_mConsole = new ConsoleManager();
    mActive = true;
    
    // LOAD EMPLEOYEES
    p_mLoader = new Loader();
    mEmployees = p_mLoader->LoadUsers();
    
    return true;
}

bool Program::deinit(){
    delete p_mConsole;
    p_mConsole = NULL;
    delete p_mLoader;
    p_mLoader = NULL;

    return true;
}

void Program::run(){
    do{
        p_mConsole->clearConsole();
        options();
        mOption = p_mConsole->enterNumberOption();
        
        switch (mOption) {
            case 0:
                mActive = false;
                break;
            case 1:
                p_mConsole->draw(to_string(mEmployees.size()));
                break;
            case 2:
                for (size_t i = 0; i < mEmployees.size(); i++){
                    p_mConsole->draw(mEmployees[i]->getFullName() + " " + mEmployees[i]->getPositionStr() + " " + mEmployees[i]->getSeniorityStr() + " Salary: " + to_string(mEmployees[i]->getSalary()));
                }
                break;
            case 3:
                for (size_t i = 0; i < mEmployees.size(); i++){
                    mEmployees[i]->incrementSalary();
                }
                p_mConsole->draw("Increment Employees salary DONE");
                break;
            default:
                p_mConsole->draw("Invalid Option");
                break;
        }
        p_mConsole->wait();
    }while(mActive);
}

void Program::options(){
    p_mConsole->draw("OPTIONS");
    p_mConsole->draw("1 - Get number of Employees");
    p_mConsole->draw("2 - Get Employees full list");
    p_mConsole->draw("3 - Increment Employees salary");
    p_mConsole->draw("---------------------------------");
    p_mConsole->draw("0 - Exit Program");
}
