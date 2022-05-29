//
//  ConsoleManager.cpp
//  ProgramTest
//
//  Created by User on 28/05/2022.
//  Copyright © 2022 Facundo. All rights reserved.
//

#include "ConsoleManager.hpp"
#include <iostream>

//using namespace std;

ConsoleManager::ConsoleManager(){
    system("clear");
}

ConsoleManager::~ConsoleManager(){
    
}

void ConsoleManager::clearConsole(){
    system("clear");
}

void ConsoleManager::draw(string text){
    cout << text << endl;
}

void ConsoleManager::wait(){
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
}

int ConsoleManager::enterNumberOption(){
    int x;
    while(1)
    {
        cout << "Select option: ";
        cin >> x;
        if (!cin.fail()) break;
        cin.clear();
        cin.ignore(10000,'\n');
        cout << "Bad entry.\n";
    }
    return x;
}
