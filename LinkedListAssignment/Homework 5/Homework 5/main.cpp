//
//  main.cpp
//  Homework 5
//
//  Created by Darby Rush on 11/9/20.
//  Copyright © 2020 Darby Rush. All rights reserved.
//

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <list>
#include "Linkedlist.h"

using namespace std;

/*
 * detailed points allocation removed.
 * but if your program pass all the test cases here
 * you will get 70/80 points allocated for correctness, efficiecy,
 * design, and testing.
 *
 */
int main(int argc, char** argv) {

    cout  << "1. ---Testing constructor and check function \n";
    Linkedlist list(4);
    list.check();
    list.rcheck();
    cout << "--------------------------------------\n\n" ;

//
    cout  << "2. ---Testing push front 7  \n";
    cout << "before push front: " << endl;
    list.check();
    list.push_front(7);
    list.check();
    list.rcheck();
    cout << "--------------------------------------\n\n" ;

    cout  << "3. ---Testing push back  -1 \n";
    cout << "before push back: " << endl;
    list.check();
    list.push_back(-1);
    list.check();
    list.rcheck();
    cout << "--------------------------------------\n\n" ;

    cout  << "4. ---Testing insert 5 at position 2  \n";
    cout << "before insert: " << endl;
    list.check();
    list.insert(2, 5);
    list.check();
    list.rcheck();
    cout << "--------------------------------------\n\n" ;

    cout  << "5. ---Testing front  \n";
    cout << list.front() << endl;
    list.front() = 1234;
    cout << list.front() << endl;

    cout << "--------------------------------------\n\n" ;

    cout  << "6. ---Testing back  \n";
    cout << list.back() << endl;
    list.back()  = 5678;
    cout << list.back() << endl;

    cout << "--------------------------------------\n\n" ;

    cout  << "7. ---Testing sort  \n";
    cout << "before sort: " << endl;
    list.check();
    list.sort();
    list.check();
    list.rcheck();
    cout << "--------------------------------------\n\n" ;

    return 0;
}
