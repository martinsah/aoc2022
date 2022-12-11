#include "../aocmartin.hpp"
#include <iostream>

int main()
{
	using namespace std;
	set_path();

	using et = pair<int, int>;
	auto etlt = [](et l, et r) {return true; };

	auto data = { 1,2,3 };
	struct {
		bool operator() (const int l, const int r) const { return l > r; }
	} customLess;
	std::priority_queue minq3(data.begin(), data.end(), customLess);

	struct {
		bool operator() (et l, et r) const { return(l.second < r.second); }
	} celf;
	
	std::priority_queue<et, vector<et>, decltype(celf)> eq;


	auto lines = vreadlines("day1.txt");

	int maxsum = 0, maxelf = 0;
	int sum = 0, elf = 1;
	for (auto n : lines) {

		auto v = str2int(n);
		if (n == "") {
			if (sum > maxsum) {
				maxsum = sum;
				maxelf = elf;
			}
			eq.push({ elf,sum });
			elf++;
			sum = 0;

		}
		else {
			sum += v;
		}

	}
	auto s = eq.top().second;
	eq.pop();
	s += eq.top().second;
	eq.pop();
	s += eq.top().second;

}

