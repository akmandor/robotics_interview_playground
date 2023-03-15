/*
##############################################
#          Coding Interview Questions
#      Created/Modified on: July 22, 2020
#           Author: Munir Jojo-Verge
##############################################
*/

/*
Write a function that takes in a string made up of brackets ((, [, {, ), ],
and }) and other optional characters. The function should return a boolean
representing whether the string is balanced with regards to brackets.

A string is said to be balanced if it has as many opening brackets of a
certain type as it has closing brackets of that type and if no bracket is
unmatched. Note that an opening bracket can't match a corresponding closing
bracket that comes before it, and similarly, a closing bracket can't match a
corresponding opening bracket that comes after it. Also, brackets can't
overlap each other as in
[(]).

Sample Input
string = "([])(){}(())()()"

Sample Output
true  // it's balanced

*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

bool balancedBrackets(string str) {
  // Write your code here.
  string open = "([{";
  string close = ")]}";

  unordered_map<char, char> matchingBrackets{
      {')', '('}, {']', '['}, {'}', '{'}};

  vector<char> stack;

  for (auto c : str) {
    if (open.find(c) != string::npos) {
      stack.push_back(c);
    } else if (close.find(c) != string::npos) {
      if (stack.size() == 0) return false;
      if (matchingBrackets[c] == stack[stack.size() - 1]) {
        stack.pop_back();
      } else
        return false;
    }
  }
  return stack.size() == 0;
}

int main() {
  string str;
  bool expected;

  cout << "Test Case 1: ";
  str = "([])(){}(())()()";
  expected = true;
  cout << (balancedBrackets(str) == expected ? "PASS" : "FAIL") << endl;

  cout << "Test Case 2: ";
  str = "()[]{}{";
  expected = false;
  cout << (balancedBrackets(str) == expected ? "PASS" : "FAIL") << endl;

  cout << "Test Case 3: ";
  str = "(((((({{{{{[[[[[([)])]]]]]}}}}}))))))";
  expected = false;
  cout << (balancedBrackets(str) == expected ? "PASS" : "FAIL") << endl;

  cout << "Test Case 4: ";
  str = "()()[{()})]";
  expected = false;
  cout << (balancedBrackets(str) == expected ? "PASS" : "FAIL") << endl;

  cout << "Test Case 5: ";
  str = "(()())((()()()))";
  expected = true;
  cout << (balancedBrackets(str) == expected ? "PASS" : "FAIL") << endl;

  cout << "Test Case 6: ";
  str = "{}()";
  expected = true;
  cout << (balancedBrackets(str) == expected ? "PASS" : "FAIL") << endl;

  cout << "Test Case 7: ";
  str = "()([])";
  expected = true;
  cout << (balancedBrackets(str) == expected ? "PASS" : "FAIL") << endl;

  cout << "Test Case 8: ";
  str = "((){{{{[]}}}}) ";
  expected = true;
  cout << (balancedBrackets(str) == expected ? "PASS" : "FAIL") << endl;

  cout << "Test Case 9: ";
  str = "((({})()))";
  expected = true;
  cout << (balancedBrackets(str) == expected ? "PASS" : "FAIL") << endl;

  cout << "Test Case 10: ";
  str = "(([]()()){})";
  expected = true;
  cout << (balancedBrackets(str) == expected ? "PASS" : "FAIL") << endl;

  cout << "Test Case 11: ";
  str =
      "(((((([[[[[[{{{{{{{{{{{{()}}}}}}}}}}}}]]]]]]))))))((([])({})[])[])[]([])"
      "{}(())";
  expected = true;
  cout << (balancedBrackets(str) == expected ? "PASS" : "FAIL") << endl;

  cout << "Test Case 12: ";
  str = "{[[[[({(}))]]]]}";
  expected = false;
  cout << (balancedBrackets(str) == expected ? "PASS" : "FAIL") << endl;

  cout << "Test Case 13: ";
  str = "[((([])([]){}){}){}([])[]((())";
  expected = false;
  cout << (balancedBrackets(str) == expected ? "PASS" : "FAIL") << endl;

  cout << "Test Case 14: ";
  str = ")[]}";
  expected = false;
  cout << (balancedBrackets(str) == expected ? "PASS" : "FAIL") << endl;

  cout << "Test Case 15: ";
  str = "(a)";
  expected = true;
  cout << (balancedBrackets(str) == expected ? "PASS" : "FAIL") << endl;
  cout << "Test Case 16: ";
  str = "(a(";
  expected = false;
  cout << (balancedBrackets(str) == expected ? "PASS" : "FAIL") << endl;
}