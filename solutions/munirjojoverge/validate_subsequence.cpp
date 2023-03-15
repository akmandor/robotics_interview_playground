/*
##############################################
#          Coding Interview Questions
#      Created/Modified on: July 23, 2019
#           Author: Munir Jojo-Verge
##############################################
 */

/*

Given two non-empty arrays of integers, write a function that determines
whether the second array is a subsequence of the first one.
A subsequence of an array is a set of numbers that aren't necessarily adjacent
in the array but that are in the same order as they appear in the array. For
instance, the numbers [1, 3, 4] form a subsequence of the array
[1, 2, 3, 4], and so do the numbers [2, 4]. Note
that a single number in an array and the array itself are both valid
subsequences of the array.

Sample Input
array = [5, 1, 22, 25, 6, -1, 8, 10]
sequence = [1, 6, -1, 10]

Sample Output
true

*/

#include <iostream>
#include <vector>

using namespace std;

// Wrong solution
bool isValidSubsequence(vector<int> array, vector<int> sequence) {
  int a_curr_idx{0};
  bool result{false};

  for (size_t i = 0; i < sequence.size(); i++) {
    result = false;
    for (size_t j = a_curr_idx; j < array.size(); j++) {
      if (sequence[i] == array[j]) {
        a_curr_idx = j + 1;
        result = true;
        break;
      }
    }
  }

  return result;
}

// Good Solution
bool isValidSubsequence2(vector<int> array, vector<int> sequence) {
  int a_curr_idx{0};
  bool result{false};

  for (size_t i = 0; i < sequence.size(); i++) {
    result = false;
    size_t j = a_curr_idx;
    while ((j < array.size()) && (sequence[i] != array[j])) {
      j++;
    }
    result = (sequence[i] == array[j]);
    a_curr_idx = j + 1;
  }

  return result;
}

// Best Solution: Super Elegant
bool isValidSubsequence3(vector<int> array, vector<int> sequence) {
  int a_curr_idx{0};
  int s_curr_idx{0};

  while (s_curr_idx < sequence.size() && a_curr_idx < array.size()) {
    if (sequence[s_curr_idx] == array[a_curr_idx]) {
      s_curr_idx++;
    }
    a_curr_idx++;
  }
  return (s_curr_idx == sequence.size());
}

int main() {
  vector<int> array{};
  vector<int> sequence{};
  bool expected_result{};

  // Test 1
  array = {5, 1, 22, 25, 6, -1, 8, 10};
  sequence = {1, 6, -1, 10};
  expected_result = true;

  cout << "Test Case 1: ";
  cout << (isValidSubsequence3(array, sequence) == expected_result ? "PASS"
                                                                   : "FAIL")
       << endl;

  array = {5, 1, 22, 25, 6, -1, 8, 10};
  sequence = {5, 1, 22, 25, 6, -1, 8, 10};
  expected_result = true;

  cout << "Test Case 2: ";
  cout << (isValidSubsequence3(array, sequence) == expected_result ? "PASS"
                                                                   : "FAIL")
       << endl;

  array = {5, 1, 22, 25, 6, -1, 8, 10};
  sequence = {4, 5, 1, 22, 25, 6, -1, 8, 10};
  expected_result = false;

  cout << "Test Case 3: ";
  cout << (isValidSubsequence2(array, sequence) == expected_result ? "PASS"
                                                                   : "FAIL")
       << endl;
}