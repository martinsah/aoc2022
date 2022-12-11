#include "../aocmartin.hpp"

int main()
{
	using namespace std;
	set_path();

	// part 1
	{
		auto lines = vreadlines("day2.txt");
		int score = 0;
		for (auto l : lines) {
			auto you = l[2];
			auto them = l[0];
			const int win = 6;
			if ((you == 'X') && (them == 'A')) // rock & rock = tie
				score += 1 + 3;
			if ((you == 'X') && (them == 'B')) // rock & paper = lose
				score += 1 + 0;
			if ((you == 'X') && (them == 'C')) // rock & scissors = win
				score += 1 + 6;
			if ((you == 'Y') && (them == 'A')) // paper & rock = win
				score += 2 + 6;
			if ((you == 'Y') && (them == 'B')) // paper & paper = tie
				score += 2 + 3;
			if ((you == 'Y') && (them == 'C')) // paper & scissors = lose
				score += 2 + 0;
			if ((you == 'Z') && (them == 'A')) // scissors & rock = lose
				score += 3 + 0;
			if ((you == 'Z') && (them == 'B')) // scissors & paper = win
				score += 3 + 6;
			if ((you == 'Z') && (them == 'C')) // scissors & scissors = tie
				score += 3 + 3;

		}
		cout << score << "\n";
	}

	// part 2
	{
		auto lines = vreadlines("day2.txt");
		int score = 0;
		for (auto l : lines) {
			auto you = l[2];
			auto them = l[0];
			const int win = 6;
			if ((you == 'X') && (them == 'A')) // lose & rock = scissors
				score += 3;
			if ((you == 'X') && (them == 'B')) // lose & paper = rock
				score += 1;
			if ((you == 'X') && (them == 'C')) // lose & scissors = paper
				score += 2;
			if ((you == 'Y') && (them == 'A')) // tie & rock = rock
				score += 3 + 1;
			if ((you == 'Y') && (them == 'B')) // tie & paper = paper
				score += 3 + 2;
			if ((you == 'Y') && (them == 'C')) // tie & scissors = scissors
				score += 3 + 3;
			if ((you == 'Z') && (them == 'A')) // win & rock = paper
				score += 6 + 2;
			if ((you == 'Z') && (them == 'B')) // win & paper = scissors
				score += 6 + 3;
			if ((you == 'Z') && (them == 'C')) // win & scissors = rock
				score += 6 + 1;

		}
		cout << score << "\n";
	}


	return 0;
}