/*
    Case from CodeWars:
    You are going to be given a word. Your job is to return the 
    character of the word. If the word's length is odd, return the 
    middle character. If the word's length is even, return the 
    middle 2 characters.
    
    Example: (input --> output)
    "test" --> "es"
    "testing" --> "t"
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    string input = "testing";
    if((input.length()) % 2 == 0) {
        cout << input[input.length() / 2 -1] << input[input.length() / 2];
    }
    else {
        cout << input[input.length() / 2];
    }
    
    return 0;
}