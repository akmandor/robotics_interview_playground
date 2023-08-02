/*
LAST UPDATE: 2023.08.01

AUTHOR: Neset Unver Akmandor (NUA)

E-MAIL: akmandor.n@northeastern.edu

DESCRIPTION: 
  - Suppose you have a list of weights and corresponding values for n items. 
  - You have a knapsack that can carry items up to a specific maximum weight, known as the capacity of the knapsack.
  - You want to maximize the sum of values of the items in your knapsack while ensuring that the sum of the weights of 
  the items remains less than or equal to the knapsack’s capacity.
  - If all the combinations exceed the given knapsack’s capacity, then return 0.
  - Note: While adding items in the knapsack, we either add the complete item or don’t add it. Moreover, we can’t add an item again that is already in the bag.
  - Let’s say you have a knapsack capacity of 5 and a list of items with weights and values as follows:
  -- weights = [1, 2, 3, 5]
  -- values = [10, 5, 4, 8]

  - There are four ways of storing items in the knapsack, such that the combined weight of stored items is less than or equal to the knapsack’s capacity.
  -- Item of weight 1 and weight 2, with a total value of 15.
  -- Item of weight 1 and weight 3, with a total value of 14.
  -- Item of weight 2 and weight 3, with a total value of 9.
  -- Item of weight 5, with a value of 8.
  - Though all of the combinations described above are valid, we need to select the one with the maximum value. 
  Hence, we will select items with weights 1 and 2, as they give us the maximum value of 15.

REFERENCES:
[1] https://medium.com/javarevisited/20-dynamic-programming-interview-questions-with-solutions-2a144b1a1e07
*/

#include <string.h>
#include <chrono>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void print(vector<T> v)
{
  for (int i=0; i<v.size(); i++)
  {
    cout << v[i] << "   ";
  }
  cout << "" << endl;
}

template <typename T>
void print(vector<vector<T>> v)
{
  for (int i=0; i<v.size(); i++)
  {
    for (int j=0; j<v[i].size(); j++)
    {
      cout << v[i][j] << "   ";
    }
    cout << "" << endl;
  }
}

int knapsack_recursive(int capacity, 
                       vector<int>& weights, 
                       vector<int>& values, 
                       int cur_weight, 
                       int cur_val, 
                       int idx)
{
  int n = weights.size();
  
  if (idx > n-1)
  {
    return cur_val;
  }

  if (cur_weight + weights[idx] > capacity)
  {
    return cur_val;
  }

  int next_idx = idx + 1;
  int val_added = knapsack_recursive(capacity, weights, values, cur_weight + weights[idx], cur_val + values[idx], next_idx);
  int val_not = knapsack_recursive(capacity, weights, values, cur_weight, cur_val, next_idx);

  return max(val_added, val_not);
}

int knapsack_recursive2(int capacity, 
                        vector<int>& weights, 
                        vector<int>& values, 
                        int cur_weight,
                        int idx)
{
  int n = weights.size();
  
  if (idx > n-1)
  {
    return 0;
  }

  int next_idx = idx + 1;
  int val_not = knapsack_recursive2(capacity, weights, values, cur_weight, next_idx);

  if (cur_weight + weights[idx] <= capacity)
  {
    int val_added = values[idx] + knapsack_recursive2(capacity, weights, values, cur_weight + weights[idx], next_idx);
    return max(val_added, val_not);
  }
  else
  {
    return val_not;
  }
}

int knapsack_memoization_recursive(int capacity, 
                                   vector<int>& weights, 
                                   vector<int>& values, 
                                   int cur_weight,
                                   int idx, 
                                   vector<vector<int>>& memo)
{
  int n = weights.size();
  
  if (idx > n-1)
  {
    return 0;
  }

  if (memo[idx][cur_weight] < 0)
  {
    int next_idx = idx + 1;
    int val_not = knapsack_memoization_recursive(capacity, weights, values, cur_weight, next_idx, memo);

    if (cur_weight + weights[idx] <= capacity)
    {
      int val_added = values[idx] + knapsack_memoization_recursive(capacity, weights, values, cur_weight + weights[idx], next_idx, memo);
      memo[idx][cur_weight] = max(val_added, val_not);
      return memo[idx][cur_weight];
    }
    else
    {
      memo[idx][cur_weight] = val_not;
      return memo[idx][cur_weight];
    }
  }

  return memo[idx][cur_weight];
}

