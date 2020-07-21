/*
##############################################
#          Coding Interview Questions
#      Created/Modified on: Jun 18, 2020
#           Author: Munir Jojo-Verge
##############################################
 */

/*

Write a function that takes in an array of integers and, without sorting the
input array, returns a sorted array of the three largest integers in the input
array.


The function should return duplicate integers if necessary; for example, it
should return
[10, 10, 12] for an input array of [10, 5, 9, 10, 12].

Sample Input
array = [141, 1, 17, -7, -17, -27, 18, 541, 8, 7, 7]

Sample Output
[18, 141, 541]
*/

#include <climits>
#include <iostream>
#include <vector>

using namespace std;

void shift(vector<int>& result, int num, size_t idx) {
  for (size_t i = 0; i < idx; i++) {
    result[i] = result[i + 1];
  }
  result[idx] = num;
}

vector<int> findThreeLargestNumbers(vector<int> array) {
  vector<int> result(3, INT_MIN);
  for (size_t i = 0; i < array.size(); i++) {
    if (array[i] > result[2]) {
      shift(result, array[i], 2);
    } else if (array[i] > result[1]) {
      shift(result, array[i], 1);
    } else if (array[i] > result[0]) {
      result[0] = array[i];
    }
  }
  return result;
}

vector<int> findThreeLargestNumbers2(vector<int> array) {
  vector<int> result(3, INT_MIN);
  for (size_t i = 0; i < array.size(); i++) {
    if (array[i] > result[0]) {
      if (array[i] > result[2]) {
        shift(result, array[i], 2);
      } else if (array[i] > result[1]) {
        shift(result, array[i], 1);
      } else
        result[0] = array[i];
    }
  }
  return result;
}
int main() {
  vector<int> array;
  vector<int> expected;
  vector<int> result;

  cout << "Test Case 1: ";
  array = {141, 1, 17, -7, -17, -27, 18, 541, 8, 7, 7};
  expected = {18, 141, 541};
  result = findThreeLargestNumbers(array);
  cout << (result == expected ? "PASS" : "FAIL") << endl;

  cout << "Test Case 2: ";
  array = {55, 7, 8};
  expected = {7, 8, 55};
  result = findThreeLargestNumbers(array);
  cout << (result == expected ? "PASS" : "FAIL") << endl;

  cout << "Test Case 3: ";
  array = {55, 43, 11, 3, -3, 10};
  expected = {11, 43, 55};
  result = findThreeLargestNumbers(array);
  cout << (result == expected ? "PASS" : "FAIL") << endl;

  cout << "Test Case 4: ";
  array = {7, 8, 3, 11, 43, 55};
  expected = {11, 43, 55};
  result = findThreeLargestNumbers(array);
  cout << (result == expected ? "PASS" : "FAIL") << endl;

  cout << "Test Case 5: ";
  array = {55, 7, 8, 3, 43, 11};
  expected = {11, 43, 55};
  result = findThreeLargestNumbers(array);
  cout << (result == expected ? "PASS" : "FAIL") << endl;

  cout << "Test Case 6: ";
  array = {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7};
  expected = {7, 7, 7};
  result = findThreeLargestNumbers(array);
  cout << (result == expected ? "PASS" : "FAIL") << endl;

  cout << "Test Case 7: ";
  array = {7, 7, 7, 7, 7, 7, 7, 8, 7, 7, 7};
  expected = {7, 7, 8};
  result = findThreeLargestNumbers(array);
  cout << (result == expected ? "PASS" : "FAIL") << endl;

  cout << "Test Case 8: ";
  array = {-1, -2, -3, -7, -17, -27, -18, -541, -8, -7, 7};
  expected = {-2, -1, 7};
  result = findThreeLargestNumbers(array);
  cout << (result == expected ? "PASS" : "FAIL") << endl;
}