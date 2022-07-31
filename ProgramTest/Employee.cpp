//
//  Employee.cpp
//  ProgramTest
//
//  Created by User on 27/05/2022.
//  Copyright © 2022 Facundo. All rights reserved.
//

#include "Employee.hpp"
#include "Position.hpp"

Empleoyee::Empleoyee(){}

Empleoyee::Empleoyee(std::string name, std::string lastName, std::string surname)
    :
    mFirstName(name),
    mLastName(lastName),
    mSurname(surname)
{}

Empleoyee::~Empleoyee(){}

void Empleoyee::setEmpleoyee(std::string name, std::string lastName, std::string surname, POSITIONS position, SENIORITIS seniority, int salary){
    mFirstName = name;
    mLastName = lastName;
    mSurname = surname;
    m_pPosition = std::make_unique<Position>(position, seniority, salary);
}

void Empleoyee::setPosition(POSITIONS position, SENIORITIS seniority, float salary){
    m_pPosition = std::make_unique<Position>(position, seniority, salary);
}

void Empleoyee::setPosition(std::unique_ptr<Position>& newPosition){
    m_pPosition = std::move(newPosition);
}

std::string Empleoyee::getFirstName(){
    return mFirstName;
}

std::string Empleoyee::getLastName(){
    return mLastName;
}

std::string Empleoyee::getSurname(){
    return mSurname;
}

std::string Empleoyee::getFullName(){
    return mFirstName + " " + mLastName + " " + mSurname;
}

std::unique_ptr<Position>& Empleoyee::getPosition(){
    return m_pPosition;
}

POSITIONS Empleoyee::getPositionOnly(){
    return m_pPosition->getPosition();
}

std::string Empleoyee::getPositionStrOnly(){
    return POSITIONS_STR[m_pPosition->getPosition()];
}

SENIORITIS Empleoyee::getSeniorityOnly(){
    return m_pPosition->getSeniority();
}

std::string Empleoyee::getSeniorityStrOnly(){
    return SENIORITIS_STR[m_pPosition->getSeniority()];
}

float Empleoyee::getSalary(){
    return m_pPosition->getSalary();
}
