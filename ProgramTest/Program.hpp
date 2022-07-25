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
    std::unique_ptr<ConsoleManager> p_mConsole;
    std::unique_ptr<Loader> p_mLoader;
    bool mActive;
    int mOption;
    std::vector<std::unique_ptr<Empleoyee>> mEmployees;
};

#endif /* Program_hpp */
