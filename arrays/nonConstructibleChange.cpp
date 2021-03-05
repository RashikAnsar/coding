/***
 *  Given an array of positive integers representing the values of coins in your
 * possession, write a function that returns the minimum amount of change (the
 * minimum sum of money) that you cannot create. The given coins can have any
 * positive integer value and aren't necessarily unique (i.e., you can have
 * multiple coins of the same value).
 *
 * For example, if you're given coins = [1, 2, 5], the minimum amount of change
 * that you can't create is 4. If you're given no coins, the minimum amount of
 * change that you can't create is 1.
 *
 * ********************************************
 * OPTIMAL TIME & SPACE COMPLEXITY: O(nlogn) time | O(1) space - where n is the
 * number of coins
 * ********************************************
 * **/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int nonConstructibleChange(vector<int> coins) {
  sort(coins.begin(), coins.end());
  int currentConstructibleChange = 0;
  for (int coin : coins) {
    if (coin > currentConstructibleChange + 1) {
      return currentConstructibleChange + 1;
    }

    currentConstructibleChange += coin;
  }
  return currentConstructibleChange + 1;
}

int main() {
  vector<int> coins = {5, 7, 1, 1, 2, 3, 22};
  cout << nonConstructibleChange(coins) << endl;  // 20

  vector<int> coins2 = {1, 5, 1, 1, 1, 10, 15, 20, 100};
  cout << nonConstructibleChange(coins2) << endl;  // 55

  return 0;
}