/*
##############################################
#          Coding Interview Questions
#      Created/Modified on: June 16, 2020
#           Author: Munir Jojo-Verge
##############################################
 */

/*

You're given a Node class that has a name and an
array of optional children nodes. When put together, nodes form
an acyclic tree-like structure.


Implement the depthFirstSearch method on the
Node class, which takes in an empty array, traverses the tree
using the Depth-first Search approach (specifically navigating the tree from
left to right), stores all of the nodes' names in the input array, and returns
it.


If you're unfamiliar with Depth-first Search, we recommend watching the
Conceptual Overview section of this question's video explanation before
starting to code.

Sample Input
graph = A
     /  |  \
    B   C   D
   / \     / \
  E   F   G   H
     / \   \
    I   J   K

Sample Output
["A", "B", "E", "F", "I", "J", "C", "D", "G", "K", "H"]

*/

#include <string>
#include <vector>

using namespace std;

// Do not edit the class below except
// for the depthFirstSearch method.
// Feel free to add new properties
// and methods to the class.
class Node {
 public:
  string name;
  vector<Node*> children;

  Node(string str) { name = str; }

  vector<string> depthFirstSearch(vector<string>* array) {
    // Since we can assume that there are NO cycles then we don't need to keep
    // track of visited nodes since we will not re-visit them ever.
    array->push_back(this->name);
    for (auto child : children) {
      child->depthFirstSearch(array);
    }
    return *array;
  }

  Node* addChild(string name) {
    Node* child = new Node(name);
    children.push_back(child);
    return this;
  }
};
