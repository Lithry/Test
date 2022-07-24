//
//  Loader.cpp
//  ProgramTest
//
//  Created by Facundo Sargiotti on 10/7/22.
//  Copyright © 2022 Facundo. All rights reserved.
//

#include "Loader.hpp"
#include "Employee.hpp"
#include <random>

Loader::Loader(){}

Loader::~Loader(){
    for (size_t i = 0; i < mEmployees.size(); i++){
        delete mEmployees[i];
        mEmployees[i] = NULL;
    }
}

std::vector<Empleoyee*> Loader::LoadUsers(){
    for (size_t i = 0; i < 251; i++){
        Empleoyee* e = new Empleoyee("Empleoyee", "Nº", std::to_string(i+1));
        mEmployees.push_back(e);
    }
    
    Empleoyee* e = mEmployees.front();
    mEmployees.erase(mEmployees.begin());
    e->setPosition(CEO, EMPTY, 20000);
    mEmployees.push_back(e);
    
    for (size_t i = 0; i < 20; i++) {
        Empleoyee* e = mEmployees.front();
        mEmployees.erase(mEmployees.begin());
        if (i < 13)
            e->setPosition(HR, JUNIOR, 500);
        else if (i<15)
            e->setPosition(HR, SEMI_SENIOR, 1000);
        else
            e->setPosition(HR, SENIOR, 1500);
        mEmployees.push_back(e);
    }
    
    for (size_t i = 0; i < 150; i++) {
        Empleoyee* e = mEmployees.front();
        mEmployees.erase(mEmployees.begin());
        if (i < 32)
            e->setPosition(Engineering, JUNIOR, 1500);
        else if (i<100)
            e->setPosition(Engineering, SEMI_SENIOR, 3000);
        else
            e->setPosition(Engineering, SENIOR, 5000);
        
        mEmployees.push_back(e);
    }
    
    for (size_t i = 0; i < 25; i++) {
        Empleoyee* e = mEmployees.front();
        mEmployees.erase(mEmployees.begin());
        if (i<20)
            e->setPosition(Artist, SEMI_SENIOR, 1200);
        else
            e->setPosition(Artist, SENIOR, 2000);
        mEmployees.push_back(e);
    }
    
    for (size_t i = 0; i < 25; i++) {
        Empleoyee* e = mEmployees.front();
        mEmployees.erase(mEmployees.begin());
        if (i<15)
            e->setPosition(Desing, JUNIOR, 800);
        else
            e->setPosition(Desing, SENIOR, 2000);
        mEmployees.push_back(e);
    }
    
    for (size_t i = 0; i < 30; i++) {
        Empleoyee* e = mEmployees.front();
        mEmployees.erase(mEmployees.begin());
        if (i<20)
            e->setPosition(PM, SEMI_SENIOR, 2400);
        else
            e->setPosition(PM, SENIOR, 4000);
        mEmployees.push_back(e);
    }
    //RANDOM SHUFFLE
    std::shuffle(mEmployees.begin(), mEmployees.end(), std::random_device());
    
    return mEmployees;
}
