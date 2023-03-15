// LAST UPDATE: 2022.03.15
//
// AUTHOR: Neset Unver Akmandor (NUA)
//
// E-MAIL: akmandor.n@northeastern.edu
//
// DESCRIPTION: TODO...
//
// REFERENCES:
// [1] https://github.com/munirjojoverge/Coding-Interview-Questions

#include <string.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define FREE_SPACE 0
#define NOT_VISITED 0

// Map class
class Map {
 public:
  const static int mapWidth = 6;
  const static int mapHeight = 5;
  vector<vector<int> > grid = {{0, 1, 0, 0, 0, 0},
                               {0, 1, 0, 0, 0, 0},
                               {0, 1, 0, 0, 0, 0},
                               {0, 1, 0, 0, 0, 0},
                               {0, 0, 0, 1, 1, 0}};

  vector<vector<int> > heuristic = {{9, 8, 7, 6, 5, 4},
                                    {8, 7, 6, 5, 4, 3},
                                    {7, 6, 5, 4, 3, 2},
                                    {6, 5, 4, 3, 2, 1},
                                    {5, 4, 3, 2, 1, 0}};
};

// Planner class
class Planner : Map {
 public:
  int start[2] = {0, 0};
  int goal[2] = {mapHeight - 1, mapWidth - 1};
  int cost = 1;

  string movements_arrows[4] = {"^", "<", "v", ">"};

  vector<vector<int> > movements{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
};

// Template function to print 2D vectors of any type
template <typename T>
void print2DVector(T Vec) {
  for (int i = 0; i < Vec.size(); ++i) {
    for (int j = 0; j < Vec[0].size(); ++j) {
      cout << Vec[i][j] << ' ';
    }
    cout << endl;
  }
}

// Search function will generate the expansions
void search(Map map, Planner planner) {
  
}

int main() {

  cout << "PROBLEM: A_star" << endl;

  // Instantiate a planner and map objects
  Map map;
  Planner planner;

  search(map, planner);

  return 0;
}