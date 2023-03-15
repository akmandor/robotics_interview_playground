/*
##############################################
#          Coding Interview Questions
#      Created/Modified on: August 23, 2019
#           Author: Munir Jojo-Verge
##############################################
 */

/*
You are given an array of integers. Each integer represents a jump of its value
in the array. For instance, the integer 2 represents a jump of 2 indices forward
in the array; the integer -3 represents a jump of 3 indices backward in the
array. If a jump spills past the array's bounds, it wraps over to the other
side. For instance, a jump of -1 at index 0 brings us to the last index in the
array. Similarly, a jump of 1 at the last index in the array brings us to index
0. Write a function that returns a boolean representing whether the jumps in the
array form a single cycle. A single cycle occurs if, starting at any index in
the array and following the jumps, every element is visited exactly once before
landing back on the starting index.

Sample input: [2, 3, 1, -4, -4, 2]
Sample output: True
*/

#include <iostream>
#include <vector>

using namespace std;

// jumping inside the array making sure we wrap around when needed
int jump(int cur_idx, const vector<int>& array) {
  int jump_len = array[cur_idx];
  int new_idx = (cur_idx + jump_len) % (int)array.size();

  return ((new_idx >= 0) ? new_idx : array.size() + new_idx);
}

// Time complexity: O(n); where n = len of array/vector
// Space Complexity O(1)
bool hasSingleCycle(vector<int> array) {
  int cur_idx = 0;
  int n_elem_visited = 0;

  while (n_elem_visited < array.size()) {
    if (n_elem_visited > 0 && cur_idx == 0) return false;

    n_elem_visited++;

    cur_idx = jump(cur_idx, array);
  }

  return (cur_idx == 0);
}

int main() {
  cout << "Test Case 1: ";
  cout << ((hasSingleCycle({2, 2, -1}) == true) ? "PASS" : "FAIL") << endl;

  cout << "Test Case 2: ";
  cout << ((hasSingleCycle({2, 2, 2}) == true) ? "PASS" : "FAIL") << endl;

  cout << "Test Case 3: ";
  cout << ((hasSingleCycle({1, 1, 1, 1, 1}) == true) ? "PASS" : "FAIL") << endl;

  cout << "Test Case 4: ";
  cout << ((hasSingleCycle({-1, 2, 2}) == true) ? "PASS" : "FAIL") << endl;

  cout << "Test Case 5: ";
  cout << ((hasSingleCycle({-2, 2, 2}) == false) ? "PASS" : "FAIL") << endl;

  cout << "Test Case 6: ";
  cout << ((hasSingleCycle({0, 1, 1, 1, 1}) == false) ? "PASS" : "FAIL")
       << endl;

  cout << "Test Case 7: ";
  cout << ((hasSingleCycle({1, 1, 0, 1, 1}) == false) ? "PASS" : "FAIL")
       << endl;

  cout << "Test Case 8: ";
  cout << ((hasSingleCycle({1, 1, 1, 1, 2}) == false) ? "PASS" : "FAIL")
       << endl;

  cout << "Test Case 9: ";
  cout << ((hasSingleCycle({3, 5, 6, -5, -2, -5, -12, -2, -1, 2, -6, 1, 1, 2,
                            -5, 2}) == true)
               ? "PASS"
               : "FAIL")
       << endl;

  cout << "Test Case 10: ";
  cout << ((hasSingleCycle({3, 5, 5, -5, -2, -5, -12, -2, -1, 2, -6, 1, 1, 2,
                            -5, 2}) == false)
               ? "PASS"
               : "FAIL")
       << endl;

  cout << "Test Case 11: ";
  cout << ((hasSingleCycle({1, 2, 3, 4, -2, 3, 7, 8, 1}) == true) ? "PASS"
                                                                  : "FAIL")
       << endl;

  cout << "Test Case 12: ";
  cout << ((hasSingleCycle({1, 2, 3, 4, -2, 3, 7, 8, -8}) == true) ? "PASS"
                                                                   : "FAIL")
       << endl;

  cout << "Test Case 13: ";
  cout << ((hasSingleCycle({1, 2, 3, 4, -2, 3, 7, 8, -26}) == true) ? "PASS"
                                                                    : "FAIL")
       << endl;

  cout << "Test Case 14: ";
  cout << ((hasSingleCycle({10, 11, -6, -23, -2, 3, 88, 908, -26}) == true)
               ? "PASS"
               : "FAIL")
       << endl;

  cout << "Test Case 15: ";
  cout << ((hasSingleCycle({10, 11, -6, -23, -2, 3, 88, 909, -26}) == false)
               ? "PASS"
               : "FAIL")
       << endl;

  cout << "Test Case 16: ";
  cout << ((hasSingleCycle({2, 3, 1, -4, -4, 2}) == true) ? "PASS" : "FAIL")
       << endl;

  cout << "Test Case 17: ";
  cout << ((hasSingleCycle({1, -1, 1, -1}) == false) ? "PASS" : "FAIL") << endl;
}
