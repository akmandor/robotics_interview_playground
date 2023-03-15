/*
##############################################
#          Coding Interview Questions
#      Created/Modified on: June 24, 2020
#           Author: Munir Jojo-Verge
##############################################
 */

/*
Consider an undirected graph consisting of n nodes where each node is labeled
from 1 to n and the edge between any two nodes is always of length 6. We define
node S to be the starting position for a BFS. Given a graph, determine the
distances from the start node to each of its descendants and return the list in
node number order, ascending. If a node is disconnected, it's distance should be
.

For example, there are  nodes in the graph with a starting node . The list of ,
and each has a weight of .

image

Starting from node  and creating a list of distances, for nodes  through  we
have .

Function Description

Define a Graph class with the required methods to return a list of distances.

Input Format

The first line contains an integer, , the number of queries.

Each of the following  sets of lines is as follows:

The first line contains two space-separated integers,  and , the number of nodes
and the number of edges. Each of the next  lines contains two space-separated
integers,  and , describing an edge connecting node  to node . The last line
contains a single integer, , the index of the starting node. Constraints

Output Format

For each of the  queries, print a single line of  space-separated integers
denoting the shortest distances to each of the  other nodes from starting
position . These distances should be listed sequentially by node number (i.e.,
), but should not include node . If some node is unreachable from , print  as
the distance to that node.

Sample Input

2
4 2
1 2
1 3
1
3 1
2 3
2
Sample Output

6 6 -1
-1 6
Explanation

We perform the following two queries:

The given graph can be represented as:
image where our start node, , is node . The shortest distances from  to the
other nodes are one edge to node , one edge to node , and there is no connection
to node . The given graph can be represented as: image where our start node, ,
is node . There is only one edge here, so node  is unreachable from node  and
node has one edge connecting it to node . We then print node 's distance to
nodes and (respectively) as a single line of space-separated integers: -1 6.

Note: Recall that the actual length of each edge is , and we print  as the
distance to any node that's unreachable from .
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Graph {
 public:
  int num_nodes;
  vector<vector<int>> adj;
  Graph(int n) {
    num_nodes = n;
    adj.resize(num_nodes);
  }

  void add_edge(int u, int v) {
    if ((u > -1) && (v > -1)) {
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
  }

  vector<int> shortest_reach(int start) {
    vector<int> dist_from_start(num_nodes, INT32_MAX);
    dist_from_start[start] = 0;

    queue<int> open;
    vector<bool> visited(num_nodes, false);
    const int edge_d{6};
    open.push(start);

    while (!open.empty()) {
      int curr_node{open.front()};
      open.pop();
      visited[curr_node] = true;

      for (auto neig : adj[curr_node]) {
        if (!visited[neig]) {
          // auto tmp_dist = dist_from_start[curr_node] + edge_d;
          if (dist_from_start[neig] == -1) {
            open.push(neig);
            dist_from_start[neig] = dist_from_start[curr_node] + edge_d;
          }
        }
      }
    }
    // std::sort(dist_from_start.begin(), dist_from_start.end());
    // dist_from_start.erase(dist_from_start.begin() + start,
    //                       dist_from_start.begin() + start + 1);
    return dist_from_start;
  }
};

int main() {
  int queries;
  cin >> queries;

  for (int t = 0; t < queries; t++) {
    int n, m;
    cin >> n;
    // Create a graph of size n where each edge weight is 6:
    Graph graph(n);
    cin >> m;
    // read and set edges
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      // add each edge to the graph
      graph.add_edge(u, v);
    }
    int startId;
    cin >> startId;
    startId--;
    // Find shortest reach from node s
    vector<int> distances = graph.shortest_reach(startId);

    for (int i = 0; i < distances.size(); i++) {
      if (i != startId) {
        cout << distances[i] << " ";
      }
    }
    cout << endl;
  }

  return 0;
}