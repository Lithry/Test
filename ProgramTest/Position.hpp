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
    Position(POSITIONS position, SENIORITIS seniority, int salary);
    ~Position();
    void setPosition(POSITIONS newPosition);
    POSITIONS getPosition();
    void setSeniority(SENIORITIS newSeniority);
    SENIORITIS getSeniority();
    void setSalary(int newSalary);
    int getSalary();
private:
    POSITIONS mPosition;
    SENIORITIS mSeniority;
    int mSalary;
};

#endif /* Position_hpp */
