/*
    Case from CodeWars:
    Write a function that takes an integer as input, and returns the
    number of bits that are equal to one in the binary 
    representation of that number.
    
    Example: (input --> output)
    1234 --> 10011010010 --> 5
    77231418 --> 0100100110100111010100111010 --> 14
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long given_int = 7;
    vector<long long> binary;
    if (given_int == 0) {
        binary.push_back(0);
    }
    while (given_int > 0) {
        binary.push_back(given_int % 2);
        given_int /= 2;
    }
    long long sum = 0;
    for (int i : binary) {
        sum+=i;
    }
    cout << sum;
    return 0;
}