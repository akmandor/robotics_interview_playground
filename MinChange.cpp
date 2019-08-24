/*
Munir Jojo - Verge
04 / 11 / 2018
Coursera
00 - Algorithms and Data Structures
	01 - Algorithmic Toolbox
		week5_dynamic_programming1
			1_money_change_again
*/

// Only for Visual Studio implementation
//#include "stdafx.h"

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int get_min_coins_change(const int money, const vector<int>& coins) {
  //write your code here
	int NumCoins = 0;	
	vector<int> min_coins(money+1);
	min_coins[0] = 0;

	for (size_t m = 1; m <= money; m++)
	{		
		min_coins[m] = INT32_MAX;
		size_t c = 0;
		while (c < coins.size() && m >= coins[c]){		
			NumCoins = min_coins[(m - coins[c])] + 1;
			if (NumCoins < min_coins[m])
				min_coins[m] = NumCoins;		
		c++;
		}
	}
	return min_coins[money];
}

int main() {
  int money;
  cout << "Enter the money you want ot change: ";
  std::cin >> money;

  vector<int> coins = { 1, 3, 4 }; // Assume sorted otherwise un-comment below.
  //std::sort(coins.begin(), coins.end());

  // lets assume that you are not allowed to have 0 cents coins

  std::cout << " Your change will use " << get_min_coins_change(money, coins) << " coins" << endl;
}
