/*
    Case form CodeWars:
    You probably know the "like" system from Facebook and other 
    pages. People can "like" blog posts, pictures or other items. We
    want to create the text that should be displayed next to such an
    item.

    Implement the function which takes an array containing the names
    of people that like an item. It must return the display text as 
    shown in the examples:
    
    Example: (input --> output)
    []                                -->  "no one likes this"
    ["Peter"]                         -->  "Peter likes this"
    ["Jacob", "Alex"]                 -->  "Jacob and Alex like 
    this"
    ["Max", "John", "Mark"]           -->  "Max, John and Mark like 
    this"
    ["Alex", "Jacob", "Mark", "Max"]  -->  "Alex, Jacob and 2 others
    like this"

    Note: For 4 or more names, the number in "and 2 others" simply increases.
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    string likes[] = {"Alex", "Jacob", "Mark", "Max", "Pablo"};
    int size_likes = *(&likes + 1) - likes;
    switch (size_likes) {
        case 0:
            cout << "no one likes this";
            break;
        case 1:
            cout << likes[0] + " likes this";
            break;
        case 2:
            cout << likes[0] + " and " + likes[1] + " like this"; 
            break;
        case 3: 
            cout << likes[0] + ", " + likes[1] +" and " + likes[2] + " like this";
            break;
        default: 
            cout << likes[0] + ", " + likes[1] +" and " + to_string(size_likes-2) + " others like this"; 
            break;
    }
    return 0;
}