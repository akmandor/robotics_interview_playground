/*
##############################################
#          Coding Interview Questions
#      Created/Modified on: August 23, 2019
#           Author: Munir Jojo-Verge
##############################################
 */

/*

Given an array of positive integers representing coin denominations and a
single non-negative integer n representing a target amount of
money, write a function that returns the number of ways to make change for
that target amount using the given coin denominations.

Note that an unlimited amount of coins is at your disposal.

Sample Input
n = 6
denoms = [1, 5]

Sample Output
2: 1x1 + 1x5 and 6x1
*/

#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int numberOfWaysToChangeMoney(int money, vector<int> denoms) {
  if (money == 0 || denoms.size() == 0) return 1;

  vector<int> NumWays(
      money + 1, 0);  // The +1 is to ignore the "0" index nad work with more
                      // common sense info (coinds and denoms directly)
  NumWays[0] = 1;

  for (size_t den = 0; den < denoms.size(); den++) {
    int denom = denoms[den];
    for (size_t ch = 1; ch <= money; ch++) {
      NumWays[ch] += (ch >= denom) ? NumWays[ch - denom] : 0;
    }
  }
  return NumWays[money];
}

size_t minChangeMoney(int money, vector<int> denoms) {
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
  return min_num_change_coins[money];
}

int main() {
  vector<int> vector1{2, 3, 4, 7};
  vector<int> vector2{5};
  vector<int> vector3{2, 4};
  vector<int> vector4{1, 5};
  vector<int> vector5{1, 5, 10, 25};
  vector<int> vector6{1, 5, 10, 25};
  vector<int> vector7{1, 5, 10, 25};
  vector<int> vector8{1, 5, 10, 25};
  vector<int> vector9{2, 3, 7};
  vector<int> vector10{2, 3, 4, 7};

  vector<int> vector11{10, 25, 1, 20, 5};

  cout << "Test Case 1: ";
  cout << ((numberOfWaysToChangeMoney(0, vector1) == 1) ? "PASS" : "FAIL")
       << endl;

  cout << "Test Case 2: ";
  cout << ((numberOfWaysToChangeMoney(9, vector2) == 0) ? "PASS" : "FAIL")
       << endl;

  cout << "Test Case 3: ";
  cout << ((numberOfWaysToChangeMoney(7, vector3) == 0) ? "PASS" : "FAIL")
       << endl;

  cout << "Test Case 4: ";
  cout << ((numberOfWaysToChangeMoney(6, vector4) == 2) ? "PASS" : "FAIL")
       << endl;

  cout << "Test Case 5: ";
  cout << ((numberOfWaysToChangeMoney(4, vector5) == 1) ? "PASS" : "FAIL")
       << endl;

  cout << "Test Case 6: ";
  cout << ((numberOfWaysToChangeMoney(5, vector6) == 2) ? "PASS" : "FAIL")
       << endl;

  cout << "Test Case 7: ";
  cout << ((numberOfWaysToChangeMoney(10, vector7) == 4) ? "PASS" : "FAIL")
       << endl;

  cout << "Test Case 8: ";
  cout << ((numberOfWaysToChangeMoney(25, vector8) == 13) ? "PASS" : "FAIL")
       << endl;

  cout << "Test Case 9: ";
  cout << ((numberOfWaysToChangeMoney(12, vector9) == 4) ? "PASS" : "FAIL")
       << endl;

  cout << "Test Case 10: ";
  cout << ((numberOfWaysToChangeMoney(7, vector10) == 3) ? "PASS" : "FAIL")
       << endl;

  cout << "Test Case 11: ";
  cout << ((minChangeMoney(40, vector11) == 2) ? "PASS" : "FAIL") << endl;
}
