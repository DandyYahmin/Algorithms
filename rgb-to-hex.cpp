/*
    Case from CodeWars:
    The rgb function is incomplete. Complete it so that passing in 
    RGB decimal values will result in a hexadecimal representation 
    being returned. Valid decimal values for RGB are 0 - 255. Any 
    values that fall out of that range must be rounded to the 
    closest valid value.

    Note: Your answer should always be 6 characters long, the 
    shorthand with 3 will not work here.
    
    Example: (input --> output)
    (255, 255, 255) --> "FFFFFF"
    (255, 255, 300) --> "FFFFFF"
    (0, 0, 0)       --> "000000"
    (148, 0, 211)   --> "9400D3"
*/
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

string rgb(int r, int g, int b) {
    r = min(max(0, r), 255);
    g = min(max(0, g), 255);
    b = min(max(0, b), 255);

    stringstream ss;
    ss << uppercase << setfill('0') << setw(2) << hex << r;
    ss << uppercase << setfill('0') << setw(2) << hex << g;
    ss << uppercase << setfill('0') << setw(2) << hex << b;

    return ss.str();
}

int main() {
    cout << rgb(255, 255, 255) << endl;

    return 0;
}
