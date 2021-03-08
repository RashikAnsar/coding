/***
 * Write a function that takes in an n x m two-dimensional array (that can be
 * square-shaped when n == m) and returns a one-dimensional array of all the
 * array's elements in spiral order.
 *
 * Spiral order starts at the top left corner of the two-dimensional array, goes
 * to the right, and proceeds in a spiral pattern all the way until every
 * element has been visited.
 *
 * ********************************************
 * OPTIMAL TIME & SPACE COMPLEXITY:O(n) time | O(n) space - where n is the total
 * number of elements in the array
 * ********************************************
 * **/

#include <iostream>
#include <vector>

using namespace std;

using namespace std;

// Iterative Solution
vector<int> spiralTraverse(vector<vector<int>> array) {
  int row = array.size(), col = array[0].size();
  int startRow = 0, endRow = row - 1;
  int startCol = 0, endCol = col - 1;
  vector<int> result;
  while (startRow <= endRow && startCol <= endCol) {
    for (int i = startCol; i <= endCol; i++) {
      result.push_back(array[startRow][i]);
    }
    startRow++;

    for (int i = startRow; i <= endRow; i++) {
      result.push_back(array[i][endCol]);
    }
    endCol--;
    if (startRow <= endRow) {
      for (int i = endCol; i >= startCol; i--) {
        result.push_back(array[endRow][i]);
      }
      endRow--;
    }

    if (startCol <= endCol) {
      for (int i = endRow; i >= startRow; i--) {
        result.push_back(array[i][startCol]);
      }
      startCol++;
    }
  }
  return result;
}

// Helper function for Recursive solution
void spiralFill(vector<vector<int>> &array, int startRow, int endRow,
                int startCol, int endCol, vector<int> &result) {
  if (startRow > endRow || startCol > endCol) {
    return;
  }

  for (int i = startCol; i <= endCol; i++) {
    result.push_back(array[startRow][i]);
  }
  startRow++;

  for (int i = startRow; i <= endRow; i++) {
    result.push_back(array[i][endCol]);
  }
  endCol--;

  if (startRow <= endRow) {
    for (int i = endCol; i >= startCol; i--) {
      result.push_back(array[endRow][i]);
    }
    endRow--;
  }

  if (startCol <= endCol) {
    for (int i = endRow; i >= startRow; i--) {
      result.push_back(array[i][startCol]);
    }
    startCol++;
  }
  spiralFill(array, startRow, endRow, startCol, endCol, result);
}

vector<int> spiralTraverse_2(vector<vector<int>> array) {
  vector<int> result;

  if (array.size() == 0) {
    return result;
  }

  spiralFill(array, 0, array.size() - 1, 0, array[0].size() - 1, result);
  return result;
}

int main() {
  vector<vector<int>> array = {{27, 12, 35, 26}, {25, 21, 94, 11},
                               {19, 96, 43, 56}, {55, 36, 10, 18},
                               {96, 83, 31, 94}, {93, 11, 90, 16}};

  vector<int> spiral = spiralTraverse_2(array);
  for (auto i : spiral) {
    cout << i << ", ";
  }
  cout << endl;

  vector<vector<int>> array2 = {
      {1, 2, 3, 4}, {12, 13, 14, 5}, {11, 16, 15, 6}, {10, 9, 8, 7}};
  vector<int> spiral2 = spiralTraverse_2(array2);

  for (auto i : spiral2) {
    cout << i << ", ";
  }
  cout << endl;

  return 0;
}