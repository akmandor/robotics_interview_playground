/*
##############################################
#          Coding Interview Questions
#      Created/Modified on: June 26, 2019
#           Author: Munir Jojo-Verge
##############################################
 */

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int kadanesAlgorithm(vector<int> array) {
  // Write your code here.
	vector<int> MaxSum(array.size());
	MaxSum[0] = array[0];
	int Biggest_sum = MaxSum[0];
	for (size_t i = 1; i<array.size(); i++){
		MaxSum[i] = max(MaxSum[i-1] + array[i], array[i]);
		Biggest_sum = max(MaxSum[i], Biggest_sum);
		//cout << "MaxSum[" << i << "] = " << MaxSum[i] << endl;
	}
	//return *max_element(MaxSum.begin(), MaxSum.end());
	return Biggest_sum;
}


int main() {

  cout << "Test Case 1: {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}" << endl;
  cout << (kadanesAlgorithm({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) == 55 ? "PASS": "FAIL") << endl;
  

  cout << "Test Case 2" << endl;
  cout << (kadanesAlgorithm({-1, -2, -3, -4, -5, -6, -7, -8, -9, -10}) == -1 ? "PASS": "FAIL") << endl;
  

  cout << "Test Case 3" << endl;
  cout << (kadanesAlgorithm({-10, -2, -9, -4, -8, -6, -7, -1, -3, -5}) == -1 ? "PASS": "FAIL") << endl;
  

  cout << "Test Case 4" << endl;
  cout << (kadanesAlgorithm({1, 2, 3, 4, 5, 6, -20, 7, 8, 9, 10}) == 35 ? "PASS": "FAIL") << endl;
  

  cout << "Test Case 5" << endl;
  cout << (kadanesAlgorithm({1, 2, 3, 4, 5, 6, -22, 7, 8, 9, 10}) == 34 ? "PASS": "FAIL") << endl;  

  cout << "Test Case 6" << endl;
  cout << (kadanesAlgorithm({1, 2, -4, 3, 5, -9, 8, 1, 2}) == 11 ? "PASS": "FAIL") << endl;
  

  cout << "Test Case 7" << endl;
  cout << (kadanesAlgorithm({3, 4, -6, 7, 8}) == 16 ? "PASS": "FAIL") << endl;
  

  cout << "Test Case 8" << endl;
  cout << (kadanesAlgorithm({3, 5, -9, 1, 3, -2, 3, 4, 7, 2, -9, 6, 3, 1, -5, 4}) == 19 ? "PASS": "FAIL") << endl;
  

  cout << "Test Case 9" << endl;
  cout << (kadanesAlgorithm({8, 5, -9, 1, 3, -2, 3, 4, 7, 2, -9, 6, 3, 1, -5, 4}) == 23 ? "PASS": "FAIL") << endl;
  

  cout << "Test Case 10" << endl;
  cout << (kadanesAlgorithm({8, 5, -9, 1, 3, -2, 3, 4, 7, 2, -9, 6, 3, 1, -5, 6}) == 24 ? "PASS": "FAIL") << endl;
  

  cout << "Test Case 11" << endl;
  cout << (kadanesAlgorithm({8, 5, -9, 1, 3, -2, 3, 4, 7, 2, -18, 6, 3, 1, -5, 6}) == 22 ? "PASS": "FAIL") << endl;
  

  cout << "Test Case 12" << endl;
  cout << (kadanesAlgorithm({8, 5, -9, 1, 3, -2, 3, 4, 7, 2, -18, 6, 3, 1, -5, 6, 20, -23, 15, 1, -3, 4}) == 35 ? "PASS": "FAIL") << endl;
  
  cout << "Test Case 13" << endl;
  cout << (kadanesAlgorithm({100, 8, 5, -9, 1, 3, -2, 3, 4, 7, 2, -18, 6, 3, 1, -5, 6, 20, -23, 15, 1, -3, 4}) == 135 ? "PASS": "FAIL") << endl;
    
}
