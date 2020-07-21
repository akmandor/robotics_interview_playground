/*
##############################################
#          Coding Interview Questions
#      Created/Modified on: July 11, 2020
#           Author: Munir Jojo-Verge
##############################################
 */

/*
Dothraki are planning an attack to usurp King Robert's throne. King Robert
learns of this conspiracy from Raven and plans to lock the single door through
which the enemy can enter his kingdom.

door

But, to lock the door he needs a key that is an anagram of a palindrome. He
starts to go through his box of strings, checking to see if they can be
rearranged into a palindrome.

For example, given the string , one way it can be arranged into a palindrome is
.

Function Description

Complete the gameOfThrones function below to determine whether a given string
can be rearranged into a palindrome. If it is possible, return YES, otherwise
return NO.

gameOfThrones has the following parameter(s):

s: a string to analyze
Input Format

A single line which contains , the input string.

Constraints

 |s|
 contains only lowercase letters in the range
Output Format

A single line which contains YES or NO.

Sample Input 0

aaabbbb
Sample Output 0

YES
Explanation 0

A palindromic permutation of the given string is bbaaabb.

Sample Input 1

cdefghmnopqrstuvw
Sample Output 1

NO
Explanation 1

Palindromes longer than 1 character are made up of pairs of characters. There
are none here.

Sample Input 2

cdcdcdcdeeeef
Sample Output 2

YES
Explanation 2

An example palindrome from the string: ddcceefeeccdd.
*/
#include <bits/stdc++.h>

using namespace std;

// Complete the gameOfThrones function below.
string gameOfThrones(string s) {
  if (s.length() == 0) {
    return "NO";
  } else if (s.length() == 1) {
    return "YES";
  }

  sort(s.begin(), s.end());
  // You are only allowed to have 0 or 1 characters with an odd number of them
  char c = s[0];
  size_t count_of_c{1};
  size_t odd_count{0};

  for (int i = 1; i < s.size(); i++) {
    if (s[i] == c) {
      ++count_of_c;
    } else {
      if (count_of_c % 2 != 0) {
        ++odd_count;
        if (odd_count > 1) {
          return "NO";
        }
      }
      c = s[i];
      count_of_c = 1;
    }
  }
  return "YES";
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  string s;
  getline(cin, s);

  string result = gameOfThrones(s);

  fout << result << "\n";

  fout.close();

  return 0;
}
