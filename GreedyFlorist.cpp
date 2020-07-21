/*
##############################################
#          Coding Interview Questions
#      Created/Modified on: Jun 23, 2020
#           Author: Munir Jojo-Verge
##############################################
*/

/*
A group of friends want to buy a bouquet of flowers. The florist wants to
maximize his number of new customers and the money he makes. To do this, he
decides he'll multiply the price of each flower by the number of that customer's
previously purchased flowers plus . The first flower will be original price, ,
the next will be  and so on. Given the size of the group of friends, the number
of flowers they want to purchase and the original prices of the flowers,
determine the minimum cost to purchase all of the flowers.

For example, if there are  friends that want to buy  flowers that cost  each
will buy one of the flowers priced  at the original price. Having each purchased
flower, the first flower in the list, , will now cost . The total cost will be .

Function Description

Complete the getMinimumCost function in the editor below. It should return the
minimum cost to purchase all of the flowers.

getMinimumCost has the following parameter(s):

c: an array of integers representing the original price of each flower
k: an integer, the number of friends
Input Format

The first line contains two space-separated integers  and , the number of
flowers and the number of friends. The second line contains  space-separated
positive integers , the original price of each flower.

Constraints

Output Format

Print the minimum cost to buy all  flowers.

Sample Input 0

3 3
2 5 6
Sample Output 0

13
Explanation 0

There are  flowers with costs  and  people in the group. If each person buys one
flower, the total cost of prices paid is  dollars. Thus, we print  as our
answer.

Sample Input 1

3 2
2 5 6
Sample Output 1

15
Explanation 1

There are  flowers with costs  and  people in the group. We can minimize the
total purchase cost like so:

The first person purchases  flowers in order of decreasing price; this means
they buy the more expensive flower () first at price  dollars and the less
expensive flower () second at price  dollars. The second person buys the most
expensive flower at price  dollars. We then print the sum of these purchases,
which is , as our answer.

Sample Input 2

5 3
1 3 5 7 9
Sample Output 2

29
Explanation 2

The friends buy flowers for ,  and ,  and  for a cost of .

*/

#include <bits/stdc++.h>
#include <functional>

using namespace std;

vector<string> split_string(string);

// Complete the getMinimumCost function below.
int getMinimumCost(int k, vector<int> c) {
  int minCost{0};
  // We can not assume the cost of the flowers are going top be in order.
  // Therefore we need to order them O(n logn)
  std::sort(c.begin(), c.end(), std::greater<int>());

  int purchaseRound{0};
  for (size_t i = 0; i < c.size(); i += k) {
    for (size_t j = 0; j < k && i + j < c.size(); ++j) {
      minCost += (purchaseRound + 1) * c[i + j];
    }
    ++purchaseRound;
  }
  return minCost;
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  string nk_temp;
  getline(cin, nk_temp);

  vector<string> nk = split_string(nk_temp);

  int n = stoi(nk[0]);

  int k = stoi(nk[1]);

  string c_temp_temp;
  getline(cin, c_temp_temp);

  vector<string> c_temp = split_string(c_temp_temp);

  vector<int> c(n);

  for (int i = 0; i < n; i++) {
    int c_item = stoi(c_temp[i]);

    c[i] = c_item;
  }

  int minimumCost = getMinimumCost(k, c);

  fout << minimumCost << "\n";

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
