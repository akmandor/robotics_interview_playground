
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
#include <vector>

using namespace std;

string trimline(string text) {
  vector<char> new_text;
  bool opened = false;
  for (size_t i = 0; i < text.size(); i++) {
    if (text[i] == '<') {
      opened = true;
    } else if (text[i] == '>') {
      opened = false;
    } else if (!opened) {
      new_text.push_back(text[i]);
    }
  }
  return string(new_text.begin(), new_text.end());
}

int main() {
  string line;
  ifstream HTML_code_file("code.txt");
  ofstream clean_file;
  clean_file.open("clean_code.txt");
  if (HTML_code_file.is_open()) {
    while (HTML_code_file.good()) {
      getline(HTML_code_file, line);
      clean_file << trimline(line);
    }
    HTML_code_file.close();
    clean_file.close();
  }

  else
    cout << "Unable to open file";

  return 0;
}