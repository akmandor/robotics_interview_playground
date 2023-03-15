/*
##############################################
#          Coding Interview Questions
#      Created/Modified on: June 26, 2019
#           Author: Munir Jojo-Verge
##############################################
 */

/*
Write a function that takes in a non-empty array of distinct integers and an
integer representing a target sum. If any two numbers in the input array sum up
to the target sum, the function should return them in an array, in sorted order.
If no two numbers sum up to the target sum, the function should return an empty
array. Assume that there will be at most one pair of numbers summing up to the
target sum.

Sample input: [3, 5, -4, 8, 11, 1, -1, 6], 10
Sample output: [-1, 11]
 */

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

std::vector<int> twoNumberSum_brute(std::vector<int> myList, int targetSum) {
  std::vector<int> output;
  for (size_t i = 0; i < myList.size(); i++) {
    int firstNum = myList[i];
    for (size_t j = i + 1; j < myList.size(); j++) {
      int secondNum = myList[j];
      if (firstNum + secondNum == targetSum) {
        return (firstNum < secondNum ? std::vector<int>{firstNum, secondNum}
                                     : std::vector<int>{secondNum, firstNum});
      }
    }
  }

  return std::vector<int>{};
}

vector<int> twoNumberSum(vector<int> array, int targetSum) {
  // Write your code here.
  std::unordered_map<int, int> map;
  
  for (size_t i = 0; i < array.size(); i++) {
    auto search = map.find(array[i]);
    if (search != map.end()) {
      return (array[i] < search->second
                  ? std::vector<int>{array[i], search->second}
                  : std::vector<int>{search->second, array[i]});
    }
    else
    {
      map.insert(make_pair(targetSum - array[i], array[i]));
    }
    
  }

  return std::vector<int>{};
}

int main() {
  vector<int> expected;

  cout << "Test Case 1" << endl;
  expected = {4, 6};
  cout << ((twoNumberSum({4, 6}, 10) == expected) ? "PASS" : "FAIL") << endl;

  cout << "Test Case 2" << endl;
  expected = {1, 4};
  cout << ((twoNumberSum({4, 6, 1}, 5) == expected) ? "PASS" : "FAIL") << endl;

  cout << "Test Case 3" << endl;
  expected = {-3, 6};
  cout << ((twoNumberSum({4, 6, 1, -3}, 3) == expected) ? "PASS" : "FAIL")
       << endl;

  cout << "Test Case 4" << endl;
  expected = {-1, 11};
  cout << ((twoNumberSum({3, 5, -4, 8, 11, 1, -1, 6}, 10) == expected) ? "PASS"
                                                                       : "FAIL")
       << endl;

  cout << "Test Case 5" << endl;
  expected = {8, 9};
  cout << ((twoNumberSum({1, 2, 3, 4, 5, 6, 7, 8, 9}, 17) == expected) ? "PASS"
                                                                       : "FAIL")
       << endl;

  cout << "Test Case 6" << endl;
  expected = {3, 15};
  cout << ((twoNumberSum({1, 2, 3, 4, 5, 6, 7, 8, 9, 15}, 18) == expected)
               ? "PASS"
               : "FAIL")
       << endl;

  cout << "Test Case 7" << endl;
  expected = {-5, 0};
  cout << ((twoNumberSum({-7, -5, -3, -1, 0, 1, 3, 5, 7}, -5) == expected)
               ? "PASS"
               : "FAIL")
       << endl;

  cout << "Test Case 8" << endl;
  expected = {-47, 210};
  cout << ((twoNumberSum({-21, 301, 12, 4, 65, 56, 210, 356, 9, -47}, 163) ==
            expected)
               ? "PASS"
               : "FAIL")
       << endl;

  cout << "Test Case 9" << endl;
  expected = {};
  cout << ((twoNumberSum({-21, 301, 12, 4, 65, 56, 210, 356, 9, -47}, 164) ==
            expected)
               ? "PASS"
               : "FAIL")
       << endl;

  cout << "Test Case 10" << endl;
  expected = {};
  cout << ((twoNumberSum({3, 5, -4, 8, 11, 1, -1, 6}, 15) == expected) ? "PASS"
                                                                       : "FAIL")
       << endl;
}