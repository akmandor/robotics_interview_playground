/*
##############################################
#          Coding Interview Questions
#      Created/Modified on: August 22, 2019
#           Author: Munir Jojo-Verge
##############################################
 */

/*
Problem 1
Given a list of numbers, return whether any two sums to k. For example, given
[10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

Bonus: Can you do this in one pass? YESSSS
*/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// 1 PASS
bool two_sum_k(vector<int> arr, int target_sum) {
  if (arr.size() == 0) return false;

  unordered_map<int, int> need_set;
  int i = 0;
  bool result = false;

  while (i < arr.size() && result == false) {
    result = (need_set.find(arr[i]) != need_set.end());
    if (result == false)
      need_set.insert({target_sum - arr[i], target_sum - arr[i]});
    i++;
  }
  return result;
}

// Smart but not that smart
bool two_sum_k_2(vector<int> arr, int target_sum) {
  if (arr.size() == 0) return false;

  int i = 1;
  bool result = false;

  while (i < arr.size() && result == false) {
    int curr_num = arr[i];
    int j = 0;
    while (j < i and result == false) {
      result = (arr[j] + curr_num == target_sum);
      j++;
    }
    i++;
  }
  return result;
}

int main() {
  bool expected_result;
  cout << "Test Case 1: {} - 17 ";
  expected_result = false;
  cout << (two_sum_k({}, 17) == expected_result ? "PASS" : "FAIL") << endl;

  cout << "Test Case 2: {10, 15, 3, 7} - 17 ";
  expected_result = true;
  cout << (two_sum_k({10, 15, 3, 7}, 17) == expected_result ? "PASS" : "FAIL")
       << endl;

  cout << "Test Case 3: {10, 15, 3, 7} - 15 ";
  expected_result = false;
  cout << (two_sum_k({10, 15, 3, 7}, 15) == expected_result ? "PASS" : "FAIL")
       << endl;

  cout << "Test Case 4: {10, 15, 3, 7, 0} - 15 ";
  expected_result = true;
  cout << (two_sum_k({10, 15, 3, 7, 0}, 15) == expected_result ? "PASS"
                                                               : "FAIL")
       << endl;

  cout << "Test Case 5: {10, 15, 3, 7, 5, 0} - 15  ";
  expected_result = true;
  cout << (two_sum_k({10, 15, 3, 7, 5, 0}, 15) == expected_result ? "PASS"
                                                                  : "FAIL")
       << endl;
}
