/*
##############################################
#          Coding Interview Questions
#      Created/Modified on: June 26, 2019
#           Author: Munir Jojo-Verge
##############################################
 */

/*

You're given a non-empty array of positive integers where each integer
represents the maximum number of steps you can take forward in the array. For
example, if the element at index 1 is 3, you can go from index 1 to index 2, 3,
or 4.


Write a function that returns the minimum number of jumps needed to reach the
final index.


Note that jumping from index i to index i + x always
constitutes one jump, no matter how large x is.

Sample Input
array = [3, 4, 2, 1, 2, 3, 7, 1, 1, 1, 3]

Sample Output
4 // 3 --> (4 or 2) --> (2 or 3) --> 7 --> 3

 */

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int minNumberOfJumps(vector<int> array) {
  // Write your code here
  size_t n = array.size();
  vector<int> jumps(n, INT_MAX);
  jumps[0] = 0;
  for (size_t i = 0; i < n; i++) {
    for (size_t j = i + 1; j < n && j <= i + array[i]; j++) {
      if (jumps[i] + 1 < jumps[j]) {
        jumps[j] = jumps[i] + 1;
      }
    }
  }
  return jumps[n - 1];
}

int minNumberOfJumps2(vector<int> array) {
  vector<bool> visited(array.size(), false);

  // Defined the triplet value
  int idx = 0;               // starting point
  int d = 0;                 // distance from the start point
  int num_jumps = array[0];  // number of jump we can perform

  // Store the expansions
  vector<vector<int> > open;
  open.push_back({d, idx, num_jumps});

  bool found = false;

  while (!found && !open.empty()) {
    std::sort(open.begin(), open.end());
    d = open[0][0];
    idx = open[0][1];
    num_jumps = open[0][2];

    open.erase(open.begin());
    visited[idx] = true;

    // Since multiple paths can take you to the goal/end, we want let the goal
    // be added to the open list and once we reach it, we know that it will hold
    // de smallest diatance. So that means that we need to check on the open
    // list if we reached the goal.
    if (idx == array.size() - 1) {
      found = true;
    } else {
      // Let's explore the "neighbours"
      for (size_t i = idx + 1; i <= idx + array[idx] && i < array.size(); i++) {
        if (!visited[i]) {
          // Defined the triplet value
          int new_idx = i;               // starting point
          int new_d = d + 1;             // distance from the start point
          int new_num_jumps = array[i];  // number of jump we can perform
          open.push_back({new_d, new_idx, new_num_jumps});
        }
      }
    }
  }
  return d;
}

int main() {
  // Test cases
  vector<int> vector1{1};
  vector<int> vector2{1, 1};
  vector<int> vector3{3, 1};
  vector<int> vector4{1, 1, 1};
  vector<int> vector5{2, 1, 1};
  vector<int> vector6{2, 1, 2, 3, 1};
  vector<int> vector7{2, 1, 2, 3, 1, 1, 1};
  vector<int> vector8{2, 1, 2, 2, 1, 1, 1};
  vector<int> vector9{3, 4, 2, 1, 2, 3, 7, 1, 1, 1, 3};
  vector<int> vector10{3, 4, 2, 1, 2, 3, 7, 1, 1, 1, 3, 2, 6, 2, 1, 1, 1, 1};
  vector<int> vector11{3, 4, 2, 1, 2, 3, 7, 1, 1, 1, 3, 2, 3, 2, 1, 1, 1, 1};
  vector<int> vector12{3, 10, 2, 1, 2, 3, 7, 1, 1, 1, 3, 2, 3, 2, 1, 1, 1, 1};
  vector<int> vector13{3, 12, 2, 1, 2, 3, 7, 1, 1, 1, 3, 2, 3, 2, 1, 1, 1, 1};
  vector<int> vector14{3, 12, 2, 1, 2, 3, 15, 1, 1, 1, 3, 2, 3, 2, 1, 1, 1, 1};

  cout << "Test Case 1: ";
  cout << (minNumberOfJumps2(vector1) == 0 ? "PASS" : "FAIL") << endl;

  cout << "Test Case 2: ";
  cout << (minNumberOfJumps2(vector2) == 1 ? "PASS" : "FAIL") << endl;

  cout << "Test Case 3: ";
  cout << (minNumberOfJumps2(vector3) == 1 ? "PASS" : "FAIL") << endl;

  cout << "Test Case 4: ";
  cout << (minNumberOfJumps2(vector4) == 2 ? "PASS" : "FAIL") << endl;

  cout << "Test Case 5: ";
  cout << (minNumberOfJumps2(vector5) == 1 ? "PASS" : "FAIL") << endl;

  cout << "Test Case 6: ";
  cout << (minNumberOfJumps2(vector6) == 2 ? "PASS" : "FAIL") << endl;

  cout << "Test Case 7: ";
  cout << (minNumberOfJumps2(vector7) == 3 ? "PASS" : "FAIL") << endl;

  cout << "Test Case 8: ";
  cout << (minNumberOfJumps2(vector8) == 4 ? "PASS" : "FAIL") << endl;

  cout << "Test Case 9: ";
  cout << (minNumberOfJumps2(vector9) == 4 ? "PASS" : "FAIL") << endl;

  cout << "Test Case 10: ";
  cout << (minNumberOfJumps2(vector10) == 5 ? "PASS" : "FAIL") << endl;

  cout << "Test Case 11: ";
  cout << (minNumberOfJumps2(vector11) == 7 ? "PASS" : "FAIL") << endl;

  cout << "Test Case 12: ";
  cout << (minNumberOfJumps2(vector12) == 6 ? "PASS" : "FAIL") << endl;

  cout << "Test Case 13: ";
  cout << (minNumberOfJumps2(vector13) == 5 ? "PASS" : "FAIL") << endl;

  cout << "Test Case 14: ";
  cout << (minNumberOfJumps2(vector14) == 3 ? "PASS" : "FAIL") << endl;
}

int main2() {
  size_t n;
  std::cout << "How many integers will you input? ";
  std::cin >> n;

  std::vector<int> myList(n);

  for (size_t i = 0; i < n; i++) {
    std::cout << "Enter int " << i << ": ";
    std::cin >> myList[i];
  }

  std::cout << "The min number of jumps is: " << minNumberOfJumps2(myList)
            << std::endl;
}