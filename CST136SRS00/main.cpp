#include "stdafx.h"
#include <iostream>
#include <cctype>
#include "LetsMakeADeal.h"

int main()
{
	int doors, reveal, instance, strat{ 0 };

	std::cout << "How many doors are there?";
	std::cin >> doors;
	std::cout << "How many doors are being revealed?";
	std::cin >> reveal;
	std::cout << "How many instances are we running?";
	std::cin >> instance;
	std::cout << "What's your stratigy? Stay(0) or Swap(1)?";
	std::cin >> strat;

	while (doors < 2)
	{
		std::cout << "Must have at least two doors:";
		std::cin >> doors;
	}
	while (reveal < 0)
	{
		std::cout << "doors revealed must be a positive integer (can include 0):";
		std::cin >> reveal;
	}
	while (instance < 1)
	{
		std::cout << "insant must be a positive integer (positive none zero number):";
		std::cin >> instance;
	}
	while (strat != 1 && strat != 0)
	{
		std::cout << "You didn't enter a number for your stratigy. Please enter 0 for stay, or 1 for Swap:";
		std::cin >> strat;
	}
	while (reveal + 2 > doors)
	{
		std::cout << "Game paramiters not met. Can't reveal more doors than there are doors, or revealing all but the door selected.\n"
			<< "please lower the doors revealed";
		std::cin >> reveal;
	}


	if (doors != 0 && reveal != 0)
	{
		LetsMakeADeal game{ doors, reveal, instance };
	}
	else if (doors != 0)
	{
		LetsMakeADeal game{ doors, 1, instance};
	}
	else if (reveal != 0)
	{
		LetsMakeADeal game{ 3, reveal, instance };
	}
	else
	{
		LetsMakeADeal game{ 3, 1, instance };
	}


    return 0;
}