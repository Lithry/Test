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
    for (size_t i = 0; i < _employees.size(); i++){
        delete _employees[i];
        _employees[i] = NULL;
    }
}

std::vector<Empleoyee*> Loader::LoadUsers(){
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
    
    return _employees;
}
