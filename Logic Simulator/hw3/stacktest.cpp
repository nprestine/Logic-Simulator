#include <iostream>
#include <fstream>
#include <functional>
#include "stack.h"
#include <string>

using namespace std;



int main(int argc, char* argv[]){
    //create new stack
    Stack<int> test;
    cout << "Expected Output: true" << endl;
    cout << "Real Output: " << boolalpha << test.empty() << endl;
    test.push(69);
    test.push(10);
    cout << "Expected Output: 10" << endl;
    cout << "Real Output: " << test.top() << endl;
    cout << "Expected Output: 2" << endl;
    cout << "Real Output: " << test.size() << endl;
    test.pop();
    cout << "Expected Output: 69" << endl;
    cout << "Real Output: " << test.top() << endl;
    test.pop();
   
    if(argc != 1){
    for(int i = 1; i<argc; i++){
        test.push((stoi(argv[i])));
    }
    cout << "This should print your last commandline number:" << test.top();
    cout << endl << "Input another number ";
    int input;
    cin >> input;
    test.push(input);
    cout << "This should print your input:" << endl;
    cout << test.top() << endl;
    }

    return 0;
    
}
