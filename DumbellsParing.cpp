/*
##############################################
#          Coding Interview Questions
#      Created/Modified on: Jun 23, 2020
#           Author: Munir Jojo-Verge
##############################################
*/

/*

*/

#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);

/*
 * Complete the 'taskOfPairing' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts LONG_INTEGER_ARRAY freq as parameter.
 */

long taskOfPairing(vector<long> freq) {
  size_t num_elem = freq.size();
  long maxNumPairs{0};

  int rem = 0;
  for (size_t i = 0; i < num_elem; ++i) {
    int quotient1 = (int)(freq[i] % 2);
    int remainder1 = freq[i] % 2;

    int quotient2 = (int)((freq[i] + rem) % 2);
    int remainder2 = (freq[i] + rem) % 2;
    if (quotient1 > quotient2) {
      maxNumPairs += quotient1;
      rem = remainder1;
    } else {
      maxNumPairs += quotient2;
      rem = remainder2;
    }
  }
  return maxNumPairs;
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  string freq_count_temp;
  getline(cin, freq_count_temp);

  int freq_count = stoi(ltrim(rtrim(freq_count_temp)));

  vector<long> freq(freq_count);

  for (int i = 0; i < freq_count; i++) {
    string freq_item_temp;
    getline(cin, freq_item_temp);

    long freq_item = stol(ltrim(rtrim(freq_item_temp)));

    freq[i] = freq_item;
  }

  long result = taskOfPairing(freq);

  fout << result << "\n";

  fout.close();

  return 0;
}

string ltrim(const string& str) {
  string s(str);

  s.erase(s.begin(),
          find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

  return s;
}

string rtrim(const string& str) {
  string s(str);

  s.erase(
      find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
      s.end());

  return s;
}