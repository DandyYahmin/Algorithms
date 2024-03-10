/*
    Case from CodeWars:
    You are at position [0, 0] in maze NxN and you can only move in 
    one of the four cardinal directions (i.e. North, East, South, 
    West). Return true if you can reach position [N-1, N-1] or false
    otherwise.

    Empty positions are marked ..
    Walls are marked W.
    Start and exit positions are empty in all test cases.
    
    Example: (input-->output)
    ".W.\n.W.\n..." --> true
    "......\n......\n......\n......\n.....W\n....W." --> false
*/
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

bool is_valid_move(const vector<string>& maze, vector<vector<bool>>& visited, int row, int col) {
    int n = maze.size();
    return row >= 0 && row < n && col >= 0 && col < n && maze[row][col] == '.' && !visited[row][col];
}

bool path_finder(string maze_str) {
    vector<string> maze;
    string row = "";
    for (char c : maze_str) {
        if (c == '\n') {
            maze.push_back(row);
            row = "";
        } else {
            row += c;
        }
    }
    maze.push_back(row);

    int n = maze.size();
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;

    vector<pair<int, int>> directions = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();

        int row = current.first;
        int col = current.second;

        if (row == n - 1 && col == n - 1) {
            return true;
        }

        for (const auto& dir : directions) {
            int new_row = row + dir.first;
            int new_col = col + dir.second;
            if (is_valid_move(maze, visited, new_row, new_col)) {
                q.push({new_row, new_col});
                visited[new_row][new_col] = true;
            }
        }
    }

    return false;
}

int main() {
    string maze = ".W.\n.W.\n...";
    cout << boolalpha << path_finder(maze) << endl;

    return 0;
}