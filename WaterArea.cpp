/*
##############################################
#          Coding Interview Questions
#      Created/Modified on: July 23, 2019
#           Author: Munir Jojo-Verge
##############################################
 */

/*
You are given an array of integers. 
Each non-zero integer represents the height of a 2D pillar of width 1. 
Imagine water being poured over all of the pillars and return the surface area of the water trapped between the pillars viewed from the front (2D).
Note that spilled water should be ignored. 
             ___ 
             | |_______________
      _______| |7           | |
      | |  3 | |6     ___   | |
      | |  2 | |5     | |   | |
______|_|__1_|_|4__ __|_|___|_|___________________________________
   0   3   0   5  0  0  2 0  4

   The answer for the above example would be:
   3 levels where the first 0 is + 
   4x2 + 2x1 + 4x1
 */

#include  <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int waterArea(vector<int> heights) {
    // Write your code here.
    size_t n_pilars = heights.size();
    if (n_pilars == 0) return 0;

    //First let's calculate MaxLeft array = to the highest pilar to the RIGHT of every index
    vector<int> MaxLeft(n_pilars,0);
    MaxLeft[0] = heights[0];
    for (size_t i = 1; i< n_pilars; i++){
        MaxLeft[i] = max(MaxLeft[i-1], heights[i]);
    }

    // Let's calculate MaxRight array = to the highest pilar to the RIGHT of every index
    vector<int> MaxRight(n_pilars,0);
    MaxRight[n_pilars-1] = heights[n_pilars-1];
    for (int i = n_pilars-2; i >= 0; i--){
        MaxRight[i] = max(MaxRight[i+1], heights[i]);
    }

    // Let's create the WaterLevel array = to the amount of water that can be held in each index
    int WaterLevelSum = 0;
    int tmp_waterLevel;
    for (size_t i = 0; i< n_pilars; i++){
        tmp_waterLevel = min(MaxLeft[i], MaxRight[i]);
        if (tmp_waterLevel > heights[i])
            WaterLevelSum += tmp_waterLevel - heights[i];		
    }

    return WaterLevelSum;
		
}


int main() {

  vector<int> vector1;
  vector<int> vector2 {0, 0, 0, 0, 0};
  vector<int> vector3 {0, 1, 0, 0, 0};
  vector<int> vector4 {0, 1, 1, 0, 0};
  vector<int> vector5 {0, 1, 2, 1, 1};
  vector<int> vector6 {0, 1, 0, 1, 0};
  vector<int> vector7 {0, 1, 0, 1, 0, 2, 0, 3};
  vector<int> vector8 {0, 8, 0, 0, 5, 0, 0, 10, 0, 0, 1, 1, 0, 3};
  vector<int> vector9 {0, 8, 0, 0, 10, 0, 0, 10, 0, 0, 1, 1, 0, 3};
  vector<int> vector10 {0, 100, 0, 0, 10, 1, 1, 10, 1, 0, 1, 1, 0, 100};
  vector<int> vector11 {0, 100, 0, 0, 10, 1, 1, 10, 1, 0, 1, 1, 0, 0};

  
  cout << "Test Case 1";
  cout << (waterArea(vector1) == 0 ? "PASS": "FAIL") << endl;

  cout << "Test Case 2";
  cout << (waterArea(vector2) == 0 ? "PASS": "FAIL") << endl;
  
  cout << "Test Case 3";
  cout << (waterArea(vector3) == 0 ? "PASS": "FAIL") << endl;


  cout << "Test Case 4";
  cout << (waterArea(vector4) == 0 ? "PASS": "FAIL") << endl;


  cout << "Test Case 5";
  cout << (waterArea(vector5) == 0 ? "PASS": "FAIL") << endl;


  cout << "Test Case 6";
  cout << (waterArea(vector6) == 1 ? "PASS": "FAIL") << endl;


  cout << "Test Case 7";
  cout << (waterArea(vector7) == 4 ? "PASS": "FAIL") << endl;
  

  cout << "Test Case 8";
  cout << (waterArea(vector8) == 48 ? "PASS": "FAIL") << endl;
  
  cout << "Test Case 9";
  cout << (waterArea(vector9) == 49 ? "PASS": "FAIL") << endl;
  

  cout << "Test Case 10";
  cout << (waterArea(vector10) == 1075 ? "PASS": "FAIL") << endl;
  

  cout << "Test Case 11";
  cout << (waterArea(vector11) == 39 ? "PASS": "FAIL") << endl;
  
}
