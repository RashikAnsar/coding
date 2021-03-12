/***
 * You're given a string of available characters and a string representing a
 * document that you need to generate. Write a function that determines if you
 * can generate the document using the available characters. If you can generate
 * the document, your function should return true; otherwise, it should return
 * false.
 *
 * You're only able to generate the document if the frequency of unique
 * characters in the characters string is greater than or equal to the frequency
 * of unique characters in the document string. For example, if you're given
 * characters = "abcabc" and document = "aabbccc" you cannot generate the
 * document because you're missing one c.
 *
 * The document that you need to create may contain any characters, including
 * special characters, capital letters, numbers, and spaces.
 *
 * Note: you can always generate the empty string ("").
 *
 * ********************************************
 * OPTIMAL TIME & SPACE COMPLEXITY: O(n + m) time | O(c) space
 * where n is the number of characters, m is the length of the document, and c
 * is the number of unique characters in the characters string
 * ********************************************
 * ***/
#include <iostream>

using namespace std;

int countCharacterFrequency(char character, string target) {
  int frequency = 0;
  for (char c : target) {
    if (c == character) {
      frequency++;
    }
  }
  return frequency;
}

// O(m* (n+m)) time and O(1) space
bool generateDocument(string characters, string document) {
  for (char character : document) {
    int documentFrequency = countCharacterFrequency(character, document);
    int charactersFrequency = countCharacterFrequency(character, characters);
    if (documentFrequency > charactersFrequency) {
      return false;
    }
  }
  return true;
}

int main() {
  string characters = "estssa";
  string document = "testing";

  cout << boolalpha << generateDocument(characters, document) << endl;  // false

  string characters1 = "helloworldO ";
  string document1 = "hello wOrld";
  cout << boolalpha << generateDocument(characters1, document1)
       << endl;  // true

  string characters2 = "&*&you^a%^&8766 _=-09     docanCMakemthisdocument";
  string document2 = "Can you make this document &";
  cout << boolalpha << generateDocument(characters2, document2)
       << endl;  // true
  return 0;
}