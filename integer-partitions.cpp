/*
    Case from CodeWars:
    An integer partition of n is a weakly decreasing list of 
    positive integers which sum to n.

    For example, there are 7 integer partitions of 5:

    [5], [4,1], [3,2], [3,1,1], [2,2,1], [2,1,1,1], [1,1,1,1,1].

    Write a function which returns the number of integer 
    partitions of n. The function should be able to find the 
    number of integer partitions of n for n at least as large
    as 100.

    Example:(input-->output)
    5 --> 7
    25 --> 1958
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n = 25;
    vector<unsigned long long int> ip(n + 1);
    ip[0] = 1;  
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            ip[j] += ip[j - i];
        }
    }
    
    cout << ip[n];
    
    return 0;
}
