/*
##############################################
#          Coding Interview Questions
#      Created/Modified on: July 22, 2020
#           Author: Munir Jojo-Verge
##############################################
 */

/*
Consider a map (mxn) that contains: empty cells, obstacle cells and gem cells.
The objective is to determine what's the best position cell that has the
shortest accumulative distance to all gems.

Input Format
The map (mxn) that contains: empty cells (0s), obstacle cells (1s) and gem
cells(2s).

Output Format

The position of the cell that has the shortest accumulative distance to all
gems.

Sample Input
vector<vector<int> > map = {{0, 1, 2, 0, 0, 0},
                            {0, 1, 0, 0, 2, 0},
                            {0, 1, 0, 0, 0, 0},
                            {0, 1, 0, 2, 0, 0},
                            {0, 0, 0, 1, 1, 0}};

Sample Output
(1,3)

Explanation
vector<vector<int> > map = {{0, 1, 2, 0, 0, 0},
                            {0, 1, 0, X, 2, 0},
                            {0, 1, 0, 0, 0, 0},
                            {0, 1, 0, 2, 0, 0},
                            {0, 0, 0, 1, 1, 0}};


*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

enum { FREE_SPACE, OBSTACLE, GEM };

class Map {
 public:
  const static int mapWidth = 6;
  const static int mapHeight = 5;
  vector<vector<int>> grid = {{0, 1, 2, 0, 0, 0},
                              {0, 1, 0, 0, 2, 0},
                              {2, 1, 0, 0, 0, 0},
                              {0, 1, 0, 0, 0, 0},
                              {0, 0, 0, 1, 1, 2}};
};

int get_acc_gem_dis(const Map& map, int i, int j) {
  int acc_gem_dis{0};
  vector<vector<int>> dist_from_start(map.mapHeight,
                                      vector<int>(map.mapWidth, INT32_MAX));
  dist_from_start[i][j] = 0;

  vector<vector<bool>> visited(map.mapHeight,
                               vector<bool>(map.mapWidth, false));
  const int edge_d{1};

  queue<vector<int>> open;
  open.push({i, j});

  vector<vector<int>> movements{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

  while (!open.empty()) {
    auto curr_node{open.front()};
    auto x = curr_node[0];
    auto y = curr_node[1];
    open.pop();
    visited[x][y] = true;

    for (auto m : movements) {
      auto x2 = x + m[0];
      auto y2 = y + m[1];
      if (x2 >= 0 && x2 < map.mapHeight && y2 >= 0 && y2 < map.mapWidth &&
          (!visited[x2][y2] && map.grid[x2][y2] != OBSTACLE) &&
          (dist_from_start[x2][y2] == INT32_MAX)) {
        open.push({x2, y2});
        dist_from_start[x2][y2] = dist_from_start[x][y] + edge_d;
        if (map.grid[x2][y2] == GEM) {
          acc_gem_dis += dist_from_start[x2][y2];
        }
      }
    }
  }
  return acc_gem_dis;
}

vector<int> idx_smallest_acc_dist(const vector<vector<int>>& acc_gem_dist) {
  int min = INT32_MAX;
  int x{0};
  int y{0};

  for (int i = 0; i < acc_gem_dist.size(); ++i)
    for (int j = 0; j < acc_gem_dist[i].size(); ++j)
      if (acc_gem_dist[i][j] < min) {
        min = acc_gem_dist[i][j];
        x = i;
        y = j;
      }

  cout << "Min accumulated distance is " << min << " and is found at (" << x
       << "," << y << ")";

  return {x, y};
}

// O((V+E)*V)
vector<int> search(Map map) {
  vector<vector<int>> acc_gem_dist(map.mapHeight,
                                   vector<int>(map.mapWidth, INT32_MAX));
  for (size_t i = 0; i < map.mapHeight; ++i) {
    for (size_t j = 0; j < map.mapHeight; ++j) {
      if (map.grid[i][j] == FREE_SPACE) {
        acc_gem_dist[i][j] = get_acc_gem_dis(map, i, j);
      }
    }
  }
  return idx_smallest_acc_dist(acc_gem_dist);
}

int main() {
  // Instantiate a map objects

  Map map;

  auto pos = search(map);
  //   for (int i = 0; i < pos.size(); i++) {
  //     cout << pos[i] << " ";
  //   }
  //   cout << endl;

  return 0;
}
