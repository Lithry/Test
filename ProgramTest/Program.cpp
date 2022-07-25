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

Program::Program():
    p_mConsole(nullptr)
{}

Program::~Program(){}

bool Program::init(){
    p_mConsole = std::make_unique<ConsoleManager>();
    
    mActive = true;
    
    // LOAD EMPLEOYEES
    p_mLoader = std::make_unique<Loader>();
    mEmployees = p_mLoader->LoadUsers();
    
    return true;
}

bool Program::deinit(){
    p_mConsole->draw("------ PROGRAM END ------");
    return true;
}

void Program::run(){
    init();
    
    do{
        p_mConsole->clearConsole();
        options();
        mOption = p_mConsole->enterNumberOption();
        
        switch (mOption) {
            case 0:
                mActive = false;
                break;
            case 1:
                p_mConsole->draw(std::to_string(mEmployees.size()));
                p_mConsole->wait();
                break;
            case 2:
                for (size_t i = 0; i < mEmployees.size(); i++){
                    p_mConsole->draw(mEmployees[i]->getFullName() + " " + mEmployees[i]->getPositionStr() + " " + mEmployees[i]->getSeniorityStr() + " Salary: " + std::to_string(mEmployees[i]->getSalary()));
                }
                p_mConsole->wait();
                break;
            case 3:
                for (size_t i = 0; i < mEmployees.size(); i++){
                    mEmployees[i]->incrementSalary();
                }
                p_mConsole->draw("Increment Employees salary DONE");
                p_mConsole->wait();
                break;
            default:
                p_mConsole->draw("Invalid Option");
                p_mConsole->wait();
                break;
        }
        
    }while(mActive);
    
    deinit();
}

void Program::options(){
    p_mConsole->draw("OPTIONS");
    p_mConsole->draw("1 - Get number of Employees");
    p_mConsole->draw("2 - Get Employees full list");
    p_mConsole->draw("3 - Increment Employees salary");
    p_mConsole->draw("---------------------------------");
    p_mConsole->draw("0 - Exit Program");
}
