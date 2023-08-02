/*
LAST UPDATE: 2023.08.01

AUTHOR: Neset Unver Akmandor (NUA)

E-MAIL: akmandor.n@northeastern.edu

DESCRIPTION: 
  - In this problem, you are climbing a staircase. 
  - It takes n steps to reach the top. Each time you can either climb 1 or 2 steps. 
  - The question is, in how many distinct ways can you climb to the top?
  - Note: Given n will be a positive integer.

  - Example 1:

  Input: 2
  Output: 2
  Explanation: There are two ways to climb to the top.
  1. 1 step + 1 step
  2. 2 steps

  - Example 2:

  Input: 3
  Output: 3
  Explanation: There are three ways to climb to the top.
  1. 1 step + 1 step + 1 step
  2. 1 step + 2 steps
  3. 2 steps + 1 step.

REFERENCES:
[1] https://medium.com/javarevisited/20-dynamic-programming-interview-questions-with-solutions-2a144b1a1e07
*/

#include <string.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int climbing_stairs(int n)
{
  int a;
  int b;
  int tmp;
  for (int i = 0; i < n; i++)
  {
    if (i == 0)
    {
      a = 0;
      b = 0;
    }
    else if (i == 1)
    {
      a = 0;
      b = 1;
    }
    else if (i == 2)
    {
      a = 1;
      b = 1;
    }
    else
    {
      tmp = b;
      b = a + b;
      a = tmp;
    }
  }
  
  return a + b;
}

int main() {
  
  int n = 5;
  cout << "# ways: " << climbing_stairs(n) << endl;

  return 0;
}