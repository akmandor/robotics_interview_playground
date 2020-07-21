
/*
##############################################
#          Coding Interview Questions
#      Created/Modified on: Jun 18, 2020
#           Author: Munir Jojo-Verge
##############################################
*/

/*

Write a function that takes in a "special" array and returns its product sum.
A "special" array is a non-empty array that contains either integers or other
"special" arrays. The product sum of a "special" array is the sum of its
elements, where "special" arrays inside it are summed themselves and then
multiplied by their level of depth.


For example, the product sum of [x, y] is x + y; the
product sum of [x, [y, z]] is x + 2y + 2z.

Sample Input
array = [5, 2, [7, -1], 3, [6, [-13, 8], 4]]

Sample Output
12 // calculated as: 5 + 2 + 2 * (7 - 1) + 3 + 2 * (6 + 3 * (-13 + 8) + 4)

*/

#include <any>
#include <iostream>
#include <vector>

using namespace std;

int productSum(vector<std::any> array, int depth = 1) {
  // Write your code here.
  if (array.size() == 0) return 0;

  int sum = 0;
  for (int i = 0; i < array.size(); i++) {
    if (array[i].type() == typeid(vector<any>))
      sum += depth * (productSum(any_cast<vector<any>>(array[i]), depth + 1));
    else
      sum += depth * any_cast<int>(array[i]);
  }

  return sum;
}

int main() {
  vector<any> array;
  int expected;
  int result;

  cout << "Test Case 1: ";
  array = {5, 2, vector<any>{7, -1}, 3, vector<any>{6, vector<any>{-13, 8}, 4}};
  expected = 12;
  result = productSum(array);
  cout << (result == expected ? "PASS" : "FAIL") << endl;

  cout << "Test Case 2: ";
  array = {1, 2, 3, 4, 5};
  expected = 15;
  result = productSum(array);
  cout << (result == expected ? "PASS" : "FAIL") << endl;

  cout << "Test Case 3: ";
  array = {1, 2, vector<any>{3}, 4, 5};
  expected = 18;
  result = productSum(array);
  cout << (result == expected ? "PASS" : "FAIL") << endl;

  cout << "Test Case 4: ";
  array = {{1, 2}, 3, vector<any>{4, 5}};
  expected = 27;
  result = productSum(array);
  cout << (result == expected ? "PASS" : "FAIL") << endl;

  cout << "Test Case 5: ";
  array = {{{{{5}}}}};
  expected = 600;
  result = productSum(array);
  cout << (result == expected ? "PASS" : "FAIL") << endl;

  cout << "Test Case 6: ";
  array = {9,
           {2, -3, 4},
           1,
           {1, 1, vector<any>{1, 1, 1}},
           {{{{3, 4, 1}}}, 8},
           {1, 2, 3, 4, 5, vector<any>{6, 7}, -7},
           {1, vector<any>{2, 3, vector<any>{4, 5}},
            vector<any>{6, 0, vector<any>{7, 0, -8}}, -7},
           {1, -3, 2,
            vector<any>{1, -3, 2, vector<any>{1, -3, 2},
                        vector<any>{1, -3, 2, vector<any>{1, -3, 2}},
                        vector<any>{1, -3, 2}}},
           -3};
  expected = 1351;
  result = productSum(array);
  cout << (result == expected ? "PASS" : "FAIL") << endl;
}
