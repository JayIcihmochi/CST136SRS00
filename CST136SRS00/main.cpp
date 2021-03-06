#include "stdafx.h"
#include <iostream>
#include <random>
#include <string>
#include <sstream>
#include <cassert>
#include "LetsMakeADeal.h"


int main(int argc, char* argv[])
{
	auto doors{ 3 }, reveal{ 1 }, instance{ 0 }, plan{ 2 };

	if (argc == 1)
	{
		std::cout << "This Executable was expecting at least one parameter.\nThey are, in order: [Instances] [Stay(0) or Swap(1) plan] [Doors total] [Doors to reveal]\n"
			<< "Please note that your choice to stay or swap is a number, and should be entered as the number associated with your choice";
		return 0;
	}
	else if (argc == 2 )
	{
		std::stringstream String1{ argv[1] };
		String1 >> instance;
	}
	else if (argc == 3)
	{
		std::stringstream String1{ argv[1] };
		String1 >> instance;
		std::stringstream String2{ argv[2] };
		String2 >> plan;
	}
	else if (argc == 4)
	{
		std::stringstream String{ argv[1] };
		String >> instance;
		std::stringstream String2{ argv[2] };
		String2 >> plan;
		std::stringstream String3{ argv[3] };
		String3 >> doors;
	}
	else if (argc == 5)
	{
		std::stringstream String{ argv[1] };
		String >> instance;
		std::stringstream String2{ argv[2] };
		String2 >> plan;
		std::stringstream String3{ argv[3] };
		String3 >> doors;
		std::stringstream String4{ argv[4] };
		String4 >> reveal;
	}

	while (doors < 2)
	{
		std::cout << "\nMust have at least two doors: ";
		std::cin >> doors;
	}
	while (reveal < 0)
	{
		std::cout << "\nDoors revealed must be a positive integer (can include 0): ";
		std::cin >> reveal;
	}
	while (instance < 1)
	{
		std::cout << "\nInsantance must be a positive integer (positive none zero number): ";
		std::cin >> instance;
	}
	while (reveal + 2 > doors)
	{
		std::cout << "\nGame paramiters not met. Can't reveal more doors than there are doors, or revealing all but the door selected.\n"
			<< "please lower the doors revealed: ";
		std::cin >> reveal;
	}

	auto strat{ false };

	while (plan != 0 && plan != 1)
	{
		std::cout << "\nYou didn't enter a valid number for your strategy. Please enter 0 for Stay, or 1 for Swap: ";
		std::cin >> plan;
	}
	if (plan == 1)
	{
		strat = true ;
	}
	else
	{
		strat = false ;
	}

	std::vector<LetsMakeADeal> gameShow;
	gameShow.reserve(instance);
	
	for (auto i = 0; i != instance; i++)
	{
		const LetsMakeADeal game(doors, reveal, strat);
		gameShow.push_back(game);
	}

	float wincar{ 0.0 };
	float wingoat{ 0.0 };

	for (auto& game : gameShow)
	{
		const auto didIWin{ game.play() };
		if (didIWin)
		{
			wincar++;
		}
		else
		{
			wingoat++;
		}
	}

	assert((wincar + wingoat) / instance < 1.01 && (wincar + wingoat) / instance > .99);

	std::cout << wincar / instance;

    return 0;
}
