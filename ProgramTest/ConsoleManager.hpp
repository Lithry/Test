//
//  ConsoleManager.hpp
//  ProgramTest
//
//  Created by User on 28/05/2022.
//  Copyright © 2022 Facundo. All rights reserved.
//

#ifndef ConsoleManager_hpp
#define ConsoleManager_hpp

#include <stdio.h>
#include <string>

using namespace std;

class ConsoleManager{
public:
    ConsoleManager();
    ~ConsoleManager();
    void clearConsole();
    void draw(string text);
    void wait();
    int enterNumberOption();
};

#endif /* ConsoleManager_hpp */
