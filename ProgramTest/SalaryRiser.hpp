//
//  SalaryRiser.hpp
//  ProgramTest
//
//  Created by Facundo Sargiotti on 30/7/22.
//  Copyright © 2022 Facundo. All rights reserved.
//

#ifndef SalaryRiser_hpp
#define SalaryRiser_hpp

#include <stdio.h>
#include "EnumSalary.h"

class SalaryRiser{
public:
    SalaryRiser();
    ~SalaryRiser();
    float riseSalary(float salary, POSITIONS position, SENIORITIS seniority);
};

#endif /* SalaryRiser_hpp */
