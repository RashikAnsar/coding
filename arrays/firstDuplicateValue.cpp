/**
 * Given an array of integers between 1 and n, inclusive, where n is the length
 * of the array, write a function that returns the first integer that appears
 * more than once (when the array is read from left to right).
 *
 * In other words, out of all the integers that might occur more than once in
 * the input array, your function should return the one whose first duplicate
 * value has the minimum index.
 *
 * If no integer appears more than once, your function should return -1.
 *
 * Note that you're allowed to mutate the input array.
 *
 * ********************************************
 * OPTIMAL TIME & SPACE COMPLEXITY: O(n) time | O(1) space - where n is the
 * length of the input array
 * ********************************************
 * **/

#include <climits>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// O(n^2) time and O(1) space
int firstDuplicateValue_1(vector<int> array) {
  int minIndex = INT_MAX;
  for (int i = 0; i < array.size(); i++) {
    for (int j = i + 1; j < array.size(); j++) {
      if (array[i] == array[j]) {
        minIndex = min(minIndex, j);
      }
    }
  }
  if (minIndex != INT_MAX) {
    return array[minIndex];
  }
  return -1;
}

// O(n) time and O(n) space
int firstDuplicateValue_2(vector<int> array) {
  unordered_map<int, bool> nums;

  for (int value : array) {
    if (nums.find(value) != nums.end()) {
      return value;
    }
    nums[value] = true;
  }

  return -1;
}

// O(n) time and O(1) space
int firstDuplicateValue(vector<int> array) {
  for (int value : array) {
    int absValue = abs(value);
    if (array[absValue - 1] < 0) {
      return absValue;
    }
    array[absValue - 1] *= -1;
  }
  return -1;
}

int main() {
  vector<vector<int>> arrays = {
      {2, 1, 5, 2, 3, 3, 4}, {2, 1, 5, 3, 3, 2, 4}, {1, 2, 3, 4, 5, 6}};

  for (int i = 0; i < arrays.size(); i++) {
    cout << firstDuplicateValue(arrays[i]) << endl;
  }

  return 0;
}