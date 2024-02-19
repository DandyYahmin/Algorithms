/*
    Case from PEMATIK Budi Luhur 2021:
    You are going to be given an integer. Your job is to return the 
    type of the integer. If the given integer is square, return 
    "square". If not, return "not a square"
    
    Example: (input --> output)
    49 --> "square"
    50 --> "not a square"
*/
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int given_int = 63;
    float sqrt_int = sqrt(given_int);
    if(sqrt_int * sqrt_int == given_int) {
        cout << "square";
    }
    else {
        cout << "not a square";
    }

    return 0;
}