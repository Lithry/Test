//
//  Employee.cpp
//  ProgramTest
//
//  Created by User on 27/05/2022.
//  Copyright © 2022 Facundo. All rights reserved.
//

#include "Employee.hpp"
#include "Position.hpp"
#include "Calculator.hpp"

Empleoyee::Empleoyee(){}

Empleoyee::Empleoyee(std::string name, std::string lastName, std::string surname)
    :
    mFirstName(name),
    mLastName(lastName),
    mSurname(surname),
    m_pCalculator(std::make_unique<Calculator>())
{}

Empleoyee::~Empleoyee(){}

void Empleoyee::setEmpleoyee(std::string name, std::string lastName, std::string surname, POSITIONS position, SENIORITIS seniority, int salary){
    mFirstName = name;
    mLastName = lastName;
    mSurname = surname;
    m_pPosition = std::make_unique<Position>(position, seniority, salary);
}

void Empleoyee::setPosition(POSITIONS position, SENIORITIS seniority, int salary){
    m_pPosition = std::make_unique<Position>(position, seniority, salary);
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

POSITIONS Empleoyee::getPosition(){
    return m_pPosition->getPosition();
}

std::string Empleoyee::getPositionStr(){
    return POSITIONS_STR[m_pPosition->getPosition()];
}

SENIORITIS Empleoyee::getSeniority(){
    return m_pPosition->getSeniority();
}

std::string Empleoyee::getSeniorityStr(){
    return SENIORITIS_STR[m_pPosition->getSeniority()];
}

int Empleoyee::getSalary(){
    return m_pPosition->getSalary();
}

bool Empleoyee::incrementSalary(){
    switch (m_pPosition->getPosition()) {
        case CEO:
            return incrementCEOSalary();
        case HR:
            return incrementHRSalary();
        case Engineering:
            return incrementEngineeringSalary();
        case Artist:
            return incrementArtistSalary();
        case Desing:
            return incrementDesingSalary();
        case PM:
            return incrementPMSalary();
        default:
            return false;
    }
    return false;
}


bool Empleoyee::incrementCEOSalary(){
    //100%
    m_pPosition->setSalary(m_pCalculator->calculatePercentInc(m_pPosition->getSalary(), 100));
    return true;
}

bool Empleoyee::incrementHRSalary(){
    switch (m_pPosition->getSeniority()) {
        case JUNIOR:
            //0.5%
            m_pPosition->setSalary(m_pCalculator->calculatePercentInc(m_pPosition->getSalary(), 0.5));
            break;
            case SEMI_SENIOR:
            //2%
            m_pPosition->setSalary(m_pCalculator->calculatePercentInc(m_pPosition->getSalary(), 2));
            break;
            case SENIOR:
            //5%
            m_pPosition->setSalary(m_pCalculator->calculatePercentInc(m_pPosition->getSalary(), 5));
            break;
        default:
            return false;
            break;
    }
    return true;
}

bool Empleoyee::incrementEngineeringSalary(){
    switch (m_pPosition->getSeniority()) {
        case JUNIOR:
            //5%
            m_pPosition->setSalary(m_pCalculator->calculatePercentInc(m_pPosition->getSalary(), 5));
            break;
            case SEMI_SENIOR:
            //7%
            m_pPosition->setSalary(m_pCalculator->calculatePercentInc(m_pPosition->getSalary(), 7));
            break;
            case SENIOR:
            //10%
            m_pPosition->setSalary(m_pCalculator->calculatePercentInc(m_pPosition->getSalary(), 10));
            break;
        default:
            return false;
            break;
    }
    return true;
}

bool Empleoyee::incrementArtistSalary(){
    switch (m_pPosition->getSeniority()) {
        case JUNIOR:
            //1%
            m_pPosition->setSalary(m_pCalculator->calculatePercentInc(m_pPosition->getSalary(), 1));
            break;
            case SEMI_SENIOR:
            //2.5%
            m_pPosition->setSalary(m_pCalculator->calculatePercentInc(m_pPosition->getSalary(), 2.5));
            break;
            case SENIOR:
            //5%
            m_pPosition->setSalary(m_pCalculator->calculatePercentInc(m_pPosition->getSalary(), 5));
            break;
        default:
            return false;
            break;
    }
    return true;
}

bool Empleoyee::incrementDesingSalary(){
    switch (m_pPosition->getSeniority()) {
        case JUNIOR:
            //2%
            m_pPosition->setSalary(m_pCalculator->calculatePercentInc(m_pPosition->getSalary(), 2));
            break;
            case SEMI_SENIOR:
            //4%
            m_pPosition->setSalary(m_pCalculator->calculatePercentInc(m_pPosition->getSalary(), 4));
            break;
            case SENIOR:
            //7%
            m_pPosition->setSalary(m_pCalculator->calculatePercentInc(m_pPosition->getSalary(), 7));
            break;
        default:
            return false;
            break;
    }
    return true;
}

bool Empleoyee::incrementPMSalary(){
    switch (m_pPosition->getSeniority()) {
        case JUNIOR:
            //2.5%
            m_pPosition->setSalary(m_pCalculator->calculatePercentInc(m_pPosition->getSalary(), 2.5));
            break;
            case SEMI_SENIOR:
            //5%
            m_pPosition->setSalary(m_pCalculator->calculatePercentInc(m_pPosition->getSalary(), 5));
            break;
            case SENIOR:
            //10%
            m_pPosition->setSalary(m_pCalculator->calculatePercentInc(m_pPosition->getSalary(), 10));
            break;
        default:
            return false;
            break;
    }
    return true;
}
