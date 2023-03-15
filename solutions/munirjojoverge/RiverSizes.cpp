/*
##############################################
#          Coding Interview Questions
#      Created/Modified on: August 22, 2019
#           Author: Munir Jojo-Verge
##############################################
 */

/*
You are given a two-dimensional array (matrix) of potentially unequal height and
width containing only 0s and 1s. Each 0 represents land, and each 1 represents
part of a river. A river consists of any number of 1s that are either
horizontally or vertically adjacent (but not diagonally adjacent). The number of
adjacent 1s forming a river determine its size. Write a function that returns an
array of the sizes of all rivers represented in the input matrix. Note that
these sizes do not need to be in any particular order.
*/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int DFS(const size_t r, const size_t c, const vector<vector<int>>& matrix,
        vector<vector<bool>>& visited, int& curr_river_len) {
  if ((matrix[r][c] == 1) && (!visited[r][c])) {
    visited[r][c] = true;
    curr_river_len++;

    if (r > 0) {
      curr_river_len = DFS(r - 1, c, matrix, visited, curr_river_len);
    }

    if ((r + 1) < matrix.size()) {
      curr_river_len = DFS(r + 1, c, matrix, visited, curr_river_len);
    }

    if (c > 0) {
      curr_river_len = DFS(r, c - 1, matrix, visited, curr_river_len);
    }

    if ((c + 1) < matrix[0].size()) {
    }
    curr_river_len = DFS(r, c + 1, matrix, visited, curr_river_len);
  }
  return curr_river_len;
}

vector<int> riverSizes(vector<vector<int>> matrix) {
  // Write your code here.
  vector<int> river_lenghts;
  if (matrix.size() == 0) return river_lenghts;

  vector<vector<bool>> visited(matrix.size(),
                               vector<bool>(matrix[0].size(), false));
  int curr_river_len = 0;
  for (size_t r = 0; r < matrix.size(); r++) {
    for (size_t c = 0; c < matrix[0].size(); c++) {
      curr_river_len = DFS(r, c, matrix, visited, curr_river_len);
      if (curr_river_len > 0) {
        river_lenghts.push_back(curr_river_len);
        curr_river_len = 0;
      }
    }
  }
  return river_lenghts;
}

int DFS2(size_t i, size_t j, size_t len, vector<vector<int>>& matrix,
         vector<vector<bool>>& visited) {
  if (!visited[i][j]) {
    visited[i][j] = true;
    size_t num_rows = matrix.size();
    size_t num_cols = matrix[0].size();
    len++;

    // North
    if ((i + 1 < num_rows) && (matrix[i + 1][j] == 1)) {
      len = DFS2(i + 1, j, len, matrix, visited);
    };

    // South
    if ((i > 0) && (matrix[i - 1][j] == 1)) {
      len = DFS2(i - 1, j, len, matrix, visited);
    };

    // West
    if ((j > 0) && (matrix[i][j - 1] == 1)) {
      len = DFS2(i, j - 1, len, matrix, visited);
    };

    // East
    if ((j + 1 < num_cols) && (matrix[i][j + 1] == 1)) {
      len = DFS2(i, j + 1, len, matrix, visited);
    };
  }
  return len;
}

vector<int> riverSizes2(vector<vector<int>> matrix) {
  // Write your code here.
  vector<int> riversLen;
  vector<vector<bool>> visited(matrix.size(),
                               vector<bool>(matrix[0].size(), false));
  for (size_t i = 0; i < matrix.size(); i++) {
    for (size_t j = 0; j < matrix[0].size(); j++) {
      if (matrix[i][j] == 1 && !visited[i][j]) {
        riversLen.push_back(DFS2(i, j, 0, matrix, visited));
      }
    }
  }
  return riversLen;
}

