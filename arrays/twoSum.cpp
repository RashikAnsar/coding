/***
 *
 * Write a function that takes in a non-empty array of distinct integers and an
 * integer representing a target sum. If any two numbers in the input array sum
 * up to the target sum, the function should return them in an array, in any
 * order. If no two numbers sum up to the target sum, the function should return
 * an empty array.
 *
 * Note that the target sum has to be obtained by summing two different integers
 * in the array; you can't add a single integer to itself in order to obtain the
 * target sum.
 *
 * You can assume that there will be at most one pair of numbers summing up to
 * the target sum.
 *
 * ********************************************
 * OPTIMAL TIME & SPACE COMPLEXITY: O(n) time | O(n) space - where n is the
 *length of the input array
 * *******************************************
 ***/

#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

// O(n^2) time and O(1) space
vector<int> twoNumberSum_1(vector<int> array, int targetSum) {
  vector<int> result;
  for (int i = 0; i < array.size(); i++) {
    for (int j = i + 1; j < array.size(); j++) {
      if (array[i] + array[j] == targetSum) {
        result.push_back(array[i]);
        result.push_back(array[j]);
        return result;
      }
    }
  }
  return result;
}

// O(n log n) time and O(1) space
vector<int> twoNumberSum_2(vector<int> array, int targetSum) {
  vector<int> result;
  sort(array.begin(), array.end());

  int i = 0, j = array.size() - 1;

  while (i <= j) {
    if (array[i] + array[j] == targetSum) {
      result.push_back(array[i]);
      result.push_back(array[j]);
      return result;
    } else if (array[i] + array[j] < targetSum) {
      i++;
    } else {
      j--;
    }
  }
  return result;
}

// O(n) and O(n) space
vector<int> twoNumberSum_3(vector<int> array, int targetSum) {
  vector<int> result;
  unordered_set<int> nums;

  for (int i = 0; i < array.size(); i++) {
    int required = targetSum - array[i];
    if (nums.find(required) != nums.end()) {
      result.push_back(array[i]);
      result.push_back(required);
      return result;
    } else {
      nums.insert(array[i]);
    }
  }
  return result;
}

int main() {
  vector<int> v = {3, 5, -4, 8, 11, 1, -1, 6};
  int target = 10;

  vector<int> ans = twoNumberSum_3(v, target);

  for (auto &i : ans) {
    cout << i << " ";
  }

  return 0;
}