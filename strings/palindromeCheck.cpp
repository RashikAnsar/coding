/**
 * Write a function that takes in a non-empty string and that returns a boolean
 * representing whether the string is a palindrome.
 *
 * A palindrome is defined as a string that's written the same forward and
 * backward. Note that single-character strings are palindromes.
 *
 * ********************************************
 * OPTIMAL TIME & SPACE COMPLEXITY: O(n) time | O(1) space - where n is the
 * length of the input string
 * ********************************************
 * **/

#include <iostream>

using namespace std;

// O(n^2) and O(n) space
bool isPalindrome_1(string str) {
  string reversedString = "";
  for (int i = str.size() - 1; i >= 0; i--) {
    reversedString += str[i];
  }

  return reversedString == str;
}

// O(n) time and O(1) space
bool isPalindrome(string str) {
  int left = 0, right = str.size() - 1;

  while (left < right) {
    if (str[left] != str[right]) {
      return false;
    }
    left++;
    right--;
  }
  return true;
}

int main() {
  string s = "abcba";
  cout << boolalpha << isPalindrome(s) << endl;

  string p = "MOM";
  cout << boolalpha << isPalindrome(p) << endl;

  string q = "sample test";
  cout << boolalpha << isPalindrome(q) << endl;
  return 0;
}