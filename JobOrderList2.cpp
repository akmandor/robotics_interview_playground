/*
##############################################
#          Coding Interview Questions
#      Created/Modified on: August 23, 2019
#           Author: Munir Jojo-Verge
##############################################
 */

/*
You are given a list of arbitrary jobs that need to be completed; these jobs are
represented by integers. You are also given a list of dependencies. A dependency
is represented as a pair of jobs where the first job is prerequisite of the
second one. In other words, the second job depends on the first one; it can only
be completed once the first job is completed. Write a function that takes in a
list of jobs and a list of dependencies and returns a list containing a valid
order in which the given jobs can be completed. If no such order exists, the
function should return an empty list.

Sample input: [1, 2, 3, 4], [[1, 2], [1, 3], [3, 2], [4, 2], [4, 3]]
Sample output: [1, 4, 3, 2] or [4, 1, 3, 2]
*/

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

enum { UNVISITED, VISITING, VISITED };

int find_job_idx(const vector<int>& jobs, int job) {
  auto result = std::find(std::begin(jobs), std::end(jobs), job);

  if (result != std::end(jobs)) {
    return (int)(result - std::begin(jobs));
  } else {
    return -1;
  }
}

vector<int> DFS(const vector<int>& jobs, const int job_idx,
                const vector<vector<int>>& deps, vector<int>& status,
                vector<int>& result) {
  if (status[job_idx] == VISITING)  // We found a cycle!!!
    return {};

  if (status[job_idx] == UNVISITED) {
    status[job_idx] = VISITING;
    int d = 0;
    while (d < deps.size() && deps[d][0] <= jobs[job_idx]) {
      if (deps[d][0] == jobs[job_idx]) {
        result =
            DFS(jobs, find_job_idx(jobs, deps[d][1]), deps, status, result);
        if (result.empty()) return result;
      }
      d++;
    }
    result.push_back(jobs[job_idx]);
  }
  status[job_idx] = VISITED;
  return result;
}

vector<int> topologicalSort(vector<int> jobs, vector<vector<int>> deps) {
  // let's not assume that jobs are in order. Since we wil need to find job idx,
  // let's order them
  std::sort(jobs.begin(), jobs.end());

  // Similar with deps...If thgey are in order of the first item, it will make
  // it easier to traverse while looking for the dependencies of an specific job
  std::sort(deps.begin(), deps.end());

  vector<int> result;
  vector<int> status(jobs.size(), UNVISITED);
  for (size_t j = 0; j < jobs.size(); j++) {
    result = DFS(jobs, j, deps, status, result);
  }
  std::reverse(result.begin(), result.end());
  return result;
}

bool isValidTopologicalOrder(vector<int> order, vector<int> jobs,
                             vector<vector<int>> deps) {
  unordered_map<int, bool> visited;
  for (int candidate : order) {
    for (vector<int> dep : deps) {
      if (candidate == dep[0] && visited.find(dep[1]) != visited.end())
        return false;
    }
    visited[candidate] = true;
  }
  for (int job : jobs) {
    if (visited.find(job) == visited.end()) return false;
  }
  return order.size() == jobs.size();
}

