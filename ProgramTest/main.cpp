//
//  main.cpp
//  ProgramTest
//
//  Created by User on 25/05/2022.
//  Copyright © 2022 Facundo. All rights reserved.
//

#include <iostream>
#include "Program.hpp"
#include <memory>

int main(int argc, const char * argv[]) {
    std::unique_ptr<Program> p = std::make_unique<Program>();
    p->run();
    return 0;
}