int main() {
  vector<vector<int>> testInput;
  vector<int> expected;
  vector<int> output;

  cout << "Test Case 1: ";
  testInput = {{0}};
  expected = {};
  output = riverSizes(testInput);
  sort(output.begin(), output.end());
  cout << (output == expected ? "PASS" : "FAIL") << endl;

  cout << "Test Case 2: ";
  testInput = {{1}};
  expected = {1};
  output = riverSizes(testInput);
  sort(output.begin(), output.end());
  cout << (output == expected ? "PASS" : "FAIL") << endl;

  cout << "Test Case 3: ";
  testInput = {{1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 0}};
  expected = {1, 2, 3};
  output = riverSizes(testInput);
  sort(output.begin(), output.end());
  cout << (output == expected ? "PASS" : "FAIL") << endl;

  cout << "Test Case 4: ";
  testInput = {
      {1, 0, 0, 1},
      {1, 0, 1, 0},
      {0, 0, 1, 0},
      {1, 0, 1, 0},
  };
  expected = {1, 1, 2, 3};
  output = riverSizes(testInput);
  sort(output.begin(), output.end());
  cout << (output == expected ? "PASS" : "FAIL") << endl;

  cout << "Test Case 5: ";
  testInput = {
      {1, 0, 0, 1, 0}, {1, 0, 1, 0, 0}, {0, 0, 1, 0, 1},
      {1, 0, 1, 0, 1}, {1, 0, 1, 1, 0},
  };
  expected = {1, 2, 2, 2, 5};
  output = riverSizes(testInput);
  sort(output.begin(), output.end());
  cout << (output == expected ? "PASS" : "FAIL") << endl;

  cout << "Test Case 6: ";
  testInput = {
      {1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0},
      {1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0},
      {0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1},
      {1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0},
      {1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1},
  };
  expected = {1, 1, 2, 2, 5, 21};
  output = riverSizes(testInput);
  sort(output.begin(), output.end());
  cout << (output == expected ? "PASS" : "FAIL") << endl;

  cout << "Test Case 7: ";
  testInput = {
      {1, 0, 0, 0, 0, 0, 1}, {0, 1, 0, 0, 0, 1, 0}, {0, 0, 1, 0, 1, 0, 0},
      {0, 0, 0, 1, 0, 0, 0}, {0, 0, 1, 0, 1, 0, 0}, {0, 1, 0, 0, 0, 1, 0},
      {1, 0, 0, 0, 0, 0, 1},
  };
  expected = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  output = riverSizes(testInput);
  sort(output.begin(), output.end());
  cout << (output == expected ? "PASS" : "FAIL") << endl;

  cout << "Test Case 8: ";
  testInput = {
      {1, 0, 0, 0, 0, 0, 1}, {0, 1, 0, 0, 0, 1, 0}, {0, 0, 1, 0, 1, 0, 0},
      {0, 0, 1, 1, 1, 0, 0}, {0, 0, 1, 0, 1, 0, 0}, {0, 1, 0, 0, 0, 1, 0},
      {1, 0, 0, 0, 0, 0, 1},
  };
  expected = {1, 1, 1, 1, 1, 1, 1, 1, 7};
  output = riverSizes(testInput);
  sort(output.begin(), output.end());
  cout << (output == expected ? "PASS" : "FAIL") << endl;

  cout << "Test Case 9: ";
  testInput = {
      {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0},
  };
  expected = {};
  output = riverSizes(testInput);
  sort(output.begin(), output.end());
  cout << (output == expected ? "PASS" : "FAIL") << endl;

  cout << "Test Case 10: ";
  testInput = {
      {1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 1},
  };
  expected = {49};
  output = riverSizes(testInput);
  sort(output.begin(), output.end());
  cout << (output == expected ? "PASS" : "FAIL") << endl;

  cout << "Test Case 11: ";
  testInput = {
      {1, 1, 0, 0, 0, 0, 1, 1},
      {1, 0, 1, 1, 1, 1, 0, 1},
      {0, 1, 1, 0, 0, 0, 1, 1},
  };
  expected = {3, 5, 6};
  output = riverSizes(testInput);
  sort(output.begin(), output.end());
  cout << (output == expected ? "PASS" : "FAIL") << endl;

  cout << "Test Case 12: ";
  testInput = {
      {1, 1, 0}, {1, 0, 1}, {1, 1, 1}, {1, 1, 0}, {1, 0, 1}, {0, 1, 0},
      {1, 0, 0}, {1, 0, 0}, {0, 0, 0}, {1, 0, 0}, {1, 0, 1}, {1, 1, 1},
  };
  expected = {1, 1, 2, 6, 10};
  output = riverSizes(testInput);
  sort(output.begin(), output.end());
  cout << (output == expected ? "PASS" : "FAIL") << endl;
}
