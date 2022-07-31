//
//  SalaryRiser.cpp
//  ProgramTest
//
//  Created by Facundo Sargiotti on 30/7/22.
//  Copyright © 2022 Facundo. All rights reserved.
//

#include "SalaryRiser.hpp"

SalaryRiser::SalaryRiser(){}

SalaryRiser::~SalaryRiser(){}

float SalaryRiser::riseSalary(float salary, POSITIONS position, SENIORITIS seniority){
    if (salary < 1)
        return 0;
    
    
    float increment = (SALARYINCRESS_VALUE[position][seniority] * salary) / 100;
    return salary + increment;
}
