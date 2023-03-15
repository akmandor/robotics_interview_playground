/*
##############################################
#          Coding Interview Questions
#      Created/Modified on: June 11, 2020
#           Author: Munir Jojo-Verge
##############################################
*/

/*

  Write a BST class for a Binary Search Tree. The class should
  support:


- Inserting values with the insert method.

- Removing values with the remove method; this method should
only remove the first instance of a given value.

- Searching for values with the contains method.

Note that you can't remove values from a single-node tree. In other words,
calling the remove method on a single-node tree should simply not
do anything.


Each BST node has an integer value, a
left child node, and a right child node. A node is
said to be a valid BST node if and only if it satisfies the BST
property: its value is strictly greater than the values of every
node to its left; its value is less than or equal to the values
of every node to its right; and its children nodes are either valid
BST nodes themselves or None / null.

Sample Usage
Assume the following BST has already been created:
         10
       /     \
      5      15
    /   \   /   \
   2     5 13   22
 /           \
1            14

All operations below are performed sequentially.
insert(12):   10
            /     \
           5      15
         /   \   /   \
        2     5 13   22
      /        /  \
     1        12  14

remove(10):   12
            /     \
           5      15
         /   \   /   \
        2     5 13   22
      /           \
     1            14

contains(15): true

*/

#include <cstddef>
#include <iostream>

class BST {
 public:
  int value;
  BST* left;
  BST* right;

  BST(int val);
  BST& insert(int val);
  BST& remove(int val, BST* parent = nullptr);
  bool contains(int val);

 private:
  int get_smallest();
};

BST::BST(int val) {
  value = val;
  left = nullptr;
  right = nullptr;
};

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
};

BST& BST::remove(int val, BST* parent) {
  if (val < value) {
    if (left != nullptr) {
      left->remove(val, this);
    }
  } else if (val > value) {
    if (right != nullptr) {
      right->remove(val, this);
    }
  } else {  // We found it
    // Now what we need to do is to find the smallest value on the RIGHT branch
    // (the bigger numbers) to make sure that we can put it here and still
    // satisfy the rule that all the LEFT branch should be smaller
    if (left != nullptr && right != nullptr) {
      value = right->get_smallest();
      right->remove(value, this);
    } else if (parent == nullptr) {  // This is the root
      if (left != nullptr) {
        value = left->value;
        right = left->right;
        left = left->left;
      } else if (right != nullptr) {
        value = right->value;
        right = right->right;
        left = right->left;
      } else {  // This is a single-node tree. DO nothing
      }
    } else if (parent->left == this) {
      parent->left = (left != nullptr) ? left : right;
    } else if (parent->right == this) {
      parent->right = (left != nullptr) ? left : right;
    }
  }
  return *this;
}

int BST::get_smallest() {
  if (left == nullptr)
    return value;
  else
    return left->get_smallest();
}

bool BST::contains(int val) {
  if (val < value) {
    if (left != nullptr) {
      return left->contains(val);
    } else {
      return false;
    }
  } else if (val > value) {
    if (right != nullptr) {
      return right->contains(val);
    } else {
      return false;
    }
  } else  // found it
  {
    return true;
  }
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
}