int knapsack_memoization(int capacity, vector<int>& weights, vector<int>& values, double& proc_time)
{
  int n = weights.size();

  // Initialize memoization data
  vector<int> memo_row(capacity+1, -1);
  vector<vector<int>> memo;
  for (int i=0; i<n; i++)
  {
    memo.push_back(memo_row);
  }

  //cout << "BEFORE" << endl;
  //print(memo);
  //cout << "" << endl;

  auto t_start_memo = std::chrono::high_resolution_clock::now();
  int val = knapsack_memoization_recursive(capacity, weights, values, 0, 0, memo);
  auto t_end_memo = std::chrono::high_resolution_clock::now();
  proc_time = std::chrono::duration<double, std::milli>(t_end_memo - t_start_memo).count();

  //cout << "AFTER" << endl;
  //print(memo);

  return val;
}

int knapsack_memoization_recursive2(int capacity, 
                                   vector<int>& weights, 
                                   vector<int>& values, 
                                   int cur_weight,
                                   int idx, 
                                   int** memo)
{
  int n = weights.size();
  
  if (idx > n-1)
  {
    return 0;
  }

  if (memo[idx][cur_weight] < 0)
  {
    int next_idx = idx + 1;
    int val_not = knapsack_memoization_recursive2(capacity, weights, values, cur_weight, next_idx, memo);

    if (cur_weight + weights[idx] <= capacity)
    {
      int val_added = values[idx] + knapsack_memoization_recursive2(capacity, weights, values, cur_weight + weights[idx], next_idx, memo);
      memo[idx][cur_weight] = max(val_added, val_not);
      return memo[idx][cur_weight];
    }
    else
    {
      memo[idx][cur_weight] = val_not;
      return memo[idx][cur_weight];
    }
  }

  return memo[idx][cur_weight];
}

int knapsack_memoization2(int capacity, vector<int>& weights, vector<int>& values, double& proc_time)
{
  int n = weights.size();

  // Initialize memoization data
  // double pointer to declare the
    // table dynamically
    int** memo;
    memo = new int*[n];
 
    // loop to create the table dynamically
    for (int i = 0; i < n; i++)
        memo[i] = new int[capacity + 1];
 
    // loop to initially filled the
    // table with -1
    for (int i = 0; i < n; i++)
        for (int j = 0; j < capacity + 1; j++)
            memo[i][j] = -1;
  
  //cout << "BEFORE" << endl;
  //print(memo);
  //cout << "" << endl;

  auto t_start_memo2 = std::chrono::high_resolution_clock::now();
  int val = knapsack_memoization_recursive2(capacity, weights, values, 0, 0, memo);
  auto t_end_memo2 = std::chrono::high_resolution_clock::now();
  proc_time = std::chrono::duration<double, std::milli>(t_end_memo2 - t_start_memo2).count();

  //cout << "AFTER" << endl;
  //print(memo);

  return val;
}

