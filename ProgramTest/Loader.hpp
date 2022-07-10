//
//  Loader.hpp
//  ProgramTest
//
//  Created by Facundo Sargiotti on 10/7/22.
//  Copyright © 2022 Facundo. All rights reserved.
//

#ifndef Loader_hpp
#define Loader_hpp

#include <stdio.h>
#include <algorithm>
#include <vector>

class Empleoyee;

class Loader{
public:
    Loader();
    ~Loader();
    std::vector<Empleoyee*> LoadUsers();
private:
    std::vector<Empleoyee*> _employees;
};

#endif /* Loader_hpp */
