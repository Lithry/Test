//
//  EnumSalary.h
//  ProgramTest
//
//  Created by User on 27/05/2022.
//  Copyright © 2022 Facundo. All rights reserved.
//

#ifndef EnumSalary_h
#define EnumSalary_h

enum POSITIONS{
    CEO = 0,
    HR,
    Engineering,
    Artist,
    Desing,
    PM
};
static const char *POSITIONS_STR[] = {
    "CEO",
    "HR",
    "Engineering",
    "Artist",
    "Desing",
    "PM"
};

enum SENIORITIS{
    EMPTY = 0,
    JUNIOR,
    SEMI_SENIOR,
    SENIOR
};
static const char *SENIORITIS_STR[] = {
    "EMPTY",
    "JUNIOR",
    "SEMI SENIOR",
    "SENIOR"
};

static const float SALARYINCRESS_VALUE[6][4] = {
    {100, 0, 0, 0},// CEO
    {0, 0.5, 2, 5},    // HR
    {0, 5, 7, 10},     // Engineering
    {0, 1, 2.5, 5},    // Artist
    {0, 4, 5, 7},      // Desing
    {0, 2.5, 5, 10}    // PM
};

#endif /* EnumSalary_h */
