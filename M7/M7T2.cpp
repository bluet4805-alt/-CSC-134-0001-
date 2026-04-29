// M7T2 - Rectangles 
// with some pointer examples 
// Blue 
// 10-29-26


#include <iostream>
using namespace std; 

int main (){
    string name = "Bob"; 
    string * pName =&name; // pointer, which points to address of name 

    cout << "name  = " << name << endl; 
    cout << "pName = " << pName << endl; 
    cout << "*pName = " << *pName << endl; 

    return 0;
}