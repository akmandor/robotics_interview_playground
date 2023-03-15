/*
##############################################
#          Coding Interview Questions
#      Created/Modified on: Jun 17, 2020
#           Author: Munir Jojo-Verge
##############################################
 */

/*
You're given a non-empty array of arrays where each subarray holds three
integers and represents a disk. These integers denote each disk's width,
depth, and height, respectively. Your goal is to stack up the disks and to
maximize the total height of the stack. A disk must have a strictly smaller
width, depth, and height than any other disk below it.


Write a function that returns an array of the disks in the final stack,
starting with the top disk and ending with the bottom disk. Note that you
can't rotate disks; in other words, the integers in each subarray must
represent [width, depth, height] at all times.


You can assume that there will only be one stack with the greatest total
height.

Sample Input
disks = [[2, 1, 2], [3, 2, 3], [2, 2, 8], [2, 3, 4], [1, 3, 1], [4, 4, 5]]

Sample Output
[[2, 1, 2], [3, 2, 3], [4, 4, 5]]

*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool validOnTop(const vector<int>& b1, const vector<int>& b2) {
  return (b1[0] > b2[0] && b1[1] > b2[1] && b1[2] > b2[2]);
}

vector<vector<int>> build_sequence(const vector<vector<int>>& disks,
                                   const vector<long long int>& sequence,
                                   const long long int total_max_height_idx) {
  vector<vector<int>> result;
  long long int idx = total_max_height_idx;
  if (idx == sequence[idx]) return {disks[idx]};

  while (idx != sequence[idx]) {
    result.push_back(disks[idx]);
    idx = sequence[idx];
  }
  // the last box
  result.push_back(disks[idx]);

  std::reverse(result.begin(), result.end());
  return result;
}

vector<vector<int>> diskStacking(vector<vector<int>> disks) {
  // Write your code here.

  // let's order first the disks by height
  std::sort(disks.begin(), disks.end(),
            [](vector<int>& b1, vector<int>& b2) { return (b1[2] < b2[2]); });

  // Create anbd initialize max_heights vector that will contain, just that.
  vector<long long int> max_heights;

  // create the vector that will hold "what disk goes on top of me" for every
  // index
  vector<long long int> sequence;

  for (size_t i = 0; i < disks.size(); i++) {
    max_heights.push_back(disks[i][2]);
    sequence.push_back(i);
  }

  long long int max_height_idx = 0;

  for (size_t i = 1; i < disks.size(); i++) {
    for (size_t j = 0; j < i; j++) {
      if (validOnTop(disks[i], disks[j])) {
        if (max_heights[i] < (disks[i][2] + max_heights[j])) {
          max_heights[i] = (disks[i][2] + max_heights[j]);
          sequence[i] = j;
        }
      }
    }
    if (max_heights[i] > max_heights[max_height_idx]) {
      max_height_idx = i;
    }
  }

  return build_sequence(disks, sequence, max_height_idx);
}

int main() {
  vector<vector<int>> disks;
  vector<vector<int>> expected;
  vector<vector<int>> result;

  cout << "Test Case 1: ";
  disks = {{2, 1, 2}, {3, 2, 3}, {2, 2, 8}, {2, 3, 4}, {1, 3, 1}, {4, 4, 5}};
  expected = {{2, 1, 2}, {3, 2, 3}, {4, 4, 5}};
  result = diskStacking(disks);
  cout << (result == expected ? "PASS" : "FAIL") << endl;

  cout << "Test Case 2: ";
  disks = {{2, 1, 2}};
  expected = {{2, 1, 2}};
  result = diskStacking(disks);
  cout << (result == expected ? "PASS" : "FAIL") << endl;
}