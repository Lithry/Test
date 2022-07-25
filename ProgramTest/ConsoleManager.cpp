//
//  ConsoleManager.cpp
//  ProgramTest
//
//  Created by User on 28/05/2022.
//  Copyright © 2022 Facundo. All rights reserved.
//

#include "ConsoleManager.hpp"
#include <iostream>

ConsoleManager::ConsoleManager(){
    //system("clear");
}

ConsoleManager::~ConsoleManager(){}

void ConsoleManager::clearConsole(){
    system("clear");
}

void ConsoleManager::draw(std::string text){
    std::cout << text << std::endl;
}

void ConsoleManager::wait(){
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
}

int ConsoleManager::enterNumberOption(){
    int x;
    while(1)
    {
        std::cout << "Select option: ";
        std::cin >> x;
        if (!std::cin.fail()) break;
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cout << "Bad entry.\n";
    }
    return x;
}
