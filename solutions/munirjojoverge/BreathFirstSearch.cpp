/*
##############################################
#          Coding Interview Questions
#      Created/Modified on: June 17, 2020
#           Author: Munir Jojo-Verge
##############################################
 */

/*
You're given a Node class that has a name and an
array of optional children nodes. When put together, nodes form
an acyclic tree-like structure.


Implement the breadthFirstSearch method on the
Node class, which takes in an empty array, traverses the tree
using the Breadth-first Search approach (specifically navigating the tree from
left to right), stores all of the nodes' names in the input array, and returns
it.


If you're unfamiliar with Breadth-first Search, we recommend watching the
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
["A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K"]

*/

#include <queue>
#include <string>
#include <vector>

using namespace std;

// Do not edit the class below except
// for the breadthFirstSearch method.
// Feel free to add new properties
// and methods to the class.
class Node {
 public:
  string name;
  vector<Node*> children;

  Node(string str) { name = str; }

  vector<string> breadthFirstSearch(vector<string>* array) {
    // Write your code here.
    queue<Node*> my_q;
    my_q.push(this);
    while (!my_q.empty()) {
      Node* curr_node = my_q.front();
      my_q.pop();
      array->push_back(curr_node->name);
      for (auto child : curr_node->children) {
        my_q.push(child);
      }
    }
    return *array;
  }

  Node* addChild(string name) {
    Node* child = new Node(name);
    children.push_back(child);
    return this;
  }
};
