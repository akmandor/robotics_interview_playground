/*
##############################################
#          Coding Interview Questions
#      Created/Modified on: June 16, 2020
#           Author: Munir Jojo-Verge
##############################################
 */

/*

You're given an array of arrays where each subarray holds two integer values
and represents an item; the first integer is the item's value, and the second
integer is the item's weight. You're also given an integer representing the
maximum capacity of a knapsack that you have. Your goal is to fit items in
your knapsack without having the sum of their weights exceed the knapsack's
capacity, all the while maximizing their combined value.


Write a function that returns the maximized combined value of the items that
you should pick as well as an array of the indices of each item picked.


You can assume that there will only be one combination of items that maximizes
the total value in the knapsack.

Sample Input
items = [[1, 2], [4, 3], [5, 6], [6, 7]]
capacity = 10

Sample Output
[10, [1, 3]]

*/

#include <algorithm>

#include <iostream>
#include <vector>

#include <cassert>

// Use (void) to silent unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))

using namespace std;

vector<vector<int>> reconstructItems(const vector<vector<int>>& optimal,
                                     const vector<vector<int>>& items,
                                     const int capacity) {
  vector<vector<int>> result(2);

  int c = optimal[0].size() - 1;
  int i = optimal.size() - 1;
  result[0].push_back({optimal[i][c]});

  while (i > 0 && c > 0) {
    if (optimal[i][c] != optimal[i - 1][c]) {
      result[1].push_back(i - 1);
      c -= items[i - 1][1];
    }
    i--;
  }

  sort(result[1].begin(), result[1].end());
  cout << "Optimal Value: " << result[0][0] << endl;
  cout << "Num of items selected: " << result[1].size() << endl;
  for (size_t i = 0; i < result[1].size(); i++) {
    cout << result[1][i] << ", ";
  }
  cout << endl;

  return result;
}

vector<vector<int>> knapsackProblem(vector<vector<int>> items, int capacity) {
  // Write your code here.
  vector<vector<int>> optimal(items.size() + 1, vector<int>(capacity + 1, 0));

  for (size_t i = 1; i < items.size() + 1; i++) {
    int item_v = items[i - 1][0];
    int item_w = items[i - 1][1];
    for (size_t c = 1; c < capacity + 1; c++) {
      if (item_w > c) {
        optimal[i][c] = optimal[i - 1][c];
      } else {
        optimal[i][c] =
            std::max(optimal[i - 1][c], optimal[i - 1][c - item_w] + item_v);
      }
    }
  }

  // Replace return below.
  return reconstructItems(optimal, items, capacity);
}

int main() {
  vector<vector<int>> items;
  int capacity;
  vector<vector<int>> expected_result;

  cout << "---------- Test Case 1 ----------" << endl;
  items = {{1, 2}, {4, 3}, {5, 6}, {6, 7}};
  capacity = 10;
  expected_result = {{10}, {1, 3}};
  assertm(knapsackProblem(items, capacity) == expected_result, "FAILED");

  cout << "---------- Test Case 2 ----------" << endl;
  items = {{465, 100},  {400, 85},   {255, 55},  {350, 45},
           {650, 130},  {1000, 190}, {455, 100}, {100, 25},
           {1200, 190}, {320, 65},   {750, 100}, {50, 45},
           {550, 65},   {100, 50},   {600, 70},  {240, 40}};
  capacity = 200;
  expected_result = {{1500}, {3, 12, 14}};
  assertm(knapsackProblem(items, capacity) == expected_result, "FAILED");

  cout << "---------- Test Case 3 ----------" << endl;
  items = {{465, 100},  {400, 85},   {255, 55},  {350, 45},
           {650, 130},  {1000, 190}, {455, 100}, {100, 25},
           {1200, 190}, {320, 65},   {750, 100}, {50, 45},
           {550, 65},   {100, 50},   {600, 70},  {255, 40}};
  capacity = 200;
  expected_result = {{1505}, {7, 12, 14, 15}};
  assertm(knapsackProblem(items, capacity) == expected_result, "FAILED");

  cout << "---------- Test Case 4 ----------" << endl;
  items = {{2, 1}, {70, 70}, {30, 30}, {69, 69}, {100, 100}}, capacity = 100;
  expected_result = {{101}, {0, 2, 3}};
  assertm(knapsackProblem(items, capacity) == expected_result, "FAILED");

  cout << "---------- Test Case 5 ----------" << endl;
  items = {{1, 2}, {70, 70}, {30, 30}, {69, 69}, {99, 100}}, capacity = 100;
  expected_result = {{100}, {1, 2}};
  assertm(knapsackProblem(items, capacity) == expected_result, "FAILED");

  cout << "---------- Test Case 6 ----------" << endl;
  items = {{1, 2}, {70, 70}, {30, 30}, {69, 69}, {100, 100}}, capacity = 0;
  expected_result = {{0}, {}};
  assertm(knapsackProblem(items, capacity) == expected_result, "FAILED");
}
