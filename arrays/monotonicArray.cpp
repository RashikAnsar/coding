/***
 * Write a function that takes in an array of integers and returns a boolean
 * representing whether the array is monotonic.
 *
 * An array is said to be monotonic if its elements, from left to right, are
 * entirely non-increasing or entirely non-decreasing.
 *
 * Non-increasing elements aren't necessarily exclusively decreasing; they
 * simply don't increase. Similarly, non-decreasing elements aren't necessarily
 * exclusively increasing; they simply don't decrease.
 *
 * Note that empty arrays and arrays of one element are monotonic.
 *
 * ********************************************
 * OPTIMAL TIME & SPACE COMPLEXITY: O(n) time | O(1) space - where n is the
 * length of the array
 * ********************************************
 * **/

#include <iostream>
#include <vector>

using namespace std;

using namespace std;

bool breaksDirection(int direction, int previous, int current) {
  int difference = current - previous;
  if (direction > 0) {
    return difference < 0;
  }
  return difference > 0;
}

bool isMonotonic_1(vector<int> array) {
  if (array.size() <= 2) {
    return true;
  }

  int direction = array[1] - array[0];
  for (int i = 2; i < array.size(); i++) {
    if (direction == 0) {
      direction = array[i] - array[i - 1];
      continue;
    }
    if (breaksDirection(direction, array[i - 1], array[i])) {
      return false;
    }
  }
  return true;
}

bool isMonotonic(vector<int> array) {
  bool isNonDecreasing = true;
  bool isNonIncreasing = true;

  for (int i = 1; i < array.size(); i++) {
    if (array[i] < array[i - 1]) {
      isNonDecreasing = false;
    }
    if (array[i] > array[i - 1]) {
      isNonIncreasing = false;
    }
  }
  return (isNonDecreasing || isNonIncreasing);
}

int main() {
  vector<int> array = {-1, -5, -10, -1100, -1100, -1101, -1102, -9001};
  cout << boolalpha << isMonotonic(array) << endl;  // true
  return 0;
}