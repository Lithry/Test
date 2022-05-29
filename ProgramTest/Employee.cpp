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

Empleoyee::Empleoyee(string name, string lastName, string surname)
    :
    _firstName(name),
    _lastName(lastName),
    _surname(surname),
    _cal(new Calculator())
{}

Empleoyee::~Empleoyee(){
    delete _post;
    _post = NULL;
    delete _cal;
    _cal = NULL;
}

void Empleoyee::setEmpleoyee(string name, string lastName, string surname, POST post, SEN seniority, int salary){
    _firstName = name;
    _lastName = lastName;
    _surname = surname;
    _post = new Position(post, seniority, salary);
}

void Empleoyee::setPosition(POST post, SEN seniority, int salary){
    _post = new Position(post, seniority, salary);
}

string Empleoyee::getFirstName(){
    return _firstName;
}

string Empleoyee::getLastName(){
    return _lastName;
}

string Empleoyee::getSurname(){
    return _surname;
}

string Empleoyee::getFullName(){
    return _firstName + " " + _lastName + " " + _surname;
}

POST Empleoyee::getPosition(){
    return _post->getPosition();
}

string Empleoyee::getPositionStr(){
    return POST_STR[_post->getPosition()];
}

SEN Empleoyee::getSeniority(){
    return _post->getSeniority();
}

string Empleoyee::getSeniorityStr(){
    return SEN_STR[_post->getSeniority()];
}

int Empleoyee::getSalary(){
    return _post->getSalary();
}

bool Empleoyee::incrementSalary(){
    switch (_post->getPosition()) {
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
    _post->setSalary(_cal->calculatePercentInc(_post->getSalary(), 100));
    return true;
}

bool Empleoyee::incrementHRSalary(){
    switch (_post->getSeniority()) {
        case JUNIOR:
            //0.5%
            _post->setSalary(_cal->calculatePercentInc(_post->getSalary(), 0.5));
            break;
            case SEMI_SENIOR:
            //2%
            _post->setSalary(_cal->calculatePercentInc(_post->getSalary(), 2));
            break;
            case SENIOR:
            //5%
            _post->setSalary(_cal->calculatePercentInc(_post->getSalary(), 5));
            break;
        default:
            return false;
            break;
    }
    return true;
}

bool Empleoyee::incrementEngineeringSalary(){
    switch (_post->getSeniority()) {
        case JUNIOR:
            //5%
            _post->setSalary(_cal->calculatePercentInc(_post->getSalary(), 5));
            break;
            case SEMI_SENIOR:
            //7%
            _post->setSalary(_cal->calculatePercentInc(_post->getSalary(), 7));
            break;
            case SENIOR:
            //10%
            _post->setSalary(_cal->calculatePercentInc(_post->getSalary(), 10));
            break;
        default:
            return false;
            break;
    }
    return true;
}

bool Empleoyee::incrementArtistSalary(){
    switch (_post->getSeniority()) {
        case JUNIOR:
            //1%
            _post->setSalary(_cal->calculatePercentInc(_post->getSalary(), 1));
            break;
            case SEMI_SENIOR:
            //2.5%
            _post->setSalary(_cal->calculatePercentInc(_post->getSalary(), 2.5));
            break;
            case SENIOR:
            //5%
            _post->setSalary(_cal->calculatePercentInc(_post->getSalary(), 5));
            break;
        default:
            return false;
            break;
    }
    return true;
}

bool Empleoyee::incrementDesingSalary(){
    switch (_post->getSeniority()) {
        case JUNIOR:
            //2%
            _post->setSalary(_cal->calculatePercentInc(_post->getSalary(), 2));
            break;
            case SEMI_SENIOR:
            //4%
            _post->setSalary(_cal->calculatePercentInc(_post->getSalary(), 4));
            break;
            case SENIOR:
            //7%
            _post->setSalary(_cal->calculatePercentInc(_post->getSalary(), 7));
            break;
        default:
            return false;
            break;
    }
    return true;
}

bool Empleoyee::incrementPMSalary(){
    switch (_post->getSeniority()) {
        case JUNIOR:
            //2.5%
            _post->setSalary(_cal->calculatePercentInc(_post->getSalary(), 2.5));
            break;
            case SEMI_SENIOR:
            //5%
            _post->setSalary(_cal->calculatePercentInc(_post->getSalary(), 5));
            break;
            case SENIOR:
            //10%
            _post->setSalary(_cal->calculatePercentInc(_post->getSalary(), 10));
            break;
        default:
            return false;
            break;
    }
    return true;
}
