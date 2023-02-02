//
//  main.cpp
//  test
//
//  Created by Darby Rush on 11/13/20.
//  Copyright © 2020 Darby Rush. All rights reserved.
//

#include <iostream>
using namespace std;

int f(int n){
    int x=0;
    cout << x << "++" << n << endl;
    if(n <= 0)
        return 1;
    x = f(n-2);
    x = 2*x;
    cout << x << "++" << n << endl;
    return x;
}


int main() {
 
    int y;
    y =f(7);
    cout << y << endl;
        
    return 0;
}
