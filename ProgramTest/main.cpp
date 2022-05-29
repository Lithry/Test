//
//  main.cpp
//  ProgramTest
//
//  Created by User on 25/05/2022.
//  Copyright © 2022 Facundo. All rights reserved.
//

#include <iostream>
#include "Program.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    Program* p = new Program();
    p->run();
    delete p;
    p = NULL;
    return 0;
}
