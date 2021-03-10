/***
 * Write a function that takes in an array of at least two integers and that
 * returns an array of the starting and ending indices of the smallest subarray
 * in the input array that needs to be sorted in place in order for the entire
 * input array to be sorted (in ascending order).
 *
 * If the input array is already sorted, the function should return [-1, -1].
 *
 * ********************************************
 * OPTIMAL TIME & SPACE COMPLEXITY: O(n) time | O(1) space - where n is the
 * length of the input array
 * ********************************************
 * ***/

#include <climits>
#include <iostream>
#include <vector>

using namespace std;

bool isOutOfOrder(int i, int num, vector<int> array) {
  if (i == 0) {
    return num > array[i + 1];
  }
  if (i == array.size() - 1) {
    return num < array[i - 1];
  }
  return num > array[i + 1] || num < array[i - 1];
}

vector<int> subarraySort(vector<int> array) {
  int minOutOfOrder = INT_MAX;
  int maxOutOfOrder = INT_MIN;

  for (int i = 0; i < array.size(); i++) {
    int num = array[i];
    if (isOutOfOrder(i, num, array)) {
      minOutOfOrder = min(minOutOfOrder, num);
      maxOutOfOrder = max(maxOutOfOrder, num);
    }
  }

  if (minOutOfOrder == INT_MAX) {
    return vector<int>{-1, -1};
  }

  int subArrayLeftIdx = 0, subArrayRightIdx = array.size() - 1;
  while (minOutOfOrder >= array[subArrayLeftIdx]) {
    subArrayLeftIdx++;
  }

  while (maxOutOfOrder <= array[subArrayRightIdx]) {
    subArrayRightIdx--;
  }

  return vector<int>{subArrayLeftIdx, subArrayRightIdx};
}

int main() {
  vector<int> array = {1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19};
  vector<int> result = subarraySort(array);  // 3, 9
  for (int x : result) {
    cout << x << ", ";
  }
  cout << endl;
  vector<int> array2 = {4, 8, 7, 12, 11, 9, -1, 3, 9, 16, -15, 51, 7};
  vector<int> result2 = subarraySort(array2);  // 0, 12
  for (int x : result2) {
    cout << x << ", ";
  }

  return 0;
}