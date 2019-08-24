/*
##############################################
#          Coding Interview Questions
#      Created/Modified on: June 26, 2019
#           Author: Munir Jojo-Verge
##############################################
 */


/*
Write a function that takes in a non-empty array of distinct integers and an integer representing a target sum. 
If any two numbers in the input array sum up to the target sum, the function should return them in an array, in sorted order.
If no two numbers sum up to the target sum, the function should return an empty array. 
Assume that there will be at most one pair of numbers summing up to the target sum.

Sample input: [3, 5, -4, 8, 11, 1, -1, 6], 10
Sample output: [-1, 11]
 */

#include <iostream>
#include <vector>

std::vector<int> twoNumberSum(std::vector<int> myList, int targetSum){
    std::vector<int> output;
    for (size_t i = 0; i < myList.size(); i++)
    {
        int firstNum = myList[i];
        for (size_t j = i+1; j < myList.size(); j++)
        {
            int secondNum = myList[j];
            if (firstNum + secondNum == targetSum){
                return (firstNum < secondNum ? std::vector<int> {firstNum, secondNum} : std::vector<int> {secondNum,firstNum});
            }
        }        
    }
    
    return std::vector<int> {};
}

int main() {
    size_t n;
    std::cout << "How many integers will you input? ";
    std::cin >> n;

    std::vector<int> myList(n);

    for (size_t i = 0; i<n; i++){
        std::cout << "Enter int " << i << ": ";
        std::cin >> myList[i];
    }
    
    int targetSum;
    std::cout << "What's your target sum? ";
    std::cin >> targetSum;

    std::vector<int> result = twoNumberSum(myList, targetSum);    
    if (result.size() > 0){
        std::cout << " The 2 integers that add up to your targeet sum are: " << result[0] << " and " << result[1] << std::endl;
    }
    else
        std::cout << " The are NO integers that add up to your targeet sum are";

}