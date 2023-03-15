/*
##############################################
#          Coding Interview Questions
#      Created/Modified on: June 26, 2019
#           Author: Munir Jojo-Verge
##############################################
 */

/*

Write a function that takes in a Binary Search Tree (BST) and a target integer
value and returns the closest value to that target value contained in the BST.

You can assume that there will only be one closest value

Each BST node has an integer, a
left child node, and a right child node. A node is
said to be a valid BST node if and only if it satisfies the BST
property: its value is strictly greater than the values of every
node to its left; its value is less than or equal to the values
of every node to its right; and its children nodes are either valid
BST nodes themselves or None / nullptr.

Sample Input
tree =   10
       /     \
      5      15
    /   \   /   \
   2     5 13   22
 /           \
1            14

target = 12

Sample Output
13

*/

#include <cfloat>
#include <cmath>
#include <iostream>
#include <limits>

using namespace std;

class BST {
 public:
  int value;
  BST* left;
  BST* right;

  BST(int val);
  BST& insert(int val);
};

BST::BST(int val) {
  value = val;
  left = nullptr;
  right = nullptr;
}

BST& BST::insert(int val) {
  if (val < value) {
    if (left == nullptr) {
      BST* newBST = new BST(val);
      left = newBST;
    } else {
      left->insert(val);
    }
  } else {
    if (right == nullptr) {
      BST* newBST = new BST(val);
      right = newBST;
    } else {
      right->insert(val);
    }
  }
  return *this;
}

// ******************************

int findClosestValueInBstHelper(BST* tree, int target, double closest) {
  // Write your code here.
  if (abs(tree->value - target) < abs(closest - target)) {
    closest = tree->value;
  }

  if (target < tree->value && tree->left != nullptr) {
    return findClosestValueInBstHelper(tree->left, target, closest);
  } else if (target >= tree->value && tree->right != nullptr) {
    return findClosestValueInBstHelper(tree->right, target, closest);
  } else {
    return int(closest);
  }
}

int findClosestValueInBst_recursive(BST* tree, long int target) {
  // Write your code here.
  return findClosestValueInBstHelper(tree, target, DBL_MAX);
}

int findClosestValueInBst(BST* tree, long int target) {
  // Write your code here.
  BST* curr_node = tree;
  int closest = curr_node->value;
  while (curr_node != nullptr) {
    if (abs(curr_node->value - target) < abs(closest - target))
      closest = curr_node->value;

    if (target < curr_node->value) {
      curr_node = curr_node->left;
    } else if (target >= curr_node->value) {
      curr_node = curr_node->right;
    } else
      break;
  }
  return closest;
}

int main() {
  BST test(100);
  test.insert(5)
      .insert(15)
      .insert(5)
      .insert(2)
      .insert(1)
      .insert(22)
      .insert(1)
      .insert(1)
      .insert(3)
      .insert(1)
      .insert(1)
      .insert(502)
      .insert(55000)
      .insert(204)
      .insert(205)
      .insert(207)
      .insert(206)
      .insert(208)
      .insert(203)
      .insert(-51)
      .insert(-403)
      .insert(1001)
      .insert(57)
      .insert(60)
      .insert(4500);

  cout << "Test Case 1: ";
  cout << ((findClosestValueInBst(&test, 100) == 100) ? "PASS" : "FAIL")
       << endl;

  cout << "Test Case 2: ";
  cout << ((findClosestValueInBst(&test, 208) == 208) ? "PASS" : "FAIL")
       << endl;

  cout << "Test Case 3: ";
  cout << ((findClosestValueInBst(&test, 4500) == 4500) ? "PASS" : "FAIL")
       << endl;

  cout << "Test Case 4: ";
  cout << ((findClosestValueInBst(&test, 4501) == 4500) ? "PASS" : "FAIL")
       << endl;

  cout << "Test Case 5: ";
  cout << ((findClosestValueInBst(&test, -70) == -51) ? "PASS" : "FAIL")
       << endl;

  cout << "Test Case 6: ";
  cout << ((findClosestValueInBst(&test, 2000) == 1001) ? "PASS" : "FAIL")
       << endl;

  cout << "Test Case 7: ";
  cout << ((findClosestValueInBst(&test, 6) == 5) ? "PASS" : "FAIL") << endl;

  cout << "Test Case 8: ";
  cout << ((findClosestValueInBst(&test, 30000) == 55000) ? "PASS" : "FAIL")
       << endl;

  cout << "Test Case 9: ";
  cout << ((findClosestValueInBst(&test, -1) == 1) ? "PASS" : "FAIL") << endl;

  cout << "Test Case 10: ";
  cout << ((findClosestValueInBst(&test, 29751) == 55000) ? "PASS" : "FAIL")
       << endl;

  cout << "Test Case 11: ";
  cout << ((findClosestValueInBst(&test, 29749) == 4500) ? "PASS" : "FAIL")
       << endl;
}