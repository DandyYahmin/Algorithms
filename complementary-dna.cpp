/*
    Case from CodeWars:
    Deoxyribonucleic acid (DNA) is a chemical found in the nucleus
    of cells and carries the "instructions" for the development 
    and functioning of living organisms.

    In DNA strings, symbols "A" and "T" are complements of each 
    other, as "C" and "G". Your function receives one side of the 
    DNA (string, except for Haskell); you need to return the other 
    complementary side. DNA strand is never empty or there is no DNA
    at all (again, except for Haskell).
    
    Example: (input --> output)
    "ATTGC" --> "TAACG"
    "GTAT" --> "CATA"
*/

#include <bits/stdc++.h>
#include <string>
using namespace std;

int main() {
    string dna = "ATTGC";
    char slice[dna.length()+1];
    strcpy(slice, dna.c_str());
    for (int i = 0; i < dna.length(); i++) {
        if (slice[i] == 'A') {
            slice[i] = 'T';
        }
        else if (slice[i] == 'T') {
            slice[i] = 'A';
        }
        else if (slice[i] == 'C') {
            slice[i] = 'G';
        }
        else if (slice[i] == 'G') {
            slice[i] = 'C';
        }
    }
    cout << slice;
    return 0;
}

/*
    Lesson:
    - didnt need to convert the string into char array to loop the given word
    - can use switch case instead if else for optimizing the code
*/