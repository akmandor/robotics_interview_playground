/*
##############################################
#          Coding Interview Questions
#      Created/Modified on: August 23, 2019
#           Author: Munir Jojo-Verge
##############################################
 */

/*
Write a function that takes in a non-empty array of distinct integers and an
integer representing a target sum. The function should find all triplets in
the array that sum up to the target sum and return a two-dimensional array of
all these triplets. The numbers in each triplet should be ordered in ascending
order, and the triplets themselves should be ordered in ascending order with
respect to the numbers they hold.

If no three numbers sum up to the target sum, the function should return an
empty array.

Sample Input
array = [12, 3, 1, 2, -6, 5, -8, 6]

targetSum = 0

Sample Output
[[-8, 2, 6], [-8, 3, 5], [-6, 1, 5]]

*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
  // This is our output
  vector<vector<int>> triplets;

  // Now we will sort the array. By default sort is in ascending order
  sort(array.begin(), array.end());

  size_t arr_len = array.size();

  for (size_t i = 0; i < arr_len - 2; i++) {
    // We define the Left and Right "pointers"
    size_t L = i + 1;
    size_t R = arr_len - 1;

    while (L < R) {
      long long int sum = array[i] + array[L] + array[R];
      if (sum == targetSum) {
        triplets.push_back({array[i], array[L], array[R]});
        L++;
        R--;
      } else if (sum < targetSum) {
        L++;
      } else {
        R--;
      }
    }
  }

  return triplets;
}
int main() {
  vector<vector<int>> expected;

  cout << "Test Case 1: ";
  expected = {{1, 2, 3}};
  cout << ((threeNumberSum({1, 2, 3}, 6) == expected) ? "PASS" : "FAIL")
       << endl;

  cout << "Test Case 2: ";
  expected = {};
  cout << ((threeNumberSum({1, 2, 3}, 7) == expected) ? "PASS" : "FAIL")
       << endl;

  cout << "Test Case 3: ";
  expected = {{-2, 10, 49}};
  cout << ((threeNumberSum({8, 10, -2, 49, 14}, 57) == expected) ? "PASS"
                                                                 : "FAIL")
       << endl;

  cout << "Test Case 4: ";
  expected = {{-8, 2, 6}, {-8, 3, 5}, {-6, 1, 5}};
  cout << ((threeNumberSum({12, 3, 1, 2, -6, 5, -8, 6}, 0) == expected)
               ? "PASS"
               : "FAIL")
       << endl;

  cout << "Test Case 5: ";
  expected = {{-8, 3, 5}, {-6, 1, 5}, {-1, 0, 1}};
  cout << ((threeNumberSum({12, 3, 1, 2, -6, 5, 0, -8, -1}, 0) == expected)
               ? "PASS"
               : "FAIL")
       << endl;

  cout << "Test Case 6: ";
  expected = {{-8, 2, 6}, {-8, 3, 5}, {-6, 0, 6}, {-6, 1, 5}, {-1, 0, 1}};
  cout << ((threeNumberSum({12, 3, 1, 2, -6, 5, 0, -8, -1, 6}, 0) == expected)
               ? "PASS"
               : "FAIL")
       << endl;

  cout << "Test Case 7: ";
  expected = {{-8, 2, 6},  {-8, 3, 5}, {-6, 0, 6}, {-6, 1, 5},
              {-5, -1, 6}, {-5, 0, 5}, {-5, 2, 3}, {-1, 0, 1}};
  cout << ((threeNumberSum({12, 3, 1, 2, -6, 5, 0, -8, -1, 6, -5}, 0) ==
            expected)
               ? "PASS"
               : "FAIL")
       << endl;

  cout << "Test Case 8: ";
  expected = {{1, 2, 15}, {1, 8, 9}, {2, 7, 9}, {3, 6, 9},
              {3, 7, 8},  {4, 5, 9}, {4, 6, 8}, {5, 6, 7}};
  cout << ((threeNumberSum({1, 2, 3, 4, 5, 6, 7, 8, 9, 15}, 18) == expected)
               ? "PASS"
               : "FAIL")
       << endl;

  cout << "Test Case 9: ";
  expected = {{8, 9, 15}};
  cout << ((threeNumberSum({1, 2, 3, 4, 5, 6, 7, 8, 9, 15}, 32) == expected)
               ? "PASS"
               : "FAIL")
       << endl;

  cout << "Test Case 10: ";
  expected = {};
  cout << ((threeNumberSum({1, 2, 3, 4, 5, 6, 7, 8, 9, 15}, 33) == expected)
               ? "PASS"
               : "FAIL")
       << endl;

  cout << "Test Case 11: ";
  expected = {};
  cout << ((threeNumberSum({1, 2, 3, 4, 5, 6, 7, 8, 9, 15}, 5) == expected)
               ? "PASS"
               : "FAIL")
       << endl;
}
