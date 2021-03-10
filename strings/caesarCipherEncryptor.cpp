/****
 * Given a non-empty string of lowercase letters and a non-negative integer
 * representing a key, write a function that returns a new string obtained by
 * shifting every letter in the input string by k positions in the alphabet,
 * where k is the key.
 *
 *
 * Note that letters should "wrap" around the alphabet; in other words, the
 * letter z shifted by one returns the letter a
 *
 *
 * ********************************************
 * OPTIMAL TIME & SPACE COMPLEXITY: O(n) time | O(n) space - where n is the
 * length of the input string
 * ********************************************
 * ***/

#include <iostream>
#include <vector>

using namespace std;

string caesarCypherEncryptor_1(string str, int key) {
  char ch;
  string ans = "";
  for (int i = 0; i < str.size(); i++) {
    ch = str[i] + key;
    if (ch > 'z') {
      ch = ch - 'z' + 'a' - 1;
    }
    ans += ch;
  }
  return ans;
}

char getNewLetter(char letter, int key) {
  int newLetterCode = letter + key;
  return newLetterCode <= 122 ? newLetterCode : 96 + newLetterCode % 122;
}

string caesarCypherEncryptor(string str, int key) {
  vector<char> newLetters;
  int newKey = key % 26;
  for (int i = 0; i < str.length(); i++) {
    newLetters.push_back(getNewLetter(str[i], newKey));
  }

  return string(newLetters.begin(), newLetters.end());
}

int main() {
  string x = "xyz";
  int key = 2;
  cout << caesarCypherEncryptor(x, key) << endl;
  return 0;
}