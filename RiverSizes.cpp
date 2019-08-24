
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int DFS(size_t i, size_t j, size_t len, vector<vector<int>> &matrix, vector<vector<bool>> &visited) {
	if (!visited[i][j]){
		visited[i][j] = true;        
		size_t num_rows = matrix.size();
		size_t num_cols = matrix[0].size();
        len++;

		// North
		if ((i+1 < num_rows) && (matrix[i+1][j] == 1)){			
			len = DFS(i+1, j, len, matrix, visited);		
		};

		//South
		if ((i > 0) && (matrix[i-1][j] == 1)){			
			len = DFS(i-1, j, len, matrix, visited);		
		};

		//West
		if ((j > 0) && (matrix[i][j-1] == 1)){			
			len = DFS(i, j-1, len, matrix, visited);		
		};

		//East
		if ((j+1 < num_cols) && (matrix[i][j+1] == 1)){			
			len = DFS(i, j+1, len, matrix, visited);		
		};
	}
	return len;
}
	
	
vector<int> riverSizes(vector<vector<int>> matrix) {
  // Write your code here.
	vector<int> riversLen;
	vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), false));	
	for (size_t i = 0; i < matrix.size(); i++){
		for (size_t j = 0; j < matrix[0].size(); j++){
			if (matrix[i][j] == 1 && !visited[i][j]){
				riversLen.push_back(DFS(i, j, 0, matrix, visited));
			}
		}
	}
	return riversLen;
}



int main() {
  vector<vector<int>> testInput;
  vector<int> expected;
  vector<int> output;

  cout <<"Test Case 1: ";
  testInput =  {{0}};
  expected  = {};
  output = riverSizes(testInput);
  sort(output.begin(), output.end());
  cout << (output == expected ? "PASS": "FAIL") << endl;


  cout <<"Test Case 2: ";
  testInput =  {{1}};
  expected  = {1};
  output = riverSizes(testInput);
  sort(output.begin(), output.end());
  cout << (output == expected ? "PASS": "FAIL") << endl;
  

  cout <<"Test Case 3: ";
    testInput =  {{1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 0}};
    expected  = {1, 2, 3};
    output = riverSizes(testInput);
    sort(output.begin(), output.end());
    cout << (output == expected ? "PASS": "FAIL") << endl;


  cout <<"Test Case 4: ";
    testInput =  {
      {1, 0, 0, 1},
      {1, 0, 1, 0},
      {0, 0, 1, 0},
      {1, 0, 1, 0},
    };
    expected  = {1, 1, 2, 3};
    output = riverSizes(testInput);
    sort(output.begin(), output.end());
    cout << (output == expected ? "PASS": "FAIL") << endl;


  cout <<"Test Case 5: ";
    testInput =  {
      {1, 0, 0, 1, 0},
      {1, 0, 1, 0, 0},
      {0, 0, 1, 0, 1},
      {1, 0, 1, 0, 1},
      {1, 0, 1, 1, 0},
    };
    expected  = {1, 2, 2, 2, 5};
    output = riverSizes(testInput);
    sort(output.begin(), output.end());
    cout << (output == expected ? "PASS": "FAIL") << endl;


  cout <<"Test Case 6: ";
    testInput =  {
      {1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0},
      {1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0},
      {0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1},
      {1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0},
      {1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1},
    };
    expected  = {1, 1, 2, 2, 5, 21};
    output = riverSizes(testInput);
    sort(output.begin(), output.end());
    cout << (output == expected ? "PASS": "FAIL") << endl;


  cout <<"Test Case 7: ";
    testInput =  {
      {1, 0, 0, 0, 0, 0, 1},
      {0, 1, 0, 0, 0, 1, 0},
      {0, 0, 1, 0, 1, 0, 0},
      {0, 0, 0, 1, 0, 0, 0},
      {0, 0, 1, 0, 1, 0, 0},
      {0, 1, 0, 0, 0, 1, 0},
      {1, 0, 0, 0, 0, 0, 1},
    };
    expected  = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    output = riverSizes(testInput);
    sort(output.begin(), output.end());
    cout << (output == expected ? "PASS": "FAIL") << endl;


  cout <<"Test Case 8: ";
    testInput =  {
      {1, 0, 0, 0, 0, 0, 1},
      {0, 1, 0, 0, 0, 1, 0},
      {0, 0, 1, 0, 1, 0, 0},
      {0, 0, 1, 1, 1, 0, 0},
      {0, 0, 1, 0, 1, 0, 0},
      {0, 1, 0, 0, 0, 1, 0},
      {1, 0, 0, 0, 0, 0, 1},
    };
    expected  = {1, 1, 1, 1, 1, 1, 1, 1, 7};
    output = riverSizes(testInput);
    sort(output.begin(), output.end());
    cout << (output == expected ? "PASS": "FAIL") << endl;


  cout <<"Test Case 9: ";
    testInput =  {
      {0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0},
    };
    expected  = {};
    output = riverSizes(testInput);
    sort(output.begin(), output.end());
    cout << (output == expected ? "PASS": "FAIL") << endl;


  cout <<"Test Case 10: ";
    testInput =  {
      {1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 1},
    };
    expected  = {49};
    output = riverSizes(testInput);
    sort(output.begin(), output.end());
    cout << (output == expected ? "PASS": "FAIL") << endl;


  cout <<"Test Case 11: ";
    testInput =  {
      {1, 1, 0, 0, 0, 0, 1, 1},
      {1, 0, 1, 1, 1, 1, 0, 1},
      {0, 1, 1, 0, 0, 0, 1, 1},
    };
    expected  = {3, 5, 6};
    output = riverSizes(testInput);
    sort(output.begin(), output.end());
    cout << (output == expected ? "PASS": "FAIL") << endl;


  cout <<"Test Case 12: ";
    testInput =  {
      {1, 1, 0},
      {1, 0, 1},
      {1, 1, 1},
      {1, 1, 0},
      {1, 0, 1},
      {0, 1, 0},
      {1, 0, 0},
      {1, 0, 0},
      {0, 0, 0},
      {1, 0, 0},
      {1, 0, 1},
      {1, 1, 1},
    };
    expected  = {1, 1, 2, 6, 10};
    output = riverSizes(testInput);
    sort(output.begin(), output.end());
    cout << (output == expected ? "PASS": "FAIL") << endl;

}
