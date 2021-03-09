/**
 *  Write a function that takes in a non-empty array of integers and returns an
 * array of the same length, where each element in the output array is equal to
 * the product of every other number in the input array.
 *
 *  In other words, the value at output[i] is equal to the product of every
 * number in the input array other than input[i].
 *
 * Note that you're expected to solve this problem without using division.
 *
 * ********************************************
 * OPTIMAL TIME & SPACE COMPLEXITY: O(n) time | O(n) space - where n is the
 * length of the input array
 * ********************************************
 * **/

#include <iostream>
#include <vector>

using namespace std;

// O(n^2) time and O(n) space
vector<int> arrayOfProducts(vector<int> array) {
  vector<int> result;
  int product = 1;
  for (int i = 0; i < array.size(); i++) {
    for (int j = 0; j < array.size(); j++) {
      if (i == j) {
        continue;
      }
      product *= array[j];
    }
    result.push_back(product);
    product = 1;
  }

  return result;
}

// O(n) time and O(n) space
vector<int> arrayOfProducts_2(vector<int> array) {
  vector<int> product(array.size(), 1);

  int leftRunningProduct = 1;
  for (int i = 0; i < array.size(); i++) {
    product[i] = leftRunningProduct;
    leftRunningProduct *= array[i];
  }

  int rightRunningProduct = 1;
  for (int i = array.size() - 1; i >= 0; i--) {
    product[i] *= rightRunningProduct;
    rightRunningProduct *= array[i];
  }

  return product;
}

int main() {
  vector<int> array = {5, 1, 4, 2};
  vector<int> ans = arrayOfProducts_2(array);

  for (auto i : ans) {
    cout << i << ", ";
  }

  cout << endl;

  vector<int> array2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  vector<int> ans2 = arrayOfProducts_2(array2);
  for (auto i : ans2) {
    cout << i << ", ";
  }

  cout << endl;

  return 0;
}