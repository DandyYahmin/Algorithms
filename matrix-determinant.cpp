/*
    Case form CodeWars:
    Write a function that accepts a square matrix (N x N 2D array) 
    and returns the determinant of the matrix.

    How to take the determinant of a matrix -- it is simplest to 
    start with the smallest cases:

    A 1x1 matrix |a| has determinant a.

    A 2x2 matrix [ [a, b], [c, d] ] or

    |a  b|
    |c  d|
    has determinant: a*d - b*c.

    The determinant of an n x n sized matrix is calculated by 
    reducing the problem to the calculation of the determinants of n
    matrices ofn-1 x n-1 size.

    For the 3x3 case, [ [a, b, c], [d, e, f], [g, h, i] ] or

    |a b c|  
    |d e f|  
    |g h i|  
    the determinant is: a * det(a_minor) - b * det(b_minor) + c * det(c_minor) 
    where det(a_minor) refers to taking the determinant
    of the 2x2 matrix created by crossing out the row and column in
    which the element a occurs:

    |- - -|
    |- e f|
    |- h i|  
    Note the alternation of signs.
    
    The determinant of larger matrices are calculated analogously, e.g. 
    if M is a 4x4 matrix with first row [a, b, c, d], then:

    det(M) = a * det(a_minor) - b * det(b_minor) + c * det(c_minor) - d * det(d_minor)
*/
#include <iostream>
#include <vector>

using namespace std;

long long determinant(vector< vector<long long> > m);

long long determinant(vector< vector<long long> > matrix) {
    int n = matrix.size();
    
    if (n == 1) {
        return matrix[0][0];
    }
    
    if (n == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }
    
    long long det = 0;
    for (int i = 0; i < n; ++i) {
        int sign = (i % 2 == 0) ? 1 : -1;
        vector< vector<long long> > minor;
        for (int j = 1; j < n; ++j) {
            vector<long long> row;
            for (int k = 0; k < n; ++k) {
                if (k != i) {
                    row.push_back(matrix[j][k]);
                }
            }
            minor.push_back(row);
        }
        det += sign * matrix[0][i] * determinant(minor);
    }
    
    return det;
}

int main() {
    vector< vector<long long> > matrix_2x2 = {{1, 2}, {3, 4}};
    vector< vector<long long> > matrix_3x3 = {{6, 1, 1}, {4, -2, 5}, {2, 8, 7}};
    vector< vector<long long> > matrix_4x4 = {{1, 0, 2, -1}, {3, 0, 0, 5}, {2, 1, 4, -3}, {1, 0, 5, 0}};

    cout << "Determinant of 2x2 matrix:" << endl;
    cout << determinant(matrix_2x2) << endl;

    cout << "\nDeterminant of 3x3 matrix:" << endl;
    cout << determinant(matrix_3x3) << endl;

    cout << "\nDeterminant of 4x4 matrix:" << endl;
    cout << determinant(matrix_4x4) << endl;

    return 0;
}
