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
#include "Position.hpp"
#include "SalaryRiser.hpp"

Program::Program(){}

Program::~Program(){}

bool Program::init(){
    p_mConsole = std::make_unique<ConsoleManager>();
    p_mSalaryRiser = std::make_unique<SalaryRiser>();
    
    mActive = true;
    
    // LOAD EMPLEOYEES
    std::unique_ptr<Loader> pLoader = std::make_unique<Loader>();
    mEmployees = pLoader->loadUsers();
    
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
                p_mConsole->setFloatPrecision(2);
                for (size_t i = 0; i < mEmployees.size(); i++){
                    p_mConsole->draw(mEmployees[i]->getFullName() + " " + mEmployees[i]->getPositionStrOnly() + " " + mEmployees[i]->getSeniorityStrOnly() + " Salary: " + std::to_string((int)mEmployees[i]->getSalary()));
                }
                p_mConsole->wait();
                break;
            case 3:
                for (size_t i = 0; i < mEmployees.size(); i++){
                    std::unique_ptr<Position> employPosition = std::move(mEmployees[i]->getPosition());
                    employPosition->setSalary(p_mSalaryRiser->riseSalary(employPosition->getSalary(), employPosition->getPosition(), employPosition->getSeniority()));
                    mEmployees[i]->setPosition(employPosition);
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
