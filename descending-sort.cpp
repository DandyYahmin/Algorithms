/*
    Case from PEMATIK Budi Luhur 2023:
    You are going to ask the user to input the length of an array, 
    after that ask the user to input random integer much as the 
    length of the array.
    
    Your task is to sort the array to descending integer.
    
    Example: (input-->output):
    (5){12,6,23,8,17} --> {23,17,12,8,6}
    (4){2,0,7,5} --> {7,5,2,0}
*/
#include <iostream>
using namespace std;

int main() {
    int ordered_arr;
    cout << "How many number do you want? ";
    cin >> ordered_arr;
    int arr[ordered_arr] = {};
    for (int i = 0; i < ordered_arr; i++)
    {
        cout << "insert " << i + 1 << " digit: ";
        cin >> arr[i];
    }

    for (int i = 0; i < ordered_arr - 1; i++) {
        for (int j = 0; j < ordered_arr - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "Numbers in descending order: ";
    for (int i = 0; i < ordered_arr; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}