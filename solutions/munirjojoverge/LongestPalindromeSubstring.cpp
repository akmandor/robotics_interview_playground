/*
##############################################
#          Coding Interview Questions
#      Created/Modified on: July 22, 2020
#           Author: Munir Jojo-Verge
##############################################
*/

/*

  Write a function that, given a string, returns its longest palindromic
  substring.


  A palindrome is defined as a string that's written the same forward and
  backward. Note that single-character strings are palindromes.

You can assume that there will only be one longest palindromic substring.

Sample Input
string = "abaxyzzyxf"

Sample Output
"xyzzyx"
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> getLongestPalindrome(string str, int leftIdx, int rightIdx) {
  while (leftIdx >= 0 && rightIdx < str.length()) {
    if (str[leftIdx] == str[rightIdx]) {
      --leftIdx;
      ++rightIdx;
    } else
      break;
  }
  return vector<int>{leftIdx + 1, rightIdx};
}

string longestPalindromicSubstring(string str) {
  // Write your code here.
  // The first letter is our longest palindrome so far.
  // Starts at indx 0 and ends at idx 1.
  vector<int> curr_longest{0, 1};  // {ini_idx, end_idx}
  for (int idx = 1; idx < str.length(); ++idx) {
    vector<int> odd = getLongestPalindrome(str, idx - 1, idx + 1);
    vector<int> even = getLongestPalindrome(str, idx - 1, idx);
    vector<int> longest =
        ((odd[1] - odd[0]) > (even[1] - even[0])) ? odd : even;
    curr_longest =
        ((curr_longest[1] - curr_longest[0]) > (longest[1] - longest[0]))
            ? curr_longest
            : longest;
  }
  int num_char = curr_longest[1] - curr_longest[0];
  return str.substr(curr_longest[0], num_char);
}

int main() {
  string str;
  string expected;

  cout << "Test Case 1: ";
  str = "abaxyzzyxf";
  expected = "xyzzyx";
  cout << (longestPalindromicSubstring(str) == expected ? "PASS" : "FAIL")
       << endl;

  cout << "Test Case 2: ";
  str = "a";
  expected = "a";
  cout << (longestPalindromicSubstring(str) == expected ? "PASS" : "FAIL")
       << endl;

  cout << "Test Case 3: ";
  str = "it's highnoon";
  expected = "noon";
  cout << (longestPalindromicSubstring(str) == expected ? "PASS" : "FAIL")
       << endl;

  cout << "Test Case 4: ";
  str = "noon high it is";
  expected = "noon";
  cout << (longestPalindromicSubstring(str) == expected ? "PASS" : "FAIL")
       << endl;

  cout << "Test Case 5: ";
  str = "abccbait's highnoon";
  expected = "abccba";
  cout << (longestPalindromicSubstring(str) == expected ? "PASS" : "FAIL")
       << endl;

  cout << "Test Case 6: ";
  str = "abcdefgfedcbazzzzzzzzzzzzzzzzzzzz";
  expected = "zzzzzzzzzzzzzzzzzzzz";
  cout << (longestPalindromicSubstring(str) == expected ? "PASS" : "FAIL")
       << endl;

  cout << "Test Case 7: ";
  str = "abcdefgfedcba";
  expected = "abcdefgfedcba";
  cout << (longestPalindromicSubstring(str) == expected ? "PASS" : "FAIL")
       << endl;

  cout << "Test Case 8: ";
  str = "abcdefghfedcbaa";
  expected = "aa";
  cout << (longestPalindromicSubstring(str) == expected ? "PASS" : "FAIL")
       << endl;

  cout << "Test Case 9: ";
  str = "zzzzzzz2345abbbba5432zzbbababa";
  expected = "zz2345abbbba5432zz";
  cout << (longestPalindromicSubstring(str) == expected ? "PASS" : "FAIL")
       << endl;

  cout << "Test Case 10: ";
  str = "ab12365456321bb";
  expected = "b12365456321b";
  cout << (longestPalindromicSubstring(str) == expected ? "PASS" : "FAIL")
       << endl;
}