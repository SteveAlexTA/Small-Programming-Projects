#include<bits/stdc++.h>
using namespace std;
bool nine_row(vector<vector<int>>&matrix, int row, int n) {
    for (int col = 0; col < 9; col++) {
        if (matrix[row][col] == n) return false;
    }
    return true;
}
bool nine_col(vector<vector<int>>&matrix, int col, int n) {
    for (int row = 0; row < 9; row++) {
        if (matrix[row][col] == n) return false;
    }
    return true;
}
bool check_3x3(vector<vector<int>>&matrix, int row, int col, int n) {
    int square_row = (row/3)*3;
    int square_col = (col/3)*3;
    for (int i = square_row; i < square_row+3; i++) {
        for (int j = square_col; j < square_col+3; j++) {
            if (matrix[i][j] == n) return false;
        }
    }
    return true;
}
bool check_valid(vector<vector<int>>& matrix, int row, int col) {
    return matrix[row][col]==0;
}
int main() {
    vector<vector<int>>sudoku(9, vector<int>(9));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> sudoku[i][j];
        }
    }
    int n; cin >> n;
    if (n > 9 || n < 1) {
        cout << "Invalid.";
        return 0;
    }
    int i, j; cin >> i >> j;  
    int row = i-1;
    int col = j-1;
    if (row < 0 || row > 8 || col < 0 || col > 8 || !check_valid(sudoku,row,col)) {
        cout << "Invalid place.";
        return 0;
    }
    if (nine_row(sudoku,row,n) && nine_col(sudoku,col,n) && check_3x3(sudoku,row,col,n) && check_valid(sudoku,row,col)) {
        cout << "Valid place.";
    } else {
        cout << "Invalid place.";
    }
}