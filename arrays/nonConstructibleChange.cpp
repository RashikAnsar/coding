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