// LAST UPDATE: 2024.06.08
//
// AUTHOR: Neset Unver Akmandor (NUA)
//
// E-MAIL: akmandor.n@northeastern.edu
//
// DESCRIPTION: Data Structures
//
// REFERENCES:
// [1] https://www.geeksforgeeks.org/introduction-to-linked-list-data-structure-and-algorithm-tutorial/

#include <string.h>

#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/// ARRAY

/// LINKED LIST
// Singly linked list node
class NodeSL {
public:
    int data;
    NodeSL* next;
};


/* Node of a doubly linked list */
class NodeDL {
public:
    int data;
    NodeDL* next; // Pointer to next node in DLL
    NodeDL* prev; // Pointer to previous node in DLL
};


template <class T>
void print(T arr[], int size)
{
  for (int i=0; i<size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << "" << endl;
}

template <class T>
void print(int r, int c, T arr[][2])
{
  for (int i=0; i<r; i++)
  {
    for (int j=0; j<c; j++)
    {
      if (j == c-1)
        cout << arr[i][j] << endl;
      else
        cout << arr[i][j] << " ";
    }
  }
}

int main() {

  cout << "[data_structures] START" << endl;

  /// ARRAY
  cout << "[data_structures] STACK" << endl;

  int arr1[8] = {1,2,3,4,5,6,7,8};
  string arr2[2][2] = {"ali", "veli", "deli", "kelly"};
  string** arr3 = arr2;

  print(arr1, 8);
  print(2, 2, arr2);
  //print(2, 2, arr3);

  cout << "-------------" << endl;

  /// STACK
  cout << "[data_structures] STACK" << endl;
  stack<int> st1;
  st1.push(5);
  st1.push(6);
  st1.push(9);
  st1.push(1);
  stack<int> st2 = st1;

  cout << "BEFORE st1 size: " << st1.size() << endl;
  cout << "BEFORE st2 size: " << st2.size() << endl;
  
  int c = 0;
  while (!st1.empty())
  {
    int tmp = st1.top();
    cout << c << ": " << tmp << endl;
    st2.push(tmp);
    st1.pop();
    c++;
  }

  cout << "AFTER st1 size: " << st1.size() << endl;
  cout << "AFTER st2 size: " << st2.size() << endl;

  cout << "-------------" << endl;
  
  /// QUEUE


  
  return 0;
}