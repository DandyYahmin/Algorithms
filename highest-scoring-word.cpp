/*
    Case from CodeWars:
    Given a string of words, you need to find the highest scoring
    word. Each letter of a word scores points according to its 
    position in the alphabet: a = 1, b = 2, c = 3 etc. You need to 
    return the highest scoring word as a string.

    If two words score the same, return the word that appears 
    earliest in the original string.
    
    For example, the score of abad is 8 (1 + 2 + 1 + 4).
    
    Example: (input-->output):
    "aa b" --> "aa"
    "massage yes massage yes massage" --> "massage"
*/
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    istringstream iss(sentence);
    string word;
    string highestWord;
    int highestScore = 0;

    while (iss >> word) {
        int score = 0;
        for (char c : word) {
            score += c - 'a' + 1;  // Calculate score for each character
        }
        if (score > highestScore) {
            highestScore = score;
            highestWord = word;
        }
    }

    cout << "Highest scoring word: " << highestWord << endl;

    return 0;
}