/*
=========================================================
Problem: Valid Sudoku (LeetCode 36)
Topic: HashSet, Matrix
Difficulty: Medium

Approach:
1. Traverse each row using an unordered_set.
2. Ignore empty cells ('.').
3. If a digit is already present in the row set, return false.
4. Repeat the same process for every column.
5. Traverse each 3×3 sub-box separately.
6. For every box:
      startRow = (box / 3) * 3
      startCol = (box % 3) * 3
7. Check duplicates inside the box using another unordered_set.
8. If all rows, columns and boxes are valid, return true.

Time Complexity: O(1)
(Generalized Sudoku: O(N²))

Space Complexity: O(1)
(Generalized Sudoku: O(N))

Key Learning:
- unordered_set is useful for duplicate detection.
- Reset the HashSet after checking each row, column and box.
- Ignore '.' since it represents an empty cell.
- The formulas
      startRow = (box / 3) * 3
      startCol = (box % 3) * 3
  help locate every 3×3 sub-box efficiently.
=========================================================
*/
#include<iostream>
#include<vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            unordered_set<char> dup;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    continue;
                } else if (dup.count(board[i][j])) {
                    return false;
                } else {
                    dup.insert(board[i][j]);
                }
            }
        }
        for (int i = 0; i < 9; i++) {
            unordered_set<char> dup;
            for (int j = 0; j < 9; j++) {
                if (board[j][i] == '.') {
                    continue;
                } else if (dup.count(board[j][i])) {
                    return false;
                } else {
                    dup.insert(board[j][i]);
                }
            }
        }

        for (int box = 0; box < 9; box++) {

            unordered_set<char> dup;

            int startRow = (box / 3) * 3;
            int startCol = (box % 3) * 3;

            for (int i = startRow; i < startRow + 3; i++) {
                for (int j = startCol; j < startCol + 3; j++) {

                    if (board[i][j] == '.') {
                        continue;
                    }

                    if (dup.count(board[i][j])) {
                        return false;
                    }

                    dup.insert(board[i][j]);
                }
            }
        }
        return true;
    }
};