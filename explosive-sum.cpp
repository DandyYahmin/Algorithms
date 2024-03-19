/*
    Case from CodeWars:
    How many ways can you make the sum of a number?

    In number theory and combinatorics, a partition of 
    a positive integer n, also called an integer partition, 
    is a way of writing n as a sum of positive integers. 
    Two sums that differ only in the order of their summands 
    are considered the same partition. If order matters, the 
    sum becomes a composition. For example, 4 can be partitioned 
    in five distinct ways:

    4
    3 + 1
    2 + 2
    2 + 1 + 1
    1 + 1 + 1 + 1
    
    Examples:(input-->output)
    1 --> 1 = 1
    2 --> 2 = 1+1 , 2
    5 --> 7 = 1+1+1+1+1, 1+1+1+2, 1+1+3, 1+2+2, 1+4, 5, 2+3
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n = 100;
    vector<unsigned long long> explosive(n + 1, 0);
    explosive[0] = 1;

    for (unsigned long long i = 1; i <= n; ++i) {
        for (unsigned long long j = i; j <= n; ++j) {
            explosive[j] += explosive[j - i];
        }
    }

    cout << explosive[n];
    
    return 0;
}
