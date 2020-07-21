
/*
##############################################
#          Coding Interview Questions
#      Created/Modified on: Jun 18, 2020
#           Author: Munir Jojo-Verge
##############################################
*/

// reading a text file
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string line;
  ifstream myfile("code.txt");
  if (myfile.is_open()) {
    while (myfile.good()) {
      getline(myfile, line);
      cout << line << endl;
    }
    myfile.close();
  }

  else
    cout << "Unable to open file";

  return 0;
}