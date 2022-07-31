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
    Position(POSITIONS position, SENIORITIS seniority, float salary);
    ~Position();
    void setPosition(POSITIONS newPosition);
    POSITIONS getPosition();
    void setSeniority(SENIORITIS newSeniority);
    SENIORITIS getSeniority();
    void setSalary(float newSalary);
    float getSalary();
private:
    POSITIONS mPosition;
    SENIORITIS mSeniority;
    float mSalary;
};

#endif /* Position_hpp */
