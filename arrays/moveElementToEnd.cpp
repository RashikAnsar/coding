/**
 * You're given an array of integers and an integer. Write a function that moves
 * all instances of that integer in the array to the end of the array and
 * returns the array.
 *
 * The function should perform this in place (i.e., it should mutate the input
 * array) and doesn't need to maintain the order of the other integers.
 *
 *
 * ********************************************
 * OPTIMAL TIME & SPACE COMPLEXITY: O(n) time and O(1) space - where n is the
 * length of the array
 * ********************************************
 * **/

#include <iostream>
#include <vector>

using namespace std;

// O(n) time and O(1) space
vector<int> moveElementToEnd_2(vector<int> array, int toMove) {
  int i = 0, j = array.size() - 1;
  while (i < j) {
    while (i < j && array[j] == toMove) {
      j--;
    }

    if (array[i] == toMove) {
      swap(array[i], array[j]);
    }
    i++;
  }
  return array;
}

// O(n) time and O(1) space
vector<int> moveElementToEnd(vector<int> array, int toMove) {
  int count = 0;

  for (int i = 0; i < array.size(); i++) {
    if (array[i] != toMove) {
      array[count++] = array[i];
    }
  }

  while (count < array.size()) {
    array[count++] = toMove;
  }
  return array;
}

int main() {
  vector<int> array{2, 1, 2, 2, 2, 3, 4, 2};
  int k = 2;
  //   vector<int> ans = {}
  vector<int> ans = moveElementToEnd(array, k);
  for (auto i : ans) {
    cout << i << " ";
  }

  return 0;
}
