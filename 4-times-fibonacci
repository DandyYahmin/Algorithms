/*
    Case from CodeWars:
    You`re will be given length of fibonacci. Could you give 
    the sum of 4*(perimeter)

    The function perimeter has for parameter n where n + 1
    (they are numbered from 0 to n) and returns the total perimeter.
    
    Hint:
    - See Fibonacci sequence
    - Fibonacci(5) => 4 * (1 + 1 + 2 + 3 + 5 + 8) => 4 * 20 = 80
    
    Example: (input --> output)
    7 --> 216
    100 --> 6890320871980057904
    
*/
#include <iostream>
using namespace std;

int main() {
    int given_length = 100;
    long long a = 1, b = 1, temporary = 0;
    long long fibonacci = 0;
    for (long long i = 2; i <= given_length; ++i) {
        temporary = a + b;
        fibonacci += temporary;
        a = b;
        b = temporary;
    }
    
    cout << (8+(fibonacci*4));
    return 0;
}