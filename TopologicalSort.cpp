/*
##############################################
#          Coding Interview Questions
#      Created/Modified on: June 16, 2020
#           Author: Munir Jojo-Verge
##############################################
 */

/*

You're given a list of arbitrary jobs that need to be completed; these jobs
are represented by distinct integers. You're also given a list of dependencies.
A dependency is represented as a pair of jobs where the first job is a
prerequisite of the second one. In other words, the second job depends on the
first one; it can only be completed once the first job is completed.


Write a function that takes in a list of jobs and a list of dependencies and
returns a list containing a valid order in which the given jobs can be
completed. If no such order exists, the function should return an empty array.

Sample Input
jobs = [1, 2, 3, 4]
deps = [[1, 2], [1, 3], [3, 2], [4, 2], [4, 3]]

Sample Output
[1, 4, 3, 2] or [4, 1, 3, 2]

*/

#include <algorithm>
#include <iostream>
#include <vector>

#include <cassert>

// Use (void) to silent unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))

using namespace std;

int find_job_idx(const vector<int>& jobs, int job) {
  auto result = std::find(std::begin(jobs), std::end(jobs), job);

  if (result != std::end(jobs)) {
    return (int)(result - std::begin(jobs));
  } else {
    return -1;
  }
}

vector<int> DFS(const vector<int>& jobs, const int job_idx,
                const vector<vector<int>>& deps, vector<bool>& visited,
                vector<bool>& exploring, vector<int>& result) {
  if (exploring[job_idx])  // We found a cycle!!!
    return {};

  exploring[job_idx] = true;
  if (!visited[job_idx]) {
    visited[job_idx] = true;
    int d = 0;
    while (d < deps.size() && deps[d][0] <= jobs[job_idx]) {
      if (deps[d][0] == jobs[job_idx]) {
        result = DFS(jobs, find_job_idx(jobs, deps[d][1]), deps, visited,
                     exploring, result);
        if (result.empty()) return result;
      }
      d++;
    }
    result.push_back(jobs[job_idx]);
  }
  exploring[job_idx] = false;
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
  vector<bool> visited(jobs.size(), false);
  vector<bool> exploring(jobs.size(), false);
  for (size_t job_idx = 0; job_idx < jobs.size(); job_idx++) {
    result = DFS(jobs, job_idx, deps, visited, exploring, result);
  }
  std::reverse(result.begin(), result.end());
  return result;
}

int main() {
  vector<int> jobs;
  vector<vector<int>> deps;
  vector<int> expected_result;

  cout << "---------- Test Case 1 ----------" << endl;
  jobs = {1, 2, 3, 4};
  deps = {{1, 2}, {1, 3}, {3, 2}, {4, 2}, {4, 3}};
  expected_result = {4, 1, 3, 2};
  assertm(topologicalSort(jobs, deps) == expected_result, "FAILED");

  cout << "---------- Test Case 2 ----------" << endl;
  jobs = {1, 2, 3, 4, 5, 6, 7, 8};
  deps = {{3, 1}, {8, 1}, {8, 7}, {5, 7}, {5, 2},
          {1, 4}, {6, 7}, {1, 2}, {7, 6}};
  expected_result = {};
  assertm(topologicalSort(jobs, deps) == expected_result, "FAILED");
}
