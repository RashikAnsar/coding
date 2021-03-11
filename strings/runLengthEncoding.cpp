/***
 * Write a function that takes in a non-empty string and returns its run-length
 * encoding.
 *
 * From Wikipedia, "run-length encoding is a form of lossless data compression
 * in which runs of data are stored as a single data value and count, rather
 * than as the original run." For this problem, a run of data is any sequence of
 * consecutive, identical characters. So the run "AAA" would be
 * run-length-encoded as "3A".
 *
 * To make things more complicated, however, the input string can contain all
 * sorts of special characters, including numbers. And since encoded data must
 * be decodable, this means that we can't naively run-length-encode long runs.
 * For example, the run "AAAAAAAAAAAA" (12 As), can't naively be encoded as
 * "12A", since this string can be decoded as either "AAAAAAAAAAAA" or "1AA".
 * Thus, long runs (runs of 10 or more characters) should be encoded in a split
 * fashion; the aforementioned run should be encoded as "9A3A".
 *
 * ********************************************
 * OPTIMAL TIME & SPACE COMPLEXITY: O(n) time | O(n) space - where n is the
 * length of the input string
 * ********************************************
 * ***/

#include <iostream>
#include <vector>

using namespace std;

string runLengthEncoding(string str) {
  vector<char> encodedStringCharacters;
  int currentRunLength = 1;

  for (int i = 1; i < str.size(); i++) {
    char currentCharacter = str[i];
    char previousCharacter = str[i - 1];

    if (currentCharacter != previousCharacter || currentRunLength == 9) {
      encodedStringCharacters.push_back(to_string(currentRunLength)[0]);
      encodedStringCharacters.push_back(previousCharacter);
      currentRunLength = 0;
    }
    currentRunLength++;
  }

  encodedStringCharacters.push_back(to_string(currentRunLength)[0]);
  encodedStringCharacters.push_back(str[str.size() - 1]);

  string encodedString(encodedStringCharacters.begin(),
                       encodedStringCharacters.end());
  return encodedString;
}

int main() {
  string s = "AAAAAAAAAAAAABBCCCCDD";
  cout << runLengthEncoding(s) << endl;
  string s1 = "1  222 333    444  555";
  cout << runLengthEncoding(s1) << endl;
  string s2 = "AAAAAAAAAAAAABBCCCCDDDDDDDDDDD";
  cout << runLengthEncoding(s2) << endl;
  return 0;
}