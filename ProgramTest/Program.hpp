//
//  Program.hpp
//  ProgramTest
//
//  Created by User on 25/05/2022.
//  Copyright © 2022 Facundo. All rights reserved.
//

#ifndef Program_hpp
#define Program_hpp

#include <stdio.h>
#include <vector>
#include <list>

class Empleoyee;
class ConsoleManager;

class Program{
public:
    Program();
    ~Program();
    void run();
private:
    bool init();
    bool deinit();
    void options();
    void loadEmpleoyeesTest();
    ConsoleManager* _console;
    bool _active;
    int _option;
    std::vector<Empleoyee*> _employees;
    std::list<Empleoyee> _list;
};

#endif /* Program_hpp */
