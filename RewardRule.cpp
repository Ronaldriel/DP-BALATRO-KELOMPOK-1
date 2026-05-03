#include <iostream>
#include "RewardRule.h"
int RewardRule::earnMoney(bool win, int score)
{
	int resultreward = score/2;
	std::cout << "Calculating reward...\n";
	if (win)
	{ 
		
		return resultreward;

	}
	return 0;
}