/*
##############################################
#          Coding Interview Questions
#      Created/Modified on: Jun 18, 2020
#           Author: Munir Jojo-Verge
##############################################
 */

/*
Write a function that takes in a non-empty string and that returns a boolean
representing whether the string is a palindrome.


A palindrome is defined as a string that's written the same forward and
backward. Note that single-character strings are palindromes.

Sample Input
string = "abcdcba"

Sample Output
true // it's written the same forward and backward
*/
#include <iostream>
#include <string>

using namespace std;

bool isPalindrome2(string str) {
  // Write your code here.
  size_t num_car = str.length();
  size_t str1_st, str1_end, str2_st, str2_end;
  str1_st = 0;
  str1_end = num_car / 2;
  str2_end = num_car - 1;

  // Let's compare the 2 halves
  size_t i = str1_st;
  bool palindrome = true;
  while (i < str1_end && palindrome) {
    palindrome = (str[str1_st + i] == str[str2_end - i]);
    i++;
  }

  return palindrome;
}

bool isPalindrome(string str) {
  // Write your code here.
  string reverseStr = "", str_half = "";
  int str_len = str.length();
  for (int i = str_len - 1; i >= int(str_len / 2); i--) {
    reverseStr += str[i];
    str_half += str[(str_len - 1) - i];
  }

  return (str_half == reverseStr);
}

int main() {
  string str;
  bool expected;
  bool result;

  cout << "Test Case 1: ";
  str = "abcdefghihgfeddcba";
  expected = false;
  result = isPalindrome(str);
  cout << (result == expected ? "PASS" : "FAIL") << endl;

  cout << "Test Case 2: ";
  str = "abcdefghihgfedcba";
  expected = true;
  result = isPalindrome(str);
  cout << (result == expected ? "PASS" : "FAIL") << endl;

  cout << "Test Case 3: ";
  str = "a";
  expected = true;
  result = isPalindrome(str);
  cout << (result == expected ? "PASS" : "FAIL") << endl;

  cout << "Test Case 4: ";
  str = "ab";
  expected = false;
  result = isPalindrome(str);
  cout << (result == expected ? "PASS" : "FAIL") << endl;

  cout << "Test Case 5: ";
  str = "aba";
  expected = true;
  result = isPalindrome(str);
  cout << (result == expected ? "PASS" : "FAIL") << endl;
}