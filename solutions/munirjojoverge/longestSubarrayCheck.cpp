/*
##############################################
#          Coding Interview Questions
#      Created/Modified on: August 23, 2019
#           Author: Munir Jojo-Verge
##############################################
 */

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

std::vector<int> get_longuest_subarray(const std::vector<int>& a) {
  std::vector<int> longuest_subarray;
  std::vector<int> tmp_subarray;
  tmp_subarray.push_back(a[0]);
  for (size_t i = 1; i < a.size(); ++i) {
    if (a[i] <= a[i - 1]) {
      tmp_subarray.clear();
    }
    tmp_subarray.push_back(a[i]);
    if (longuest_subarray.size() <= tmp_subarray.size()) {
      longuest_subarray = tmp_subarray;
    }
  }
  return longuest_subarray;
}
void map_b(const std::vector<int>& b, std::unordered_map<int, bool>& u_map) {
  for (size_t i = 0; i < b.size(); ++i) {
    u_map.insert(std::make_pair(b[i], true));
  }
}

bool b_belongs_c(const std::vector<int>& b,
                 const std::unordered_map<int, bool>& u_map) {
  for (size_t i = 0; i < b.size(); ++i) {
    if (u_map.find(b[i]) == u_map.end()) return false;
  }
  return true;
}

bool longestSubarrayCheck(std::vector<int> a, std::vector<int> b,
                          std::vector<int> c) {
  // first let's get the longuest subarray of a,
  std::vector<int> longuest_subarray = get_longuest_subarray(a);

  // Let's check if all of the elements of b belong to c
  // For a O(1) search time, it's better to create a hash_map and search all
  // elmments.
  std::unordered_map<int, bool> u_map;
  map_b(c, u_map);

  return (b_belongs_c(b, u_map) && longuest_subarray == b);
}

int main() {
  vector<int> a{1, 1, 5, 1, 1, 2};
  vector<int> b{1, 2};
  vector<int> c{2, 1};
  bool result = longestSubarrayCheck(a, b, c);
  return 0;
}