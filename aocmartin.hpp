//aocmartin.hpp
#include <vector>
#include <string>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <functional>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

void set_path(std::string path = "../data") {
	namespace fs = std::filesystem;
	fs::current_path(fs::path(path));
	std::cout << "Current path is " << fs::current_path() << '\n';

}

uint32_t str2int(std::string s) {
	if (s == "") {
		return 0;
	}
	return std::stoi(s);
}


// read each line into a vector
std::vector<std::string> vreadf(std::string fname) {
	std::ifstream f{ fname };
	std::vector<std::string> retvet{};
	while (f.good()) {
		std::string s{};
		f >> s;
		retvet.push_back(s);
	}
	return(retvet);
}

// also read each line into a vector
std::vector<std::string> vreadlines(std::string fname) {
	std::ifstream f{ fname };
	std::vector<std::string> retvet{};
	for (std::string line; getline(f, line); ) {
		retvet.push_back(line);
	}
	return retvet;
}

std::vector<std::int32_t> vstr2int32(std::vector<std::string> inp) {
	std::vector<std::int32_t> retval{};
	for (auto s : inp) {
		try {
			retval.push_back(std::stoi(s));
		}
		catch (std::exception e) {
			std::cout << "\nFailure converting: '" << s << "' to integer value fyi";
		}
	}
	return retval;

}
std::vector<std::string> str_split_to_words(std::string text, std::string delimiter = " ") {
	using namespace std;
	vector<string> words{};

	size_t pos = 0;
	while ((pos = text.find(delimiter)) != string::npos) {
		words.push_back(text.substr(0, pos));
		text.erase(0, pos + delimiter.length());
	}
	words.push_back(text);
	return words;
}

std::vector<std::string> vec_keep_bits(std::vector<std::string>& inp, int bit, char val) {
	std::vector<std::string> retval{};

	for (auto s : inp) {
		if (s[bit] == val)
			retval.push_back(s);
	}

	return retval;
}

void print_strvec_bin(std::string& inp) {
	int rval = 0;
	for (int x = inp.size() - 1; x > -1; x--) {
		rval |= (inp[11 - x] == '1') ? (1 << x) : 0;
	}
	std::cout << rval;
}
