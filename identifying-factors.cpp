/*
    Case from PEMATIK Budi Luhur 2023:
    You are going to be given an integer. Your job is to identify 
    factors from the given integer beyond number 1 and the number 
    itself. If the given integer have factors, return the factors
    number. If not, return "None"
    
    Example: (input --> output)
    17 --> "None"
    20 --> "2 4 5 10"
*/
#include <iostream>
using namespace std;

int main() {
    int given_int = 20;
    bool flag = true;
    
    if(given_int < 2) {
        flag = false;
    }else {
        for (int i = 2; i < given_int; i++) {
            if(given_int % i == 0) {
                flag = false;
                cout << i << " ";
            }
        }   
    }
    
    if(flag) {
        cout << "None" << endl;
    }
    
    return 0;
}