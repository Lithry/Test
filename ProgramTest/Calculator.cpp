//
//  Calculator.cpp
//  ProgramTest
//
//  Created by User on 29/05/2022.
//  Copyright © 2022 Facundo. All rights reserved.
//

#include "Calculator.hpp"

Calculator::Calculator(){}

Calculator::~Calculator(){}

int Calculator::calculatePercentInc(int base, float percentInc){
    float increment = (percentInc * base) / 100;
    return base + increment;
}
