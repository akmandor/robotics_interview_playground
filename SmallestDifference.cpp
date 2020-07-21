/*
##############################################
#          Coding Interview Questions
#      Created/Modified on: August 23, 2019
#           Author: Munir Jojo-Verge
##############################################
*/

/*

Write a function that takes in two non-empty arrays of integers, finds the
pair of numbers (one from each array) whose absolute difference is closest to
zero, and returns an array containing these two numbers, with the number from
the first array in the first position.
You can assume that there will only be one pair of numbers with the smallest
difference.

Sample Input
arrayOne = [-1, 5, 10, 20, 28, 3]
arrayTwo = [26, 134, 135, 15, 17]

Sample Output
[28, 26]

*/

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

vector<int> smallestDifference(vector<int> A, vector<int> B) {
  // The first thing is to order both arrays.
  // Sorting is by default in ascending order
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());

  int smallest_Diff = INT32_MAX;

  size_t idx_A = 0, idx_B = 0;

  vector<int> smallest_pair;

  while (idx_A < A.size() && idx_B < B.size()) {
    long long int cur_dif;
    if (A[idx_A] == B[idx_B]) {
      return vector<int>{A[idx_A], B[idx_B]};
    } else {
      cur_dif = abs(A[idx_A] - B[idx_B]);

      if (cur_dif < smallest_Diff) {
        smallest_Diff = cur_dif;
        smallest_pair = {A[idx_A], B[idx_B]};
      }

      if (A[idx_A] < B[idx_B]) {
        idx_A++;
      } else {
        idx_B++;
      }
    }
  }
  return smallest_pair;
}

int main() {
  vector<int> expected;

  cout << "Test Case 1: ";
  expected = {20, 17};
  cout << ((smallestDifference({-1, 5, 10, 20, 3}, {26, 134, 135, 15, 17}) ==
            expected)
               ? "PASS"
               : "FAIL")
       << endl;

  cout << "Test Case 2: ";
  expected = {28, 26};
  cout << ((smallestDifference({-1, 5, 10, 20, 28, 3},
                               {26, 134, 135, 15, 17}) == expected)
               ? "PASS"
               : "FAIL")
       << endl;

  cout << "Test Case 3: ";
  expected = {25, 1005};
  cout << ((smallestDifference({10, 0, 20, 25},
                               {1005, 1006, 1014, 1032, 1031}) == expected)
               ? "PASS"
               : "FAIL")
       << endl;

  cout << "Test Case 4: ";
  expected = {25, 1005};
  cout << ((smallestDifference({10, 0, 20, 25, 2200},
                               {1005, 1006, 1014, 1032, 1031}) == expected)
               ? "PASS"
               : "FAIL")
       << endl;

  cout << "Test Case 5: ";
  expected = {2000, 1032};
  cout << ((smallestDifference({10, 0, 20, 25, 2000},
                               {1005, 1006, 1014, 1032, 1031}) == expected)
               ? "PASS"
               : "FAIL")
       << endl;

  cout << "Test Case 6: ";
  expected = {954, 954};
  cout << ((smallestDifference({240, 124, 86, 111, 2, 84, 954, 27, 89},
                               {1, 3, 954, 19, 8}) == expected)
               ? "PASS"
               : "FAIL")
       << endl;

  cout << "Test Case 7: ";
  expected = {20, 21};
  cout << ((smallestDifference({0, 20}, {21, -2}) == expected) ? "PASS"
                                                               : "FAIL")
       << endl;

  cout << "Test Case 8: ";
  expected = {1000, 1014};
  cout << ((smallestDifference({10, 1000}, {-1441, -124, -25, 1014, 1500, 660,
                                            410, 245, 530}) == expected)
               ? "PASS"
               : "FAIL")
       << endl;

  cout << "Test Case 9: ";
  expected = {-123, -124};
  cout << ((smallestDifference(
                {10, 1000, 9124, 2142, 59, 24, 596, 591, 124, -123},
                {-1441, -124, -25, 1014, 1500, 660, 410, 245, 530}) == expected)
               ? "PASS"
               : "FAIL")
       << endl;

  cout << "Test Case 10: ";
  expected = {530, 530};
  cout << ((smallestDifference(
                {10, 1000, 9124, 2142, 59, 24, 596, 591, 124, -123, 530},
                {-1441, -124, -25, 1014, 1500, 660, 410, 245, 530}) == expected)
               ? "PASS"
               : "FAIL")
       << endl;
}
