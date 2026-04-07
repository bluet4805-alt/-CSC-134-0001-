#include <iostream>

using namespace std;

// M5T1, Simple Functions
// Blue
// 3-18-26

//Declare our Functions
void say_hello();              // no return
int get_answer();              // returns int
int double_a_num (int number); // int argument, returns int

// Write Main()
int main()
{
    say_hello ();
    cout << "The answer is: " << get_answer() << endl;
    cout << "Type in an integer: ";
    int num;
    cin >> num;
    int answer = double_a_num (num);
    cout << "Double that number is: " << answer << endl;
    return 0;
}

// Define our functions (enter the full code)

void say_hello() {
cout << "Hello World!" << endl;
}

int get_answer() {
return 42;
}

int double_a_num (int number) {
int answer = number * 2;
return answer;
}
