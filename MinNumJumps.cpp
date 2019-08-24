/*
##############################################
#          Coding Interview Questions
#      Created/Modified on: June 26, 2019
#           Author: Munir Jojo-Verge
##############################################
 */


/*

 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minNumberOfJumps(vector<int> array) {
  // Write your code here.
	size_t n = array.size();
	vector<int> jumps(n,INT_MAX);
	jumps[0] = 0;
	for (size_t i = 0; i < n; i++){
		for (size_t j = i+1; j < n && j <= i+array[i]; j++){
			if (jumps[i]+1 < jumps[j]){
				jumps[j] = jumps[i]+1;
			}
	  }
  }
	return jumps[n-1];
}



int main() {

  // Test cases
  vector<int> vector1 {1};
  vector<int> vector2 {1, 1};
  vector<int> vector3 {3, 1};
  vector<int> vector4 {1, 1, 1};
  vector<int> vector5 {2, 1, 1};
  vector<int> vector6 {2, 1, 2, 3, 1};
  vector<int> vector7 {2, 1, 2, 3, 1, 1, 1};
  vector<int> vector8 {2, 1, 2, 2, 1, 1, 1};
  vector<int> vector9 {3, 4, 2, 1, 2, 3, 7, 1, 1, 1, 3};
  vector<int> vector10 {3, 4, 2, 1, 2, 3, 7, 1, 1, 1, 3, 2, 6, 2, 1, 1, 1, 1};
  vector<int> vector11 {3, 4, 2, 1, 2, 3, 7, 1, 1, 1, 3, 2, 3, 2, 1, 1, 1, 1};
  vector<int> vector12 {3, 10, 2, 1, 2, 3, 7, 1, 1, 1, 3, 2, 3, 2, 1, 1, 1, 1};
  vector<int> vector13 {3, 12, 2, 1, 2, 3, 7, 1, 1, 1, 3, 2, 3, 2, 1, 1, 1, 1};
  vector<int> vector14 {3, 12, 2, 1, 2, 3, 15, 1, 1, 1, 3, 2, 3, 2, 1, 1, 1, 1};

  
  cout << "Test Case 1" << endl;       
  cout <<(minNumberOfJumps(vector1) == 0? "PASS": "FAIL") << endl;
  

  cout << "Test Case 2" << endl;
  cout <<(minNumberOfJumps(vector2) == 1? "PASS": "FAIL") << endl;
  

  cout << "Test Case 3" << endl;
  cout <<(minNumberOfJumps(vector3) == 1? "PASS": "FAIL") << endl;
  

  cout << "Test Case 4" << endl;
  cout <<(minNumberOfJumps(vector4) == 2? "PASS": "FAIL") << endl;
  

  cout << "Test Case 5" << endl;
  cout <<(minNumberOfJumps(vector5) == 1? "PASS": "FAIL") << endl;
  

  cout << "Test Case 6" << endl;
  cout <<(minNumberOfJumps(vector6) == 2? "PASS": "FAIL") << endl;
  
  cout << "Test Case 7" << endl;
  cout <<(minNumberOfJumps(vector7) == 3? "PASS": "FAIL") << endl;
  

  cout << "Test Case 8" << endl;
  cout <<(minNumberOfJumps(vector8) == 4? "PASS": "FAIL") << endl;
  

  cout << "Test Case 9" << endl;
  cout <<(minNumberOfJumps(vector9) == 4? "PASS": "FAIL") << endl;
  

  cout << "Test Case 10" << endl;
  cout <<(minNumberOfJumps(vector10) == 5? "PASS": "FAIL") << endl;
  

  cout << "Test Case 11" << endl;
  cout <<(minNumberOfJumps(vector11) == 7? "PASS": "FAIL") << endl;
  

  cout << "Test Case 12" << endl;
  cout <<(minNumberOfJumps(vector12) == 6? "PASS": "FAIL") << endl;
  

  cout << "Test Case 13" << endl;
  cout <<(minNumberOfJumps(vector13) == 5? "PASS": "FAIL") << endl;
  

  cout << "Test Case 14" << endl;
  cout <<(minNumberOfJumps(vector14) == 3? "PASS": "FAIL") << endl;
    
}

int main2() {
    size_t n;
    std::cout << "How many integers will you input? ";
    std::cin >> n;

    std::vector<int> myList(n);

    for (size_t i = 0; i<n; i++){
        std::cout << "Enter int " << i << ": ";
        std::cin >> myList[i];
    }
    
    std::cout << "The min number of jumps is: " << minNumberOfJumps(myList) << std::endl;
    
}