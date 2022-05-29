//
//  Position.hpp
//  ProgramTest
//
//  Created by User on 27/05/2022.
//  Copyright © 2022 Facundo. All rights reserved.
//

#ifndef Position_hpp
#define Position_hpp

#include <stdio.h>
#include "EnumSalary.h"


class Position{
public:
    Position();
    Position(POST post, SEN seniority, int salary);
    ~Position();
    void setPosition(POST newPost);
    POST getPosition();
    void setSeniority(SEN newSeniority);
    SEN getSeniority();
    void setSalary(int newSalary);
    int getSalary();
private:
    POST _position;
    SEN _seniority;
    int _salary;
};

#endif /* Position_hpp */
