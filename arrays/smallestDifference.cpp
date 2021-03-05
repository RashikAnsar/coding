/***
 *  Write a function that takes in two non-empty arrays of integers, finds the
 * pair of numbers (one from each array) whose absolute difference is closest to
 * zero, and returns an array containing these two numbers, with the number from
 * the first array in the first position.
 *
 * Note that the absolute difference of two integers is the distance between
 * them on the real number line. For example, the absolute difference of -5 and
 * 5 is 10, and the absolute difference of -5 and -4 is 1.
 *
 * You can assume that there will only be one pair of numbers with the smallest
 * difference.
 *
 * ********************************************
 * OPTIMAL TIME & SPACE COMPLEXITY: O(nlog(n) + mlog(m)) time | O(1) space -
 * where n is the length of the first input array and m is the length of the
 * second input array
 * ********************************************
 * **/

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

// O(nlog(n) + mlog(m)) time and O(1) space
vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
  sort(arrayOne.begin(), arrayOne.end());
  sort(arrayTwo.begin(), arrayTwo.end());
  int idxOne = 0, idxTwo = 0;
  int smallest = INT_MAX, current = INT_MAX;
  vector<int> smallestDiffPair;
  while (idxOne < arrayOne.size() && idxTwo < arrayTwo.size()) {
    int firstNum = arrayOne[idxOne], secondNum = arrayTwo[idxTwo];

    if (firstNum > secondNum) {
      current = firstNum - secondNum;
      idxTwo++;
    } else if (firstNum < secondNum) {
      current = secondNum - firstNum;
      idxOne++;
    } else {
      smallestDiffPair = {firstNum, secondNum};
      return smallestDiffPair;
    }

    if (smallest > current) {
      smallest = current;
      smallestDiffPair = {firstNum, secondNum};
    }
  }
  return smallestDiffPair;
}

int main() {
  vector<int> arrayOne{-1, 5, 10, 20, 28, 3};
  vector<int> arrayTwo{26, 134, 135, 15, 17};

  vector<int> ans = smallestDifference(arrayOne, arrayTwo);
  for (auto i : ans) {
    cout << i << " ";
  }

  return 0;
}