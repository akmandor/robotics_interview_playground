/*
##############################################
#          Coding Interview Questions
#      Created/Modified on: June 16, 2020
#           Author: Munir Jojo-Verge
##############################################
*/
/*
Problem Introduction
A Computer Science curriculum specifies the prerequisites for each course as a
list of courses that should be taken before taking this course. You would like
to perform a consistency check of the curriculum, that is, to check that there
are no cyclic dependencies. For this, you construct the following directed
graph: vertices correspond to courses, there is a directed edge (u, v) is the
course u should be taken before the course v. Then, it is enough to check
whether the resulting graph contains a cycle.

Problem Description Task.
Check whether a given directed graph with n vertices and m edges contains a
cycle.
Input Format.
A graph is given in the standard format. Constraints. 1 ≤ n ≤ 10^3 , 0 ≤ m ≤
10^3.

Output Format.
Output 1 if the graph contains a cycle and 0 otherwise.
*/

#include <iostream>
#include <vector>

using namespace std;

enum { NOT_EXPLORED, BEING_EXPLORED, FULLY_EXPLORED };

bool explore(vector<vector<int> >& adj, vector<int>& state, int curr_node) {
  state[curr_node] = BEING_EXPLORED;
  bool IsCycle = false;
  size_t i = 0;
  while ((i < adj[curr_node].size()) && (IsCycle == false)) {
    if (state[adj[curr_node][i]] == NOT_EXPLORED)  //
      IsCycle = explore(adj, state, adj[curr_node][i]);
    else if (state[adj[curr_node][i]] == BEING_EXPLORED)  // there is a cycle
    {
      IsCycle = true;
    }
    i++;
  }
  state[curr_node] = FULLY_EXPLORED;
  return IsCycle;
}

int acyclic(vector<vector<int> >& adj, int n_vertices, int n_edges) {
  // write your code here
  if (n_vertices == 0 || n_edges == 0) return 0;

  // We need to choose the first node with a connection. Not necessarly we will
  // have vertix 0 with a connection!
  bool IsCycle = false;
  size_t i = 0;
  vector<int> state(n_vertices, NOT_EXPLORED);  // 0 = Not Explored, 1 = Being
                                                // Explored, 2 = Fully explored

  while ((i < n_vertices) && (IsCycle == false)) {
    IsCycle = explore(adj, state, i);
    i++;
  }
  return IsCycle;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());

  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj, n, m) << std::endl;
}
