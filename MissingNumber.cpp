/*
##############################################
#          Coding Interview Questions
#      Created/Modified on: August 23, 2019
#           Author: Munir Jojo-Verge
##############################################
 */

/*
Given a list of n+1 integers and these integers are in the range of 0 to n.
There are no duplicates in list. One of the integers is missing in the list.
Write an efficient code to find the missing integer.

Examples:

Input : arr = {0, 1, 2, 3, 4, 6, 7, 8, 9}
Output : 5

Input : arr = {0, 1, 2, 3, 4, 5, 6, 8, 9}
Output : 7

What happened if we miss the edges??
*/

#include <iostream>
#include <vector>
using namespace std;

int search_missing(vector<int>& arr, int n) {
  int a = 0, b = n - 1;
  int mid;
  while (a < b) {
    mid = (a + b) / 2;
    if (arr[mid] != mid)
      b = mid - 1;
    else
      a = mid + 1;
  }
  return ((a == (n - 1)) ? n : a);
}

int main() {
  vector<int> test_arr;
  int expected_result;

  cout << "Test Case 1 - ";
  test_arr = {0, 1, 3, 4, 5, 6, 7, 8, 9};
  expected_result = 2;
  cout << ((search_missing(test_arr, 9) == expected_result) ? " PASS "
                                                            : " FAIL ")
       << endl;

  cout << "Test Case 2 - ";
  test_arr = {0, 1, 2, 3, 4, 5, 6, 8, 9};
  expected_result = 7;
  cout << ((search_missing(test_arr, 9) == expected_result) ? " PASS "
                                                            : " FAIL ")
       << endl;

  cout << "Test Case 3 - ";
  test_arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  expected_result = 0;
  cout << ((search_missing(test_arr, 9) == expected_result) ? " PASS "
                                                            : " FAIL ")
       << endl;

  cout << "Test Case 4 - ";
  test_arr = {0, 1, 2, 3, 4, 6, 7, 8, 9};
  expected_result = 5;
  cout << ((search_missing(test_arr, 9) == expected_result) ? " PASS "
                                                            : " FAIL ")
       << endl;

  cout << "Test Case 5 - ";
  test_arr = {0, 1, 2, 3, 4, 5, 6, 7, 8};
  expected_result = 9;
  cout << ((search_missing(test_arr, 9) == expected_result) ? " PASS "
                                                            : " FAIL ")
       << endl;
}
