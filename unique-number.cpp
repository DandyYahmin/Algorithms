/*
    Case from CodeWars:
    You will be given an array with some numbers. All numbers are 
    equal except for one. Try to find the number and the index 
    located different one!
    
    Example: (input --> output)
    {1, 1, 1, 2, 1, 1} --> 2 at index 4
    {0, 0, 0.55, 0, 0} --> 0.55 at index 2
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<float> v = {1,1,1,1,2,1};

    for (size_t i = 0; i < v.size(); ++i) {
        if(v[i] != v[i+1]) {
            if(v[i] != v[i+2]){
                cout << v[i] << " at index " << i;
                return 0;
            }
        }
    }
    
    return 0;
}