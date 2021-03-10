/**
 * Write a function that takes in an array of integers and returns an array of
 * length 2 representing the largest range of integers contained in that array.
 *
 * The first number in the output array should be the first number in the
 * range, while the second number should be the last number in the range.
 *
 *
 * A range of numbers is defined as a set of numbers that come right after each
 * other in the set of real integers. For instance, the output array [2, 6]
 * represents the range {2, 3, 4, 5, 6}, which is a range of length 5. Note that
 * numbers don't need to be sorted or adjacent in the input array in order to
 * form a range.
 *
 * You can assume that there will only be one largest range.
 *
 * ********************************************
 * OPTIMAL TIME & SPACE COMPLEXITY: O(n) time | O(n) space - where n is the
 * length of the input array
 * ********************************************
 * ***/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// O(n) time and O(n) space
vector<int> largestRange(vector<int> array) {
  vector<int> range;
  int longestLength = 0;
  unordered_map<int, bool> nums = {};

  for (int num : array) {
    nums[num] = true;
  }

  for (int num : array) {
    if (!nums[num]) {
      continue;
    }
    nums[num] = false;
    int currLen = 1;
    int left = num - 1;
    int right = num + 1;
    while (nums.find(left) != nums.end()) {
      nums[left] = false;
      currLen++;
      left--;
    }
    while (nums.find(right) != nums.end()) {
      nums[right] = false;
      currLen++;
      right++;
    }
    if (currLen > longestLength) {
      longestLength = currLen;
      range = {left + 1, right - 1};
    }
  }

  return range;
}

int main() {
  vector<int> array = {1, 11, 3, 0, 15, 5, 2, 4, 10, 7, 12, 6};
  vector<int> ans = largestRange(array);  // 0 7
  for (int x : ans) {
    cout << x << " ";
  }
  cout << endl;

  vector<int> array2 = {1, 1, 1, 3, 4};
  vector<int> ans2 = largestRange(array2);  // 3 4
  for (int x : ans2) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}