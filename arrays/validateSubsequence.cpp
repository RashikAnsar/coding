/**
 * Given two non-empty arrays of integers, write a function that determines
 * whether the second array is a subsequence of the first one.
 *
 * A subsequence of an array is a set of numbers that aren't necessarily
 * adjacent in the array but that are in the same order as they appear in the
 * array. For instance, the numbers [1, 3, 4] form a subsequence of the array
 * [1, 2, 3, 4] , and so do the numbers [2, 4]. Note that a single number in an
 * array and the array itself are both valid subsequences of the array.
 *
 * ********************************************
 * OPTIMAL TIME & SPACE COMPLEXITY: O(n) time | O(1) space - where n is the
 *length of the input array
 * *******************************************
 * **/

#include <iostream>
#include <vector>

using namespace std;

// O(n) and O(1) space
bool isValidSubsequence(vector<int> array, vector<int> sequence) {
  int seqIdx = 0;
  for (int i = 0; i < array.size(); i++) {
    if (seqIdx == sequence.size()) {
      return true;
    }
    if (sequence[seqIdx] == array[i]) {
      seqIdx++;
    }
  }

  return (sequence.size() == seqIdx);
}

int main() {
  vector<int> arr = {5, 1, 22, 25, 6, -1, 8, 10};
  vector<int> subSq = {1, 6, -1, 10};
  bool ans = isValidSubsequence(arr, subSq);
  cout << boolalpha << ans << endl;
  return 0;
}