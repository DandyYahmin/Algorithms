/*
    Case from CodeWars:
    Create two functions to encode and then decode a string using 
    the Rail Fence Cipher. This cipher is used to encode a string 
    by placing each character successively in a diagonal along a 
    set of "rails". First start off moving diagonally and down. 
    When you reach the bottom, reverse direction and move 
    diagonally and up until you reach the top rail. Continue until 
    you reach the end of the string. Each "rail" is then read left 
    to right to derive the encoded string.

    For example, the string "WEAREDISCOVEREDFLEEATONCE" could be 
    represented in a three rail system as follows:

    W       E       C       R       L       T       E
      E   R   D   S   O   E   E   F   E   A   O   C  
        A       I       V       D       E       N    
    
    The encoded string would be:
    WECRLTEERDSOEEFEAOCAIVDEN

    Write a function/method that takes 2 arguments, a string and 
    the number of rails, and returns the ENCODED string.

    Write a second function/method that takes 2 arguments, an 
    encoded string and the number of rails, and returns the DECODED
    string.

    For both encoding and decoding, assume number of rails >= 2 and
    that passing an empty string will return an empty string.

    Note that the example above excludes the punctuation and spaces
    just for simplicity. There are, however, tests that include 
    punctuation. Don't filter out punctuation as they are a part of
    the string.
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string railFenceEncode(const string& text, int rails) {
    if (text.empty() || rails < 2)
        return "";

    vector<string> fence(rails);
    int rail = 0;
    bool down = false;

    for (char c : text) {
        fence[rail] += c;
        if (rail == 0 || rail == rails - 1)
            down = !down;
        rail += down ? 1 : -1;
    }

    string encoded;
    for (const string& str : fence)
        encoded += str;

    return encoded;
}

string railFenceDecode(const string& text, int rails) {
    if (text.empty() || rails < 2)
        return "";

    vector<string> fence(rails);
    vector<int> indices(text.length());

    int rail = 0;
    bool down = false;

    for (int i = 0; i < text.length(); ++i) {
        indices[i] = rail;
        fence[rail] += '*';
        if (rail == 0 || rail == rails - 1)
            down = !down;
        rail += down ? 1 : -1;
    }

    int j = 0;
    for (char c : text) {
        fence[indices[j++]] += c;
    }

    string decoded;
    rail = 0;
    down = false;

    for (int i = 0; i < text.length(); ++i) {
        decoded += fence[rail][0];
        fence[rail].erase(0, 1);
        if (rail == 0 || rail == rails - 1)
            down = !down;
        rail += down ? 1 : -1;
    }

    return decoded;
}

int main() {
    string plaintext = "WEAREDISCOVEREDFLEEATONCE";
    int rails = 3;

    string encoded = railFenceEncode(plaintext, rails);
    string decoded = railFenceDecode(encoded, rails);

    cout << "Original: " << plaintext << endl;
    cout << "Encoded: " << encoded << endl;
    cout << "Decoded: " << decoded << endl;

    return 0;
}