/*
##############################################
#          Coding Interview Questions
#      Created/Modified on: August 22, 2019
#           Author: Munir Jojo-Verge
##############################################
 */


/*
Problem 2
This problem was asked by Uber.

Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.

For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].

Follow-up: what if you can't use division?
*/


#include <vector>
#include <iostream>

using namespace std;

vector<int> product_all_except_i(vector<int> arr) {
    int arr_len = arr.size();
    if (arr_len == 0 || arr_len == 1)
        return arr;

    vector<int> result(arr_len);    
    vector<int> left_prod(arr_len);    
    vector<int> right_prod(arr_len);

    left_prod[0] = arr[0];
    right_prod[arr_len-1] = arr[arr_len - 1];

    for (size_t i = 1; i < arr_len-1; i++)
    {
        left_prod[i] = left_prod[i-1] * arr[i];
        right_prod[arr_len-1-i] = right_prod[arr_len-i] * arr[arr_len-1-i];
    }
    left_prod[arr_len-1] = left_prod[arr_len-2] * arr[arr_len-1];
    right_prod[0] = right_prod[1] * arr[0];

    result[0] = right_prod[1];
    result[arr_len-1] = left_prod[arr_len-2];
    for (size_t i = 1; i < arr_len-1; i++)
    {
        result[i] = left_prod[i-1] * right_prod[i+1];
    }
    return result;
}

int main(){
  vector<int> expected_result;
  cout << "Test Case 1: {} - 17 ";
  expected_result = {};
  cout << (product_all_except_i({}) == expected_result ? "PASS": "FAIL") << endl;  

  cout << "Test Case 2: {1, 2, 3, 4, 5}  ";
  expected_result = {120, 60, 40, 30, 24};
  cout << (product_all_except_i({1, 2, 3, 4, 5}) == expected_result ? "PASS": "FAIL") << endl;  
}