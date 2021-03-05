/**
 * Write a function that, given a string, returns its longest palindromic
 * substring.
 *
 * A palindrome is defined as a string that's written the same forward and
 * backward. Note that single-character strings are palindromes.
 *
 * You can assume that there will only be one longest palindromic substring.
 *
 * ********************************************
 * OPTIMAL TIME & SPACE COMPLEXITY: O(n^2) time | O(n) space - where n is the
 * length of the input string
 * ********************************************
 * **/

#include <iostream>
#include <vector>

using namespace std;

using namespace std;

bool isPalindrome(string str) {
  int left = 0, right = str.length() - 1;
  while (left < right) {
    if (str[left] != str[right]) {
      return false;
    }
    left++;
    right--;
  }
  return true;
}

vector<int> getLongestPalindromeFrom(string str, int left, int right) {
  while (left >= 0 && right < str.length()) {
    if (str[left] != str[right]) {
      break;
    }
    left--;
    right++;
  }
  return vector<int>{left + 1, right};
}

// O(n^3) time and  O(n) space
string longestPalindromicSubstring_1(string str) {
  string result = "";
  for (int i = 0; i < str.length(); i++) {
    for (int j = i; j < str.length(); j++) {
      string substring = str.substr(i, j + 1 - i);
      if (substring.length() > result.length() && isPalindrome(substring)) {
        result = substring;
      }
    }
  }
  return result;
}

// O(n^2) time and O(n) space
string longestPalindromicSubstring_2(string str) {
  vector<int> currentLongest{0, 1};
  for (int i = 1; i < str.length(); i++) {
    vector<int> odd = getLongestPalindromeFrom(str, i - 1, i + 1);
    vector<int> even = getLongestPalindromeFrom(str, i - 1, i);
    vector<int> longest = odd[1] - odd[0] > even[1] - even[0] ? odd : even;
    currentLongest =
        currentLongest[1] - currentLongest[0] > longest[1] - longest[0]
            ? currentLongest
            : longest;
  }

  return str.substr(currentLongest[0], currentLongest[1] - currentLongest[0]);
}

int main() {
  string s = "abaxyzzyxf";
  cout << longestPalindromicSubstring_2(s) << endl;
  return 0;
}