/*
    Case from CodeWars:
    Write a program called sumIntervals/sum_intervals that accepts 
    an array of intervals, and returns the sum of all the interval 
    lengths. Overlapping intervals should only be counted once.

    Intervals
    Intervals are represented by a pair of integers in the form of 
    an array. The first value of the interval will always be less 
    than the second value. Interval example: [1, 5] is an interval 
    from 1 to 5. The length of this interval is 4.

    Overlapping Intervals
    List containing overlapping intervals:

    {{1, 4}, {7, 10}, {3, 5}}

    The sum of the lengths of these intervals is 7. Since [1, 4] and
    [3, 5] overlap, we can treat the interval as [1, 5], which has a
    length of 4.
    
    Example: (input-->output)
    {{1, 5}, {6, 10}} --> 8
    {{0, 20}, {-100000000, 10}, {30, 50}} --> 100000030
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<pair<int, int>> intervals = {{1, 4}, {7, 10}, {3, 5}};
    std::sort(intervals.begin(), intervals.end());

    int totalLength = 0;
    int currentStart = intervals[0].first;
    int currentEnd = intervals[0].second;

    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i].first <= currentEnd) {
            currentEnd = std::max(currentEnd, intervals[i].second);
        } else {
            totalLength += currentEnd - currentStart;
            currentStart = intervals[i].first;
            currentEnd = intervals[i].second;
        }
    }

    totalLength += currentEnd - currentStart;
    
    cout << totalLength;
    return 0;
}