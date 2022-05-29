//
//  EnumSalary.h
//  ProgramTest
//
//  Created by User on 27/05/2022.
//  Copyright © 2022 Facundo. All rights reserved.
//

#ifndef EnumSalary_h
#define EnumSalary_h

enum POST{
    NONE = 0,
    CEO,
    HR,
    Engineering,
    Artist,
    Desing,
    PM
};
static const char *POST_STR[] = {
    "NONE",
    "CEO",
    "HR",
    "Engineering",
    "Artist",
    "Desing",
    "PM"
};

enum SEN{
    EMPTY = 0,
    JUNIOR,
    SEMI_SENIOR,
    SENIOR
};

static const char *SEN_STR[] = {
    "EMPTY",
    "JUNIOR",
    "SEMI SENIOR",
    "SENIOR"
};

#endif /* EnumSalary_h */
