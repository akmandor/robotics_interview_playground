/*
##############################################
#          Coding Interview Questions
#      Created/Modified on: June 26, 2019
#           Author: Munir Jojo-Verge
##############################################
 */
/*
Given an array of positive integers representing coin denominations and a single
non-negative integer representing a target amount of money, implement a function
that returns the smallest number of coins needed to make change for that target
amount using the given coin denominations. Note that an unlimited amount of
coins is at your disposal. If it is impossible to make change for the target
amount, return -1.

Sample input: 7, [1, 5, 10]
*/

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int minNumberOfCoinsForChange2(int money, vector<int> denoms) {
  // Write your code here.
  if (denoms.size() == 0) return -1;
  if (money == 0) return 0;

  sort(denoms.begin(), denoms.end());

  vector<int> MinCoins(money + 1, INT_MAX - 1);
  MinCoins[0] = 0;
  for (auto den : denoms) {
    for (size_t ch = 1; ch <= money; ch++) {
      if (ch >= den) {
        int ch_left = int(ch - den);
        int num_coins = MinCoins[ch_left] + 1;
        MinCoins[ch] = min(MinCoins[ch], num_coins);
      }
    }
  }
  return ((MinCoins[money] != INT_MAX - 1) ? MinCoins[money] : -1);
}

size_t minNumberOfCoinsForChange(int money, vector<int> denoms) {
  if (denoms.size() == 0) return -1;
  if (money == 0) return 0;

  sort(denoms.begin(), denoms.end());
  vector<size_t> min_num_change_coins(money + 1, UINT32_MAX);
  min_num_change_coins[0] = 0;

  for (size_t m = 1; m <= money; m++) {
    for (auto den : denoms) {
      if (m >= den) {
        min_num_change_coins[m] = std::min(min_num_change_coins[m],
                                           min_num_change_coins[m - den] + 1);
      } else {
        break;
      }
    }
  }
  return (min_num_change_coins[money] != UINT32_MAX
              ? min_num_change_coins[money]
              : -1);
}

int main() {
  vector<int> vector1{1, 2, 3};
  vector<int> vector2{2, 1};
  vector<int> vector3{1, 5, 10};
  vector<int> vector4{1, 5, 10};
  vector<int> vector5{1, 5, 10};
  vector<int> vector6{1, 5, 10};
  vector<int> vector7{1, 5, 10};
  vector<int> vector8{1, 5, 10};
  vector<int> vector9{2, 4};
  vector<int> vector10{3, 7};
  vector<int> vector11{3, 5};
  vector<int> vector12{3, 4, 5};
  vector<int> vector13{39, 45, 130, 40, 4, 1};
  vector<int> vector14{39, 45, 130, 40, 4, 1, 60, 75};

  cout << "Test Case 1: ";
  cout << ((minNumberOfCoinsForChange(0, vector1) == 0) ? "PASS" : "FAIL")
       << endl;

  cout << "Test Case 2: ";
  cout << ((minNumberOfCoinsForChange(3, vector2) == 2) ? "PASS" : "FAIL")
       << endl;

  cout << "Test Case 3: ";
  cout << ((minNumberOfCoinsForChange(4, vector3) == 4) ? "PASS" : "FAIL")
       << endl;

  cout << "Test Case 4: ";
  cout << ((minNumberOfCoinsForChange(7, vector4) == 3) ? "PASS" : "FAIL")
       << endl;

  cout << "Test Case 5: ";
  cout << ((minNumberOfCoinsForChange(10, vector5) == 1) ? "PASS" : "FAIL")
       << endl;

  cout << "Test Case 6: ";
  cout << ((minNumberOfCoinsForChange(11, vector6) == 2) ? "PASS" : "FAIL")
       << endl;

  cout << "Test Case 7: ";
  cout << ((minNumberOfCoinsForChange(24, vector7) == 6) ? "PASS" : "FAIL")
       << endl;

  cout << "Test Case 8: ";
  cout << ((minNumberOfCoinsForChange(25, vector8) == 3) ? "PASS" : "FAIL")
       << endl;

  cout << "Test Case 9: ";
  cout << ((minNumberOfCoinsForChange(7, vector9) == -1) ? "PASS" : "FAIL")
       << endl;

  cout << "Test Case 10: ";
  cout << ((minNumberOfCoinsForChange(7, vector10) == 1) ? "PASS" : "FAIL")
       << endl;

  cout << "Test Case 11: ";
  cout << ((minNumberOfCoinsForChange(9, vector11) == 3) ? "PASS" : "FAIL")
       << endl;

  cout << "Test Case 12: ";
  cout << ((minNumberOfCoinsForChange(9, vector12) == 2) ? "PASS" : "FAIL")
       << endl;

  cout << "Test Case 13: ";
  cout << ((minNumberOfCoinsForChange(135, vector13) == 3) ? "PASS" : "FAIL")
       << endl;

  cout << "Test Case 14: ";
  cout << ((minNumberOfCoinsForChange(135, vector14) == 2) ? "PASS" : "FAIL")
       << endl;
}
