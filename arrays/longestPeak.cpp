/**
 * Write a function that takes in an array of integers and returns the length of
 * the longest peak in the array.
 *
 * A peak is defined as adjacent integers in the array that are strictly
 * increasing until they reach a tip (the highest value in the peak), at which
 * point they become strictly decreasing. At least three integers are required
 * to form a peak.
 *
 *
 * For example, the integers 1, 4, 10, 2 form a peak, but the integers 4, 0,
 * 10don't and neither do the integers 1, 2, 2, 0. Similarly, the integers 1, 2,
 * 3 don't form a peak because there aren't any strictly decreasing integers
 * after the 3.
 *
 * ********************************************
 * OPTIMAL TIME & SPACE COMPLEXITY: O(n) time | O(1) space - where n is the
 * length of the input array
 * ********************************************
 * ***/

#include <iostream>
#include <vector>

using namespace std;

int longestPeak(vector<int> array) {
  int longestPeakLength = 0;
  int i = 1;

  while (i < (array.size() - 1)) {
    bool isPeak = array[i] > array[i - 1] && array[i] > array[i + 1];
    if (!isPeak) {
      i++;
      continue;
    }

    int leftIdx = i - 2, rightIdx = i + 2;
    while (leftIdx >= 0 && array[leftIdx] < array[leftIdx + 1]) {
      leftIdx--;
    }

    while (rightIdx < array.size() && array[rightIdx] < array[rightIdx - 1]) {
      rightIdx++;
    }

    int currentPeakLength = rightIdx - leftIdx - 1;
    longestPeakLength = max(longestPeakLength, currentPeakLength);
    i = rightIdx;
  }

  return longestPeakLength;
}

int main() {
  vector<int> array = {1, 2, 3, 3, 4, 0, 10, 6, 5, -1, -3, 2, 3};
  cout << longestPeak(array) << endl;  // 6
  vector<int> array2 = {5, 4, 3, 2, 1, 2, 10, 12, -3, 5, 6, 7, 10};
  cout << longestPeak(array2) << endl;  // 5

  return 0;
}