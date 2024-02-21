/*
    Case from CodeWars:
    Given n, take the sum of the digits of n. If that value has more
    than one digit, continue reducing in this way until a single
    digit number is produced. The input will be a non-negative
    integer.
    
    Example: (input --> output)
    16 --> 1 + 6 = 7
    942 --> 9 + 4 + 2 = 15 --> 1 + 5 = 6
*/
#include <iostream>
using namespace std;

int main() {
    int n = 10;
    string str_n = to_string(n);
    
    while(n > 9) {
        int sum = 0;
        for(char digit : str_n) {
            sum += (digit - '0');
        }
        n = sum;
    }
    cout << n;
    
    return 0;
}