/*
    Case from CodeWars:
    Basically you have to assume that n people are put into a circle
    and that they are eliminated in steps of k elements, like this:

    n=7, k=3 => means 7 people in a circle
    one every 3 is eliminated until one remains
    [1,2,3,4,5,6,7] - initial sequence
    [1,2,4,5,6,7] => 3 is counted out
    [1,2,4,5,7] => 6 is counted out
    [1,4,5,7] => 2 is counted out
    [1,4,5] => 7 is counted out
    [1,4] => 5 is counted out
    [4] => 1 counted out, 4 is the last element - the survivor!

    The above example description will give you a more thorough 
    insight about the origin of this kind of permutation, but 
    basically that's all that there is to know to solve this.
    
    Example: (input-->output)
    (n=11, k=19) --> 10
    (n=14, k=2) --> 13
*/
#include <iostream>
using namespace std;

int main() {
    int n, k;
    cout << "Enter the number of people (n): ";
    cin >> n;
    cout << "Enter the step (k): ";
    cin >> k;

    int survivor = 1;

    for (int i = 2; i <= n; ++i) {
        survivor = (survivor + k - 1) % i + 1;
    }

    cout << "The survivor is: " << survivor << endl;

    return 0;
}