int main() {
  
  int capacity;
  vector<int> weights;
  vector<int> values;
  int expected;

  int caseNum = 5;

  switch (caseNum)
  {
    case 1:
      // TEST CASE 1
      capacity = 6;
      weights = {1,2,3,5};
      values = {1,5,4,8};
      expected = 10;
      break;

    case 2:
      // TEST CASE 2
      capacity = 3;
      weights = {4};
      values = {2};
      expected = 0;
      break;

    case 3:
      // TEST CASE 3
      capacity = 3;
      weights = {2};
      values = {3};
      expected = 3;
      break;

    case 4:
      // TEST CASE 4
      capacity = 10;
      weights = {3,6,10,7,2};
      values = {12,10,15,17,13};
      expected = 30;
      break;

    case 5:
      // TEST CASE 5
      capacity = 30;
      weights = {10,20,30};
      values = {22,33,44};
      expected = 55;
      break;

    case 6:
      // TEST CASE 6
      capacity = 10;
      weights = {1,2,3,8,7,4};
      values = {20,5,10,40,15,25};
      expected = 60;
      break;

    case 7:
      // TEST CASE 7
      capacity = 20;
      weights = {3,6,10,7,2,12,15,10,13,20};
      values = {12,10,15,17,13,12,30,15,18,20};
      expected = 55;
      break;
    
    default:
      // TEST CASE 1
      caseNum = 1;
      capacity = 6;
      weights = {1,2,3,5};
      values = {1,5,4,8};
      expected = 10;
      break;
  }

  //// SOLUTIONS

  // RECURSIVE
  auto t_start_rec = std::chrono::high_resolution_clock::now();
  int val_recursive = knapsack_recursive(capacity, weights, values, 0, 0, 0);
  auto t_end_rec = std::chrono::high_resolution_clock::now();
  double elapsed_time_recursive = std::chrono::duration<double, std::milli>(t_end_rec - t_start_rec).count();

  // RECURSIVE2
  auto t_start_rec2 = std::chrono::high_resolution_clock::now();
  int val_recursive2 = knapsack_recursive2(capacity, weights, values, 0, 0);
  auto t_end_rec2 = std::chrono::high_resolution_clock::now();
  double elapsed_time_recursive2 = std::chrono::duration<double, std::milli>(t_end_rec2 - t_start_rec2).count();

  // MEMOIZATION
  double proc_time;
  auto t_start_memo = std::chrono::high_resolution_clock::now();
  int val_memoization = knapsack_memoization(capacity, weights, values, proc_time);
  auto t_end_memo = std::chrono::high_resolution_clock::now();
  double elapsed_time_memoization = std::chrono::duration<double, std::milli>(t_end_memo - t_start_memo).count();

  // MEMOIZATION2
  double proc_time2;
  auto t_start_memo2 = std::chrono::high_resolution_clock::now();
  int val_memoization2 = knapsack_memoization2(capacity, weights, values, proc_time2);
  auto t_end_memo2 = std::chrono::high_resolution_clock::now();
  double elapsed_time_memoization2 = std::chrono::duration<double, std::milli>(t_end_memo2 - t_start_memo2).count();

  //// OUTPUT

  // RECURSIVE
  cout << "Case " << caseNum << ": Evaluating RECURSIVE..." << endl;
  if (val_recursive == expected && val_recursive2 == expected)
  {
    cout << "HURRAY!" << endl;
    cout << "val_recursive = expected = " << val_recursive << endl;
    cout << "val_recursive2 = expected = " << val_recursive2 << endl;
  }
  else
  {
    cout << "WHOOPS..." << endl;
    cout << "val_recursive = " << val_recursive << endl;
    cout << "val_recursive2 = " << val_recursive2 << endl;
    cout << "expected = " << expected << endl;
  }
  cout << "elapsed_time_recursive: " << elapsed_time_recursive << endl;
  cout << "elapsed_time_recursive2: " << elapsed_time_recursive2 << endl << endl;

  // MEMOIZATION
  cout << "Case " << caseNum << ": Evaluating MEMOIZATION..." << endl;
  if (val_memoization == expected)
  {
    cout << "HURRAY!" << endl;
    cout << "val_memoization = expected = " << val_memoization << endl;
  }
  else
  {
    cout << "WHOOPS..." << endl;
    cout << "val_memoization = " << val_memoization << endl;
    cout << "expected = " << expected << endl;
  }
  cout << "elapsed_time_memoization_recursion: " << proc_time << endl;
  cout << "elapsed_time_memoization_recursion2: " << proc_time2 << endl;
  cout << "elapsed_time_memoization: " << elapsed_time_memoization << endl;
  cout << "elapsed_time_memoization2: " << elapsed_time_memoization2 << endl;
  

  cout << "improvement (memoization vs. recursive): %" << (elapsed_time_recursive - proc_time) * 100 / elapsed_time_recursive << endl;
  cout << "improvement (memoization vs. recursive2): %" << (elapsed_time_recursive2 - proc_time) * 100 / elapsed_time_recursive2 << endl;

  cout << "improvement (memoization2 vs. recursive): %" << (elapsed_time_recursive - proc_time2) * 100 / elapsed_time_recursive << endl;
  cout << "improvement (memoization2 vs. recursive2): %" << (elapsed_time_recursive2 - proc_time2) * 100 / elapsed_time_recursive2 << endl;

  return 0;
}