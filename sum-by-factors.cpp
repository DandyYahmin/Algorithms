/*
    Case from CodeWars:
    Given an array of positive or negative integers:
    I= [i1,..,in]

    you have to produce a sorted array P of the form

    [ [p, sum of all ij of I for which p is a prime factor (p 
    positive) of ij] ...]

    P will be sorted by increasing order of the prime numbers. The 
    final result has to be given as a string in Java, C#, C, C++ and
    as an array of arrays in other languages.

    Example:
    I = {12, 15}; // result = "(2 12)(3 27)(5 15)"
    
    [2, 3, 5] is the list of all prime factors of the elements of
    hence the result.

    Notes:
    It can happen that a sum is 0 if some numbers are negative!
    Example: I = [15, 30, -45] 5 divides 15, 30 and (-45) so 5 
    appears in the result, the sum of the numbers for which 5 is a 
    factor is 0 so we have [5, 0] in the result amongst others.
*/
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <sstream>
#include <iostream>
using namespace std;

class SumOfDivided
{
public:
    static string sumOfDivided(vector<int>& lst) {
        map<int, int> prime_sums;

        for (int num : lst) {
            if (num != 0) {
                for (int i = 2; i <= abs(num); ++i) {
                    if (isPrime(i) && num % i == 0) {
                        prime_sums[i] += num;
                    }
                }
            }
        }

        stringstream result;
        for (const auto& pair : prime_sums) {
            result << "(" << pair.first << " " << pair.second << ")";
        }

        return result.str();
    }

private:
    static bool isPrime(int num) {
        if (num <= 1) return false;
        if (num <= 3) return true;
        if (num % 2 == 0 || num % 3 == 0) return false;

        for (int i = 5; i * i <= num; i += 6) {
            if (num % i == 0 || num % (i + 2) == 0) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    vector<int> numbers = {12, 15};
    string result = SumOfDivided::sumOfDivided(numbers);
    cout << result << endl;
    return 0;
}