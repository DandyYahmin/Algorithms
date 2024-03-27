/*
    Case from CodeWars:
    We need to sum big numbers and we require your help.

    Write a function that returns the sum of two numbers. The input 
    numbers are strings and the function must return a string.

    Notes:
    The input numbers are big.
    The input is a string of only digits
    The numbers are positives

    Example:(input-->output)
    ("123", "321") --> "444"
    ("11", "99")   --> "110"
*/
#include <iostream>
#include <string>
using namespace std;

string add(const string& num1, const string& num2) {
    string n1 = num1;
    string n2 = num2;

    if (n1.length() < n2.length()) {
        swap(n1, n2);
    }

    int len1 = n1.length();
    int len2 = n2.length();
    int carry = 0;
    string result = "";

    for (int i = 0; i < len1; i++) {
        int digit1 = n1[len1 - 1 - i] - '0';
        int digit2 = i < len2 ? n2[len2 - 1 - i] - '0' : 0;

        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        int digit = sum % 10;

        result.insert(result.begin(), digit + '0');
    }

    if (carry > 0) {
        result.insert(result.begin(), carry + '0');
    }

    return result;
}

int main() {
    cout << add("123", "321") << endl;
    cout << add("11", "99") << endl;
    return 0;
}