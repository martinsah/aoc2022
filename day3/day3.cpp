#include "../aocmartin.hpp"

int main()
{
	using namespace std;
	set_path();

	auto lines = vreadlines("day3.txt");

	{
		unordered_map<char, int> sums;
		char com = 0;
		size_t score = 0;

		for (auto l : lines) {
			unordered_map<char, int> left;

			auto len = l.size();
			auto sl = l.substr(0, len / 2);

			for (auto c : sl)
				left[c] = 1;

			auto ctop = [](char c) {if (c > 96) return (c - 96); return (c - 64 + 26); };

			for (int x = len / 2; x < len; x++) {
				if (left.contains(l[x])) {
					cout << "\ndupe: " << l[x] << " += " << ctop(l[x]);
					score += ctop(l[x]);
					com = l[x];
					break;
				}
			}
		}
		cout << "\npart 1 score = " << score;
	}

	// part 2
	{
		unordered_map<char, int> sums;
		char com = 0;
		size_t score = 0;
		auto ctop = [](char c) {if (c > 96) return (c - 96); return (c - 64 + 26); };

		int mod = 0;
		string l1, l2, l3;
		int group = 1;
		for (auto l : lines) {
			switch (mod++) {
			case 0:
				l1 = l;
				continue;
			case 1:
				l2 = l;
				continue;
			case 2:
				l3 = l;
			}
			mod = 0;


			unordered_set<char> set1(l1.begin(), l1.end());
			unordered_set<char> set2(l2.begin(), l2.end());
			unordered_set<char> set3(l3.begin(), l3.end());

			for (auto c : set1) {
				if (set2.contains(c) && set3.contains(c)) {
					cout << "\n" << group++ << ": " << c << " += " << ctop(c);
					score += ctop(c);
				}
			}

		}
		cout << "\npart 2 score = " << score;
	}



	return 0;
}