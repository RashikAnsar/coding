/**
 *
 *  Write a function that takes in a non-empty array of distinct integers and an
 * integer representing a target sum. The function should find all quadruplets
 * in the array that sum up to the target sum and return a two-dimensional array
 * of all these quadruplets in no particular order.
 *
 * If no four numbers sum up to the target sum, the function should return an
 * empty array.
 *
 * ********************************************
 * Average: O(n^2) time | O(n^2) space - where n is the length of the input
 * array
 *
 * Worst: O(n^3) time | O(n^2) space - where n is the length of the input array
 * ********************************************
 * **/
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// Average: O(n^2) time and  O(n^2) space
// Worst: O(n^3) time and  O(n^2) space
vector<vector<int>> fourNumberSum(vector<int> array, int targetSum) {
  unordered_map<int, vector<vector<int>>> allPairSums;
  vector<vector<int>> result{};

  for (int i = 1; i < array.size() - 1; i++) {
    for (int j = i + 1; j < array.size(); j++) {
      int currSum = array[i] + array[j];
      int diff = targetSum - currSum;
      if (allPairSums.find(diff) != allPairSums.end()) {
        for (vector<int> pairs : allPairSums[diff]) {
          pairs.push_back(array[i]);
          pairs.push_back(array[j]);
          result.push_back(pairs);
        }
      }
    }

    for (int k = 0; k < i; k++) {
      int currSum = array[i] + array[k];
      if (allPairSums.find(currSum) == allPairSums.end()) {
        allPairSums[currSum] = vector<vector<int>>{{array[k], array[i]}};
      } else {
        allPairSums[currSum].push_back(vector<int>{array[k], array[i]});
      }
    }
  }
  return result;
}

int main() {
  vector<int> array = {7, 6, 4, -1, 1, 2};
  int targetSum = 16;
  vector<vector<int>> result = fourNumberSum(array, targetSum);
  for (auto lists : result) {
    for (auto list : lists) {
      cout << list << ", ";
    }
    cout << endl;
  }

  vector<int> array2 = {-2, -1, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int targetSum2 = 4;
  vector<vector<int>> result2 = fourNumberSum(array2, targetSum2);

  for (auto lists : result2) {
    for (auto list : lists) {
      cout << list << ", ";
    }
    cout << endl;
  }

  return 0;
}