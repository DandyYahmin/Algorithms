/*
    Case from PEMATIK Budi Luhur 2023:
    You will be given an integer alue which represents the unit of seconds
    then convert the integer units into units of hours, minutes and seconds

    Example: (input --> output)
    7425 --> 2 Hours 3 Minutes 45 Seconds
*/
#include <iostream>
using namespace std;
int main()
{
    int given_int = 7425 ;
    cout << given_int / 3600 << " Hours ";
    cout << (given_int % 3600) / 60 << " Minutes ";
    cout << (given_int % 3600) % 60 << " Seconds ";
    return 0;
}