/*
##############################################
#          Coding Interview Questions
#      Created/Modified on: August 23, 2019
#           Author: Munir Jojo-Verge
##############################################
 */

/*
Problem 3
This problem was asked by Google.

Given the root to a binary tree, implement serialize(root), which serializes the tree into a string, and deserialize(s), which deserializes the string back into the tree.

*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Node {
    public:
        char data;
        Node* left;
        Node* right;

        Node(int data){
            this->data = data;
            left = nullptr;
            right = nullptr;
        };        
};

string serialize(Node* root){
    string result = "";
    if (root == nullptr){
        return "@";
    }      
    result += root->data;
    result += serialize(root->left);
    result += serialize(root->right);

    return result;    
}

Node* deserialize(string str){    
    
    if (str == "" || str[0] == '@') {
        return nullptr;
    }      
    Node* newNode = new Node(str[0]);
    str = str.erase(0,1);
    newNode->left = deserialize(str);
    str = str.erase(0,1);
    newNode->right = deserialize(str);

    return newNode;    
}

int main(){    
    string expected_result;
    char expected_node;

    Node node_a('a');
    Node node_b('b');
    Node node_c('c');
    Node node_d('d');
    Node node_e('e');
    Node node_f('f');
    Node node_g('g');
    node_a.left = &node_b;
    node_a.right = &node_c;
    node_b.left = &node_d;
    node_b.right = &node_e;
    node_c.left = &node_f;
    node_c.right = &node_g;

    cout << "Test Case 1 - ";
    expected_result = "abd@@e@@cf@@g@@";
    cout << (serialize(&node_a) == expected_result ? "PASS": "FAIL") << endl;  

    cout << "Test Case 2 - ";
    expected_node = node_a.data;
    cout << (deserialize(expected_result)->data == expected_node ? "PASS": "FAIL") << endl;  
}


