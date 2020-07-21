/*
##############################################
#          Coding Interview Questions
#      Created/Modified on: June 26, 2019
#           Author: Munir Jojo-Verge
##############################################
 */

/*
Write a function that takes in a non-empty array of integers and returns the
maximum sum that can be obtained by summing up all the numbers in a non-empty
subarray of the input array. A subarray must only contain adjacent numbers.

Sample input: [3, 5, -9, 1, 3, -2, 3, 4, 7, 2, -9, 6, 3, 1, -5, 4]
Sample output: 19 ([1, 3, -2, 3, 4, 7, 2, -9, 6, 3, 1])
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int kadanesAlgorithm(vector<int> array) {
  // Write your code here.
  int Prev_Sum = array[0];
  int Biggest_sum = Prev_Sum;
  for (size_t i = 1; i < array.size(); i++) {
    Prev_Sum = max(Prev_Sum + array[i], array[i]);
    Biggest_sum = max(Prev_Sum, Biggest_sum);
    // cout << "MaxSum[" << i << "] = " << MaxSum[i] << endl;
  }
  // return *max_element(MaxSum.begin(), MaxSum.end());
  return Biggest_sum;
}

int kadanesAlgorithm2(vector<int> array) {
  // Write your code here.
  vector<int> MaxSum(array.size());
  MaxSum[0] = array[0];
  int Biggest_sum = MaxSum[0];
  for (size_t i = 1; i < array.size(); i++) {
    MaxSum[i] = max(MaxSum[i - 1] + array[i], array[i]);
    Biggest_sum = max(MaxSum[i], Biggest_sum);
    // cout << "MaxSum[" << i << "] = " << MaxSum[i] << endl;
  }
  // return *max_element(MaxSum.begin(), MaxSum.end());
  return Biggest_sum;
}

int main() {
  cout << "Test Case 1: {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}: ";
  cout << (kadanesAlgorithm({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) == 55 ? "PASS"
                                                                   : "FAIL")
       << endl;

  cout << "Test Case 2: ";
  cout << (kadanesAlgorithm({-1, -2, -3, -4, -5, -6, -7, -8, -9, -10}) == -1
               ? "PASS"
               : "FAIL")
       << endl;

  cout << "Test Case 3: ";
  cout << (kadanesAlgorithm({-10, -2, -9, -4, -8, -6, -7, -1, -3, -5}) == -1
               ? "PASS"
               : "FAIL")
       << endl;

  cout << "Test Case 4: ";
  cout << (kadanesAlgorithm({1, 2, 3, 4, 5, 6, -20, 7, 8, 9, 10}) == 35
               ? "PASS"
               : "FAIL")
       << endl;

  cout << "Test Case 5: ";
  cout << (kadanesAlgorithm({1, 2, 3, 4, 5, 6, -22, 7, 8, 9, 10}) == 34
               ? "PASS"
               : "FAIL")
       << endl;

  cout << "Test Case 6: ";
  cout << (kadanesAlgorithm({1, 2, -4, 3, 5, -9, 8, 1, 2}) == 11 ? "PASS"
                                                                 : "FAIL")
       << endl;

  cout << "Test Case 7: ";
  cout << (kadanesAlgorithm({3, 4, -6, 7, 8}) == 16 ? "PASS" : "FAIL") << endl;

  cout << "Test Case 8: ";
  cout << (kadanesAlgorithm(
               {3, 5, -9, 1, 3, -2, 3, 4, 7, 2, -9, 6, 3, 1, -5, 4}) == 19
               ? "PASS"
               : "FAIL")
       << endl;

  cout << "Test Case 9: ";
  cout << (kadanesAlgorithm(
               {8, 5, -9, 1, 3, -2, 3, 4, 7, 2, -9, 6, 3, 1, -5, 4}) == 23
               ? "PASS"
               : "FAIL")
       << endl;

  cout << "Test Case 10: ";
  cout << (kadanesAlgorithm(
               {8, 5, -9, 1, 3, -2, 3, 4, 7, 2, -9, 6, 3, 1, -5, 6}) == 24
               ? "PASS"
               : "FAIL")
       << endl;

  cout << "Test Case 11: ";
  cout << (kadanesAlgorithm(
               {8, 5, -9, 1, 3, -2, 3, 4, 7, 2, -18, 6, 3, 1, -5, 6}) == 22
               ? "PASS"
               : "FAIL")
       << endl;

  cout << "Test Case 12: ";
  cout << (kadanesAlgorithm({8, 5, -9, 1,  3, -2, 3,   4,  7, 2,  -18,
                             6, 3, 1,  -5, 6, 20, -23, 15, 1, -3, 4}) == 35
               ? "PASS"
               : "FAIL")
       << endl;

  cout << "Test Case 13: ";
  cout << (kadanesAlgorithm({100, 8, 5, -9, 1, 3,  -2,  3,  4, 7,  2, -18,
                             6,   3, 1, -5, 6, 20, -23, 15, 1, -3, 4}) == 135
               ? "PASS"
               : "FAIL")
       << endl;
}
