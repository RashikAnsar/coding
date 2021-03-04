/***
 * Write a function that takes in a non-empty array of integers that are sorted
 * in ascending order and returns a new array of the same length with the
 * squares of the original integers also sorted in ascending order.
 *
 * ********************************************
 * OPTIMAL TIME & SPACE COMPLEXITY: O(n) time | O(n) space - where n is the
 * length of the input array
 * ********************************************
 * **/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// O(n log n) time and O(n) space
vector<int> sortedSquaredArray_1(vector<int> array) {
  vector<int> ans;
  for (int num : array) {
    ans.push_back(num * num);
  }
  sort(ans.begin(), ans.end());
  return ans;
}

// O(n) time and O(n) space
vector<int> sortedSquaredArray_2(vector<int> array) {
  vector<int> ans(array.size(), 0);
  int smallestIdx = 0, largestIdx = array.size() - 1;
  for (int i = array.size() - 1; i >= 0; i--) {
    if (abs(array[smallestIdx]) > abs(array[largestIdx])) {
      ans[i] = array[smallestIdx] * array[smallestIdx];
      smallestIdx++;
    } else {
      ans[i] = array[largestIdx] * array[largestIdx];
      largestIdx--;
    }
  }

  return ans;
}

int main() {
  vector<int> arr = {1, 2, 3, 4, 5, 6};
  vector<int> ans = sortedSquaredArray_2(arr);
  for (auto &i : ans) {
    cout << i << " ";
  }

  cout << endl << endl;
  vector<int> arr2 = {-3, -2, -1};
  vector<int> ans2 = sortedSquaredArray_2(arr2);
  for (auto &i : ans2) {
    cout << i << " ";
  }

  return 0;
}