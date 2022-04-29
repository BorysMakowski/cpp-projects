/*
program to code a message using Shannon–Fano algorithm
input: string containing characters a-b
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>

struct symbolCount {
	char symbol;
	int count;
	std::string codeword = "";
};
bool symbolSorter(symbolCount& left, symbolCount& right)
{
	return left.count > right.count;
}

struct minimumDifference {
	int difference = 0;
	int position = 0;
};


std::string input;
symbolCount symbolCounts[26] = { 0 };
std::vector <symbolCount> symbolCountsVector;
std::vector <std::string> output;





int divide(std::vector<symbolCount> vect, int left, int right) {
	int count = right - left;
	int sumleft = 0;
	int sumright = 0;
	int* difference = new int[right];
	minimumDifference minDiff;
	minDiff.difference = INT_MAX;

	for (int j = left; j < right; j++)
	{
		sumleft = 0;
		sumright = 0;
		for (int i = left; i < j; i++)
			sumleft += vect[i].count;

		for (int i = j; i < right; i++)
			sumright += vect[i].count;

		difference[j] = abs(sumleft - sumright);
		if (difference[j] < minDiff.difference)
		{
			minDiff.difference = difference[j];
			minDiff.position = j;
		}
	}
	delete[] difference;
	return minDiff.position;
}

void assignCodeWord(std::vector<symbolCount>& vect, int in) {
	std::vector <int> positions;
	int begin = 0;
	int end = vect.size();
	int position = 0;
	while (end - begin != 1)
	{
		position = divide(vect, begin, end);
		if (in < position)
		{
			end = position;
			vect.at(in).codeword.append("0");
		}
		else
		{
			begin = position;
			vect.at(in).codeword.append("1");
		}
	}
}




int main()
{
	std::cout << "kodowanie Shanona-Fano" << std::endl;
	std::cout << "podaj ciag znakow:" << std::endl;
	std::cin >> input;

	for (int i = 0; i < 26; i++)
		symbolCounts[i].symbol = (char)i + 'a';

	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] >= 'a' && input[i] <= 'z')
		{
			symbolCounts[(int)input[i] - 'a'].count++;
		}
		else
		{
			std::cout << "Unexpected input! I will now cease to work. Have a nice day." << std::endl;
			return 1;
		}
	}

	std::sort(symbolCounts, symbolCounts + 26, &symbolSorter);

	for (int i = 0; i < 26; i++)
	{
		if (symbolCounts[i].count)
			symbolCountsVector.push_back(symbolCounts[i]);
	}

	std::cout << "symbol | wystapienia | kod" << std::endl;
	for (int i = 0; i < symbolCountsVector.size(); i++)
	{
		assignCodeWord(symbolCountsVector, i);
		std::cout << " " << symbolCountsVector[i].symbol << "         " << symbolCountsVector[i].count << "           " << symbolCountsVector[i].codeword << std::endl;
	}




	for (int i = 0; i < input.length(); i++)
	{
		for (int j = 0; j < symbolCountsVector.size(); j++)
		{
			if (symbolCountsVector.at(j).symbol == input[i])
				output.push_back(symbolCountsVector.at(j).codeword);
		}
	}

	std::cout << "output: " << std::endl;
	for (std::string i : output)
		std::cout << i;
	std::cout << std::endl;
}

//ddddddddddbbbbbbbbeeeeeeeeaaaaaaaffffccc