int main() {
  vector<int> jobs;
  vector<vector<int>> deps;
  vector<int> order;

  cout << "Test Case 1: ";
  jobs = {1, 2, 3, 4, 5, 6, 7, 8};
  deps = {{3, 1}, {8, 1}, {8, 7}, {5, 7}, {5, 2},
          {1, 4}, {1, 6}, {1, 2}, {7, 6}};
  order = topologicalSort(jobs, deps);
  cout << ((isValidTopologicalOrder(order, jobs, deps) == true) ? "PASS"
                                                                : "FAIL")
       << endl;

  cout << "Test Case 2: ";
  jobs = {1, 2, 3, 4, 5, 6, 7, 8};
  deps = {{3, 1}, {8, 1}, {8, 7}, {5, 7}, {5, 2},
          {1, 4}, {6, 7}, {1, 2}, {7, 6}};
  order = topologicalSort(jobs, deps);
  cout << ((order == vector<int>{}) ? "PASS" : "FAIL") << endl;

  cout << "Test Case 3: ";
  jobs = {1, 2, 3, 4, 5, 6, 7, 8};
  deps = {{3, 1}, {8, 1}, {8, 7}, {5, 7}, {5, 2}, {1, 4},
          {1, 6}, {1, 2}, {7, 6}, {4, 6}, {6, 2}, {2, 3}};
  order = topologicalSort(jobs, deps);
  cout << ((order == vector<int>{}) ? "PASS" : "FAIL") << endl;

  cout << "Test Case 4: ";
  jobs = {1, 2, 3, 4, 5, 6, 7, 8};
  deps = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}, {7, 8}, {8, 1}};
  order = topologicalSort(jobs, deps);
  cout << ((order == vector<int>{}) ? "PASS" : "FAIL") << endl;

  cout << "Test Case 5: ";
  jobs = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  deps = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {7, 6}, {7, 8}, {8, 1}};
  order = topologicalSort(jobs, deps);
  cout << ((isValidTopologicalOrder(order, jobs, deps) == true) ? "PASS"
                                                                : "FAIL")
       << endl;

  cout << "Test Case 6: ";
  jobs = {1, 2, 3, 4, 5, 6, 7, 8};
  deps = {{1, 2}, {3, 5}, {4, 6}, {3, 6}, {1, 7}, {7, 8}, {1, 8}, {2, 8}};
  order = topologicalSort(jobs, deps);
  cout << ((isValidTopologicalOrder(order, jobs, deps) == true) ? "PASS"
                                                                : "FAIL")
       << endl;

  cout << "Test Case 7: ";
  jobs = {1, 2, 3, 4, 5, 6, 7, 8};
  deps = {
      {1, 2}, {1, 3}, {1, 4}, {1, 5}, {1, 6}, {1, 7},
      {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8},
  };
  order = topologicalSort(jobs, deps);
  cout << ((isValidTopologicalOrder(order, jobs, deps) == true) ? "PASS"
                                                                : "FAIL")
       << endl;

  cout << "Test Case 8: ";
  jobs = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  deps = {
      {1, 2}, {1, 3}, {1, 4}, {1, 5},  {1, 6},   {1, 7},   {2, 8},  {3, 8},
      {4, 8}, {5, 8}, {6, 8}, {7, 8},  {2, 3},   {2, 4},   {5, 4},  {7, 6},
      {6, 2}, {6, 3}, {6, 5}, {5, 9},  {9, 8},   {8, 0},   {4, 0},  {5, 0},
      {9, 0}, {2, 0}, {3, 9}, {3, 10}, {10, 11}, {11, 12}, {2, 12},
  };
  order = topologicalSort(jobs, deps);
  cout << ((isValidTopologicalOrder(order, jobs, deps) == true) ? "PASS"
                                                                : "FAIL")
       << endl;

  cout << "Test Case 9: ";
  jobs = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  deps = {
      {1, 2}, {1, 3}, {1, 4}, {1, 5},  {1, 6},   {1, 7},   {2, 8},  {3, 8},
      {4, 8}, {5, 8}, {6, 8}, {7, 8},  {2, 3},   {2, 4},   {5, 4},  {7, 6},
      {6, 2}, {6, 3}, {6, 5}, {5, 9},  {9, 8},   {8, 0},   {4, 0},  {5, 0},
      {9, 0}, {2, 0}, {3, 9}, {3, 10}, {10, 11}, {11, 12}, {12, 2},
  };
  order = topologicalSort(jobs, deps);
  cout << ((order == vector<int>{}) ? "PASS" : "FAIL") << endl;

  cout << "Test Case 10: ";
  jobs = {1, 2, 3, 4};
  deps = {{1, 2}, {1, 3}, {3, 2}, {4, 2}, {4, 3}};
  order = topologicalSort(jobs, deps);
  cout << ((isValidTopologicalOrder(order, jobs, deps) == true) ? "PASS"
                                                                : "FAIL")
       << endl;

  cout << "Test Case 11: ";
  jobs = {1, 2, 3, 4, 5};
  deps = {};
  order = topologicalSort(jobs, deps);
  cout << ((isValidTopologicalOrder(order, jobs, deps) == true) ? "PASS"
                                                                : "FAIL")
       << endl;

  cout << "Test Case 12: ";
  jobs = {1, 2, 3, 4, 5};
  deps = {{1, 4}, {5, 2}};
  order = topologicalSort(jobs, deps);
  cout << ((isValidTopologicalOrder(order, jobs, deps) == true) ? "PASS"
                                                                : "FAIL")
       << endl;
}