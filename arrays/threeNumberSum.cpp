/**
 * Write a function that takes in a non-empty array of distinct integers and an
 * integer representing a target sum. The function should find all triplets in
 * the array that sum up to the target sum and return a two-dimensional array of
 * all these triplets. The numbers in each triplet should be ordered in
 * ascending order, and the triplets themselves should be ordered in ascending
 * order with respect to the numbers they hold.
 *
 * If there is no three numbers sum up to the target sum, the function should
 * return an empty array.
 *
 * ********************************************
 * OPTIMAL TIME & SPACE COMPLEXITY: O(n^2) time | O(n) space - where n is the
 * length of the input array
 * ********************************************
 * **/

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// O(n^3) and O(n) space
vector<vector<int>> threeNumberSum_1(vector<int> array, int targetSum) {
  sort(array.begin(), array.end());
  vector<vector<int>> ans;
  for (int i = 0; i < array.size(); i++) {
    for (int j = i + 1; j < array.size(); j++) {
      for (int k = j + 1; k < array.size(); k++) {
        int currentSum = array[i] + array[j] + array[k];
        if (currentSum == targetSum) {
          ans.push_back({array[i], array[j], array[k]});
        }
      }
    }
  }
  return ans;
}

// O(n^2) and O(n) space
vector<vector<int>> threeNumberSum_2(vector<int> array, int targetSum) {
  sort(array.begin(), array.end());
  vector<vector<int>> ans;
  for (int i = 0; i < array.size() - 2; i++) {
    int left = i + 1, right = array.size() - 1;
    while (left < right) {
      int currSum = array[i] + array[left] + array[right];
      if (currSum == targetSum) {
        ans.push_back({array[i], array[left], array[right]});
        left++;
        right--;
      } else if (currSum > targetSum) {
        right--;
      } else {
        left++;
      }
    }
  }
  return ans;
}

void printResult(vector<vector<int>> ans) {
  for (auto row : ans) {
    for (int i : row) {
      cout << i << " ";
    }
    cout << endl;
  }

  cout << "-----------------------------" << endl;
}

int main() {
  vector<int> nums = {12, 3, 1, 2, -6, 5, -8, 6};
  int targetSum = 0;
  vector<vector<int>> ans = threeNumberSum_2(nums, targetSum);
  printResult(ans);

  vector<int> nums2 = {8, 10, -2, 49, 14};
  int targetSum2 = 57;
  vector<vector<int>> ans2 = threeNumberSum_2(nums2, targetSum2);

  printResult(ans2);

  return 0;
}