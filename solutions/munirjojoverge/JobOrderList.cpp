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

#include <iostream>
#include <unordered_map>
#include <vector>

#define UNVISITED 0
#define VISITING 1
#define VISITED 2

using namespace std;

bool DFS(const int job, unordered_map<int, int>& visited,
         unordered_map<int, vector<int>>& deps, vector<int>& output) {
  if (visited[job] == VISITED) {
    return true;
  }

  visited[job] = VISITING;

  for (auto dep : deps[job]) {
    if (DFS(dep, visited, deps, output) == true) {
      return true;
    }
  }

  output.push_back(job);
  visited[job] = VISITED;
  return false;
}

unordered_map<int, vector<int>> get_job_deps(vector<vector<int>> deps) {
  unordered_map<int, vector<int>> job_deps;
  for (auto job_dep_pair : deps) {
    int job = job_dep_pair[0];
    int dep = job_dep_pair[1];

    auto it = job_deps.find(dep);
    if (it != job_deps.end()) {
      it->second.push_back(job);
    } else {
      job_deps.insert({dep, {job}});
    }
  }
  return job_deps;
}

unordered_map<int, int> init_visit(const vector<int>& jobs) {
  unordered_map<int, int> visited;
  for (auto job : jobs) {
    visited.insert({job, UNVISITED});
  }

  return visited;
}

vector<int> topologicalSort(vector<int> jobs, vector<vector<int>> deps) {
  /*
      This is a very classic problem for using DFS on directed graphs
      */
  vector<int> output;
  if (jobs.size() == 0) return output;

  unordered_map<int, vector<int>> job_deps = get_job_deps(deps);

  unordered_map<int, int> visited = init_visit(jobs);

  for (auto job : jobs) {
    bool Iscycle = DFS(job, visited, job_deps, output);
    if (Iscycle) {
      return {};
    } else
      return output;
  }
}

bool isValidTopologicalOrder(vector<int> order, vector<int> jobs,
                             vector<vector<int>> deps);

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