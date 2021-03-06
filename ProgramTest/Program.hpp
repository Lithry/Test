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
class Loader;

class Program{
public:
    Program();
    ~Program();
    void run();
private:
    bool init();
    bool deinit();
    void options();
    ConsoleManager* p_mConsole;
    Loader* p_mLoader;
    bool mActive;
    int mOption;
    std::vector<Empleoyee*> mEmployees;
};

#endif /* Program_hpp */
