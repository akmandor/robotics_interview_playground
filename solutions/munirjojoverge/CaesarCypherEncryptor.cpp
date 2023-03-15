
/*
##############################################
#          Coding Interview Questions
#      Created/Modified on: Jun 18, 2020
#           Author: Munir Jojo-Verge
##############################################
*/

/*

Given a non-empty string of lowercase letters and a non-negative integer
representing a key, write a function that returns a new string obtained by
shifting every letter in the input string by k positions in the alphabet,
where k is the key.


Note that letters should "wrap" around the alphabet; in other words, the
letter z shifted by one returns the letter a.

Sample Input
string = "xyz"
key = 2

Sample Output
"zab"

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string caesarCypherEncryptor(string str, int key) {
  // Write your code here.
  vector<char> output(str.length());
  // string output;
  key = key % 26;
  for (size_t i = 0; i < str.length(); i++) {
    output[i] = str[i] + key;
    if (output[i] > 'z') output[i] = 'a' + (output[i] % 'z') - 1;
  }
  return string(output.begin(), output.end());
}

int main() {
  string str;
  int key;
  string expected;
  string result;

  cout << "Test Case 1: ";
  str = "xyz";
  key = 2;
  expected = "zab";
  result = caesarCypherEncryptor(str, key);
  cout << (result == expected ? "PASS" : "FAIL") << endl;

  cout << "Test Case 2: ";
  str = "abc";
  key = 0;
  expected = "abc";
  result = caesarCypherEncryptor(str, key);
  cout << (result == expected ? "PASS" : "FAIL") << endl;

  cout << "Test Case 3: ";
  str = "abc";
  key = 3;
  expected = "def";
  result = caesarCypherEncryptor(str, key);
  cout << (result == expected ? "PASS" : "FAIL") << endl;

  cout << "Test Case 4: ";
  str = "xyz";
  key = 5;
  expected = "cde";
  result = caesarCypherEncryptor(str, key);
  cout << (result == expected ? "PASS" : "FAIL") << endl;

  cout << "Test Case 5: ";
  str = "abc";
  key = 26;
  expected = "abc";
  result = caesarCypherEncryptor(str, key);
  cout << (result == expected ? "PASS" : "FAIL") << endl;

  cout << "Test Case 6: ";
  str = "abc";
  key = 52;
  expected = "abc";
  result = caesarCypherEncryptor(str, key);
  cout << (result == expected ? "PASS" : "FAIL") << endl;

  cout << "Test Case 7: ";
  str = "abc";
  key = 57;
  expected = "fgh";
  result = caesarCypherEncryptor(str, key);
  cout << (result == expected ? "PASS" : "FAIL") << endl;
}