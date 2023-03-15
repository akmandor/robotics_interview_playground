/*
##############################################
#          Coding Interview Questions
#      Created/Modified on: June 24, 2020
#           Author: Munir Jojo-Verge
##############################################
 */

/*
The Ruler of HackerLand believes that every citizen of the country should have
access to a library. Unfortunately, HackerLand was hit by a tornado that
destroyed all of its libraries and obstructed its roads! As you are the greatest
programmer of HackerLand, the ruler wants your help to repair the roads and
build some new libraries efficiently.

HackerLand has  cities numbered from  to . The cities are connected by
bidirectional roads. A citizen has access to a library if:

Their city contains a library.
They can travel by road from their city to a city containing a library.
The following figure is a sample map of HackerLand where the dotted lines denote
obstructed roads:

image

The cost of repairing any road is  dollars, and the cost to build a library in
any city is  dollars. If in the above example  and , we would build  roads at a
cost of  and  libraries for a cost of . We don't need to rebuild one of the
roads in the cycle .

You are given  queries, where each query consists of a map of HackerLand and
value of  and . For each query, find the minimum cost of making libraries
accessible to all the citizens and print it on a new line.

Function Description

Complete the function roadsAndLibraries in the editor below. It must return the
minimal cost of providing libraries to all, as an integer.

roadsAndLibraries has the following parameters:

n: integer, the number of cities
c_lib: integer, the cost to build a library
c_road: integer, the cost to repair a road
cities: 2D array of integers where each  contains two integers that represent
cities connected by an obstructed road . Input Format

The first line contains a single integer , that denotes the number of queries.

The subsequent lines describe each query in the following format:
- The first line contains four space-separated integers that describe the
respective values of , ,  and , the number of cities, number of roads, cost of a
library and cost of a road.
- Each of the next  lines contains two space-separated integers,  and , that
describe a bidirectional road that connects cities  and .

Constraints

Each road connects two distinct cities.
Output Format

For each query, print an integer that denotes the minimum cost to make libraries
accessible to all the citizens on a new line.

Sample Input

2
3 3 2 1
1 2
3 1
2 3
6 6 2 5
1 3
3 4
2 4
1 2
2 3
5 6
Sample Output

4
12
Explanation

Perform the following  queries:

HackerLand contains  cities connected by  bidirectional roads. The price of
building a library is  and the price for repairing a road is . image The
cheapest way to make libraries accessible to all is to:

Build a library in city  at a cost of .
Repair the road between cities  and  at a cost of .
Repair the road between cities  and  at a cost of .
This gives a total cost of . Note that the road between cities  and  does not
need to be repaired each is connected to city .

In this scenario it is optimal to build a library in each city because the cost
of building a library () is less than the cost of repairing a road (). image

There are 6 cities, so the total cost is 12.
*/
#include <bits/stdc++.h>
#include <vector>

using namespace std;

vector<string> split_string(string);

void DFS1(const int city, const vector<vector<int>>& neigs,
          vector<bool>& visited, long long int& num_roads) {
  visited[city] = true;
  for (auto neig : neigs[city]) {
    if (!visited[neig]) {
      ++num_roads;
      DFS1(neig, neigs, visited, num_roads);
    }
  }
}

long long int get_min_cost(const size_t num_cities, const size_t num_roads,
                           const int c_lib, const int c_road,
                           const vector<vector<int>>& neigs) {
  // // long num_cycles = get_num_cycles(num_cities, neigs);
  // size_t num_roads_needed = get_num_roads(num_cities, neigs);
  // size_t num_libraries_needed = get_num_groups(num_cities, neigs);

  vector<bool> visited(num_cities, false);
  long long int num_roads_needed{0};
  long long int num_libraries_needed{0};

  for (size_t city = 0; city < num_cities; ++city) {
    if (!visited[city]) {
      ++num_libraries_needed;
      DFS1(city, neigs, visited, num_roads_needed);
    }
  }
  return ((num_roads_needed * c_road) + (num_libraries_needed * c_lib));
}

// Complete the roadsAndLibraries function below.
long long int roadsAndLibraries(int n, int c_lib, int c_road,
                                vector<vector<int>> cities) {
  // The rationale is:
  // 1) No matter the cost of c_road or c_lib, we want to detect cycles and
  // avoid them.
  // 2) if c_road < c_lib, then we will put a library in each acyclic
  // group.
  // 3) if c_road >= c_lib, then we just put a library in each town and
  // NO roads.
  // 4) We are not alowed to "crerate" roads (as in connect cities
  // that they were previoslly not connected)

  if (c_road >= c_lib) {
    return (static_cast<long long int>(n) * c_lib);
  } else {
    // This is an Undirected graph and the best way to represent this is
    // whith a bi-directional Directed graph.
    size_t num_roads{cities.size()};
    vector<vector<int>> neigs(n, vector<int>());
    for (size_t i = 0; i < num_roads; ++i) {
      int city1 = cities[i][0] - 1;
      int city2 = cities[i][1] - 1;
      neigs[city1].push_back(city2);
      neigs[city2].push_back(city1);
    }
    return get_min_cost(n, num_roads, c_lib, c_road, neigs);
  }
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  int q;
  cin >> q;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int q_itr = 0; q_itr < q; q_itr++) {
    string nmC_libC_road_temp;
    getline(cin, nmC_libC_road_temp);

    vector<string> nmC_libC_road = split_string(nmC_libC_road_temp);

    int n = stoi(nmC_libC_road[0]);

    int m = stoi(nmC_libC_road[1]);

    int c_lib = stoi(nmC_libC_road[2]);

    int c_road = stoi(nmC_libC_road[3]);

    vector<vector<int>> cities(m);
    for (int i = 0; i < m; i++) {
      cities[i].resize(2);

      for (int j = 0; j < 2; j++) {
        cin >> cities[i][j];
      }

      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long long int result = roadsAndLibraries(n, c_lib, c_road, cities);

    fout << result << "\n";
  }

  fout.close();

  return 0;
}

vector<string> split_string(string input_string) {
  string::iterator new_end =
      unique(input_string.begin(), input_string.end(),
             [](const char& x, const char& y) { return x == y and x == ' '; });

  input_string.erase(new_end, input_string.end());

  while (input_string[input_string.length() - 1] == ' ') {
    input_string.pop_back();
  }

  vector<string> splits;
  char delimiter = ' ';

  size_t i = 0;
  size_t pos = input_string.find(delimiter);

  while (pos != string::npos) {
    splits.push_back(input_string.substr(i, pos - i));

    i = pos + 1;
    pos = input_string.find(delimiter, i);
  }

  splits.push_back(
      input_string.substr(i, min(pos, input_string.length()) - i + 1));

  return splits;
}