/*
##############################################
#          Coding Interview Questions
#      Created/Modified on: July 25, 2019
#           Author: Munir Jojo-Verge
##############################################
 */

/*
 Write a function that takes in an array of integers and returns an array of length 2 representing the largest
 range of numbers contained in that array. 
 The first number in the output array should be the first number in the range while the second number should be
 the last number in the range. 
 A range of numbers is defined as a set of numbers that come right after each other in the set of real integers.
 For instance, the output array [2, 6] represents the range {2, 3, 4, 5, 6}, which is a range of length 5.
 Note that numbers do not need to be ordered or adjacent in the array in order to form a range. 
 Assume that there will only be one largest range.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> largestRange(vector<int> array) {	
  // Write your code here.
	
	/* One easy way to solve this problem is to order the array
	   and to go through all the elements to find the largest range.
		 This solution, although easy to implement requires a time 
		 complexity of: ORDER = nlog(n) + find the largest range = n === nlog(n)
		 
		 We can do better by:
		 1) going throgh the array's items and checking to the left (Smaller numbers) of the value and
		 checking to the right (bigger values) of the value for consecutive integers that should be
		 on the array. If we find any (on the left or right) on the array, we can mark it as "used" (in a range)
		 and that way we can skip the items that have been already used since they belong to, inebitably,
		 the largest range so far. Do mark the elements as "used" we can use a Hastable that has constant
		 access time and, in this way, we make the time complexity:
		 Fill the hashtable = n + find the largest range = n === n
		 which is much better than the previous nlog(n)
		 
	*/
	 // The problem does NOT define the required output when the array is empty
	
	unordered_map<int, bool> u;
	vector<int> output(2);
	size_t cur_range_len = 0;
	size_t largest_range_len = 0;
	
	// Let's fill in the hastable / map
	for(size_t i = 0; i < array.size(); i++){
		u[array[i]] = false; // The false means NOT used as part of a range
	}
	
	for(size_t i = 0; i < array.size(); i++){
		if (u[array[i]] == true)
			continue;
		
		u[array[i]] = true;
		cur_range_len = 1;

		//Let's look at smaller integers (left)
		int left  = array[i]-1;		
		while (u.find(left) != u.end()){
			u[left] = true;						
			left--;			
			cur_range_len ++;
		}		
		
		//Let's look at bigger integers (right)
		int right = array[i]+1;
		while (u.find(right) != u.end()){
			u[right] = true;			
			right++;			
			cur_range_len ++;
		}
		if (cur_range_len > largest_range_len){
			largest_range_len = cur_range_len;
			output = {left+1, right-1};
		}
	}
	
	return output;
}

int main() {
  vector<vector<int>> testInput;
  vector<int> expected;
  vector<int> output;

  cout << "Test Case 1: ";
    expected = {1, 1};
    cout << (largestRange({1}) == expected ? "PASS": "FAIL") << endl;
 

  cout << "Test Case 2: ";
    expected = {1, 2};
    cout << (largestRange({1, 2}) == expected ? "PASS": "FAIL") << endl;
 

  cout << "Test Case 3: ";
    expected = {1, 4};
    cout << (largestRange({4, 2, 1, 3}) == expected ? "PASS": "FAIL") << endl;
 

  cout << "Test Case 4: ";
    expected = {1, 4};
    cout << (largestRange({4, 2, 1, 3, 6}) == expected ? "PASS": "FAIL") << endl;
 

  cout << "Test Case 5: ";
    expected = {6, 10};
    cout << (largestRange({8, 4, 2, 10, 2, 6, 7, 9, 2}) == expected ? "PASS": "FAIL") << endl;
 

  cout << "Test Case 6: ";
    expected = {0, 7};
    cout << (largestRange({1, 11, 3, 0, 15, 5, 2, 4, 10, 7, 12, 6}) == expected ? "PASS": "FAIL") << endl;
 

  cout << "Test Case 7: ";
    expected = {10, 19};
    cout << (largestRange({19, -1, 18, 17, 2, 10, 3, 12, 5, 16, 4, 11, 8, 7, 6, 15, 12, 12, 2, 1, 6, 13, 14}) == expected ? "PASS": "FAIL") << endl;
 

  cout << "Test Case 8: ";
    expected = {-1, 19};
    cout << (largestRange({0, 9, 19, -1, 18, 17, 2, 10, 3, 12, 5, 16, 4, 11, 8, 7, 6, 15, 12, 12, 2, 1, 6, 13, 14}) == expected ? "PASS": "FAIL") << endl;
 

  cout << "Test Case 9: ";
    expected = {-7, 7};
    cout << (largestRange({0, -5, 9, 19, -1, 18, 17, 2, -4, -3, 10, 3, 12, 5, 16, 4, 11, 7, -6, -7, 6, 15, 12, 12, 2, 1, 6, 13, 14, -2}) == expected ? "PASS": "FAIL") << endl;
 

  cout << "Test Case 10: ";
    expected = {-7, 7};
    cout << (largestRange({0, -5, 9, 19, -1, 18, 17, 2, -4, -3, 10, 3, 12, 5, 16, 4, 11, 7, -6, -7, 6, 15, 12, 12, 2, 1, 6, 13, 14, -2}) == expected ? "PASS": "FAIL") << endl;
 

  cout << "Test Case 11: ";
    expected = {-8, 19};
    cout << (largestRange({-7, -7, -7, -7, 8, -8, 0, 9, 19, -1, -3, 18, 17, 2, 10, 3, 12, 5, 16, 4, 11, -6, 8, 7, 6, 15, 12, 12, -5, 2, 1, 6, 13, 14, -4, -2}) == expected ? "PASS": "FAIL") << endl;
 
  cout << "TEST_END" << endl;
}
