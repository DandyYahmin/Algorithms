/*
    Case from CodeWars:
    You are given an array containing integers. The array is either 
    entirely comprised of odd integers or entirely comprised of even
    integers, except for a single integer. Write a method that takes 
    the array as an argument and returns this "outlier"
    
    Exmaple: (input --> output)
    {2, 4, 0, 100, 4, 11, 2602, 36} --> 11
    {160, 3, 1719, 19, 11, 13, -21} --> 160
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> given_arr = {17, 6, 8, 10, 6, 12, 24, 36};
    int count_even = 0, count_odd = 0;
    int even_number = 0, odd_number = 0;

    for (int num : given_arr) {
        if (num % 2 == 0) {
            count_even++;
            even_number = num;
        } else {
            count_odd++;
            odd_number = num;
        }
    }

    if (count_even == 1) {
        cout << even_number;
    } else {
        cout << odd_number;
    }
    
    return 0;
}