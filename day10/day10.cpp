#include "../aocmartin.hpp"

int main()
{
	using namespace std;
	set_path();

	auto lines = vreadlines("day10.txt");
	int acc = 1;
	int pc = 0;

	vector<int> cyc{ 20,60,100,140,180,220 };
	int score = 0;
	string oline{};

	auto sc = [&]() {
		
		for (auto c : cyc) {
			if ((pc+1) == c) {
				//cout << "\npc: " << pc << " acc " << acc << " ss " << acc * pc;
				score += acc * (pc+1);
			}
		}
		// sprite position
		auto xpos = pc % 40;
		if (xpos == acc - 1 || xpos == acc || xpos == acc + 1) {
			oline = oline + "#";
		}
		else {
			oline = oline + ".";
		}
		if (oline.length() == 40) {
			cout << "\n" << oline << " pc " << pc;
			oline = "";
		}
		pc++;
	};

	for (auto l : lines) {
		
		auto w = str_split_to_words(l);
		if (w[0] == "noop") {
			sc();
			continue;
		}
		sc();
		sc();
		acc += str2int(w[1]);
	}
	cout << "\nscore1 " << score;
	return 0;
}
