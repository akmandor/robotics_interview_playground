/*
##############################################
#          Coding Interview Questions
#      Created/Modified on: July 5, 2020
#           Author: Munir Jojo-Verge
##############################################
 */

/*
Problem Introduction
In this problem, your goal is to add parentheses to a given arithmetic
expression to maximize its value.
max(5 − 8 + 7 × 4 − 8 + 9) =?

Problem Description
Find the maximum value of an arithmetic expression by specifying the order
of applying its arithmetic operations using additional parentheses. Input
Format. The only line of the input contains a string s of length 2n + 1 for some
n, with symbols s 0 , s 1 , . . . , s 2n . Each symbol at an even position of s
is a digit (that is, an integer from 0 to 9) while each symbol at an odd
position is one of three operations from {+,-,*}. Constraints. 1 ≤ n ≤ 14 (hence
the string contains at most 29 symbols). Output Format. Output the maximum
possible value of the given arithmetic expression among different orders of
applying arithmetic operations.

Sample 1.
Input: 1+5
Output:
6

Sample 2.
Input: 5-8+7*4-8+9
Output: 200
200 = (5 − ((8 + 7) × (4 − (8 + 9))))
*/

#include <cassert>
#include <climits>
#include <cmath>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using std::max;
using std::min;
using std::string;
using std::vector;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

long long MinAndMax(vector<vector<long long>>& minArray,
                    vector<vector<long long>>& maxArray, const int i,
                    const int j, const string& exp) {
  long long minVal = LLONG_MAX;
  long long maxVal = LLONG_MIN;
  for (int k = i; k < j; k++) {
    char op = exp[2 * k + 1];
    long long a = eval(minArray[i][k], minArray[k + 1][j], op);
    long long b = eval(minArray[i][k], maxArray[k + 1][j], op);
    long long c = eval(maxArray[i][k], minArray[k + 1][j], op);
    long long d = eval(maxArray[i][k], maxArray[k + 1][j], op);
    minVal = min(minVal, min(a, min(b, min(c, d))));
    maxVal = max(maxVal, max(a, max(b, max(c, d))));
  }
  minArray[i][j] = minVal;
  maxArray[i][j] = maxVal;
}

long long get_maximum_value(const string& exp) {
  int length = exp.size();
  int numOfnum = (length + 1) / 2;
  vector<vector<long long>> minArray(numOfnum, vector<long long>(numOfnum, 0));
  vector<vector<long long>> maxArray(numOfnum, vector<long long>(numOfnum, 0));

  for (int i = 0; i < numOfnum; i++) {
    // The values on the main diagonal is just the number themselves
    minArray[i][i] = std::stoll(exp.substr(2 * i, 1));
    maxArray[i][i] = std::stoll(exp.substr(2 * i, 1));
  }

  for (int s = 0; s < numOfnum - 1; s++) {
    for (int i = 0; i < numOfnum - s - 1; i++) {
      int j = i + s + 1;

      // find the minimum and maximum values for the expression
      // between the ith number and jth number
      MinAndMax(minArray, maxArray, i, j, exp);
    }
  }

  return maxArray[0][numOfnum - 1];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
