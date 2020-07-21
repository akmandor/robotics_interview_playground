/*
##############################################
#          Coding Interview Questions
#      Created/Modified on: July 5, 2020
#           Author: Munir Jojo-Verge
##############################################
 */

/*
John has collected various rocks. Each rock has various minerals embeded in it.
Each type of mineral is designated by a lowercase letter in the range . There
may be multiple occurrences of a mineral in a rock. A mineral is called a
gemstone if it occurs at least once in each of the rocks in John's collection.
Given a list of minerals embedded in each of John's rocks, display the number of
types of gemstones he has in his collection. For example, the array of mineral
composition strings . The minerals and appear in each composite, so there are
gemstones.

Function Description Complete the gemstones function in the editor
below. It should return an integer representing the number of gemstones found in
the list of rocks. gemstones has the following parameter(s): arr: an array of
strings

Input Format The first line consists of an integer , the size of . Each
of the next lines contains a string where each letter represents an occurence of
a mineral in the current rock. Constraints | arr[i] | Each composition consists
of only lower-case Latin letters ('a'-'z'). Output Format Print the number of
types of gemstones in John's collection. If there are none, print .

Sample Input
3
abcdde
baccd
eeabg

Sample Output
2

Explanation
Only and are gemstones because they are the only types that occur in every rock.
*/
#include <bits/stdc++.h>

using namespace std;

// Complete the gemstones function below.
int gemstones(vector<string> arr) {
  size_t arr_len{arr.size()};
  if (arr_len == 0)
    return 0;
  else if (arr_len == 1)
    return arr[0].length();

  // At this point we know that to be a "Gem" it must be in all samples,
  // therefore we can pick any one (for ex the first sample), and go through all
  // the minerals  and add them to the map.

  std::unordered_map<char, int> u;
  string str{arr[0]};
  for (size_t i = 0; i < str.length(); ++i) {
    auto search = u.find(str[i]);
    if (search == u.end()) {
      u.emplace(std::make_pair(str[i], 0));
    }
  }

  for (size_t i = 1; i < arr_len - 1; ++i) {
    str = arr[i];
    for (size_t j = 0; j < str.length(); ++j) {
      auto search = u.find(str[j]);
      if (search != u.end() && search->second == i - 1) {
        search->second = i;
      }
    }
  }

  str = arr[arr_len - 1];
  int result{0};
  for (size_t i = 0; i < str.length(); ++i) {
    auto search = u.find(str[i]);
    if (search != u.end() && search->second == arr_len - 2) {
      search->second = i;
      ++result;
    }
  }
  return result;
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  vector<string> arr(n);

  for (int i = 0; i < n; i++) {
    string arr_item;
    getline(cin, arr_item);

    arr[i] = arr_item;
  }

  int result = gemstones(arr);

  fout << result << "\n";

  fout.close();

  return 0;
}
