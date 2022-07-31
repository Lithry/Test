//
//  Position.cpp
//  ProgramTest
//
//  Created by User on 27/05/2022.
//  Copyright © 2022 Facundo. All rights reserved.
//

#include "Position.hpp"

Position::Position(){}

Position::Position(POSITIONS position, SENIORITIS seniority, float salary)
    :
    mPosition(position),
    mSeniority(seniority),
    mSalary(salary)
{}

Position::~Position(){}

void Position::setPosition(POSITIONS newPosition){
    mPosition = newPosition;
}

POSITIONS Position::getPosition(){
    return mPosition;
}

void Position::setSeniority(SENIORITIS newSeniority){
    mSeniority = newSeniority;
}

SENIORITIS Position::getSeniority(){
    return mSeniority;
}

void Position::setSalary(float newSalary){
    mSalary = newSalary;
}

float Position::getSalary(){
    return mSalary;
}
