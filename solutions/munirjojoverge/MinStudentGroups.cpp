/*
##############################################
#          Coding Interview Questions
#      Created/Modified on: July 23, 2019
#           Author: Munir Jojo-Verge
##############################################
 */

/*
You've invited a lot of children to a celebration party, and you want to
entertain them and also teach them something in the process. You are going to
hire a few teachers and divide the children into groups and assign a teacher to
each of the groups this teacher will work with this group through the whole
party. But you know that for a teacher to work with a group of children
efficiently children of that group should be of relatively the same age. More
specifically age of any two children in the same group should differ by at most
one year. Also, you want to minimize the number of groups. Because you want to
hire fewer teachers, and spend the money on presents and other kinds of
entertainment for the children. So, you need to divide children into the minimum
possible number of groups such that the age of any two children in any group
differs by at most one year.
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<size_t> min_groups(vector<u_short>& ages, size_t num_kids) {
  vector<size_t> groups;
  sort(ages.begin(), ages.end());
  size_t idx = 0;
  while (idx < num_kids) {
    size_t i = idx;
    size_t kid_count_per_group = 0;
    while (i < num_kids & ages[i] <= ages[idx] + 1.0) {
      kid_count_per_group++;
      i++;
    }
    groups.push_back(kid_count_per_group);
    idx = i;
  }
  return groups;
}

int main() {
  size_t num_kids;
  cout << "Enter the num of kids: ";
  cin >> num_kids;

  vector<u_short> ages(num_kids, 0);
  u_int16_t age;
  cout << "Enter the ages of each kid:" << endl;
  for (size_t i = 0; i < num_kids; i++) {
    cout << "Age for kid " << i + 1 << ": " << endl;
    cin >> ages[i];
  }

  vector<size_t> groups = min_groups(ages, num_kids);
  cout << "Min number of groups is: " << endl;
  for (size_t g = 0; g < groups.size(); g++) {
    cout << "Group: " << g + 1 << ": " << groups[g] << " kids" << endl;
  }
  return 0;
}
