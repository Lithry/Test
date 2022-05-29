//
//  Position.cpp
//  ProgramTest
//
//  Created by User on 27/05/2022.
//  Copyright © 2022 Facundo. All rights reserved.
//

#include "Position.hpp"

Position::Position(){
    
}

Position::Position(POST post, SEN seniority, int salary)
    :
    _position(post),
    _seniority(seniority),
    _salary(salary)
{}

Position::~Position(){
    
}

void Position::setPosition(POST newPost){
    _position = newPost;
}

POST Position::getPosition(){
    return _position;
}

void Position::setSeniority(SEN newSeniority){
    _seniority = newSeniority;
}

SEN Position::getSeniority(){
    return _seniority;
}

void Position::setSalary(int newSalary){
    _salary = newSalary;
}

int Position::getSalary(){
    return _salary;
}
