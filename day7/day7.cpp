#include "../aocmartin.hpp"

int main()
{
	using namespace std;
	set_path();
	struct node {
		shared_ptr<node> parent;
		unordered_map<string, shared_ptr<node>> branches;
		unordered_map<string, size_t> files;

		// debug
		string name;

		// change dir
		shared_ptr<node> cd(string dir) {
			if (branches.contains(dir)) {
				return branches[dir];
			}
			else {
				if (dir == "..") {
					return parent;
				}
				auto newdir = make_shared<node>(node{});
				branches[dir] = newdir;
				newdir->name = dir;
				return newdir;
			}
		}

		// size of contained files and directories
		size_t size() {
			size_t ret=0;
			for (auto f : files) {
				ret += f.second;
			}
			for (auto b : branches) {
				ret += b.second->size();
			}
			return ret;
		}
	};

	vector<shared_ptr<node>> alldirs;

	auto root = node{};
	root.name = "root";

	auto root_ptr = make_shared<node>(root);
	root.parent = root_ptr;
	auto cwd = root_ptr;
	alldirs.push_back(root_ptr);

	auto print_path = [&](shared_ptr<node> p) {
		vector<string> path;
		while (p->parent != nullptr) {
			path.push_back(p->name);
			auto cd = p->cd("..");
			p = cd;
		}
		reverse(path.begin(), path.end());
		cout << "\n";
		for (auto s : path)
			cout << "/" << s;
	};

	auto cd = [&](string d) {
		auto cd = cwd->cd(d);
		if (d != "..") {
			cd->parent = cwd;
			alldirs.push_back(cd);
		}
		cwd = cd;
	};

	auto lines = vreadlines("day7.txt");
	
	for (auto line : lines) {
		
		auto word = str_split_to_words(line);

		if (word[0] == "$" && word[1] == "cd") {
			// change directory
			if (word[2] == "/")
				continue;
			cd(word[2]);
			//print_path(cwd);
			continue;
		}
		if (word[0] == "$" && word[1] == "ls") {
			// ok they're going to list files...
			continue;
		}

		if (word[0] == "dir") {
			// ignore directories in listing
			continue;
		}
		// should be a file in line now
		//cout << "\n" << line;
		cwd->files[word[1]] = str2int(word[0]);
		//cwd->size += str2int(word[0]);
	}

	size_t score1 = 0;
	
	auto root_size = root_ptr->size();
	size_t size_to_free = 30000000 - (70000000 - root_size);
	vector<size_t> candidates;

	for (auto d : alldirs) {
		auto dsize = d->size();
		cout << "\n" << d->name << ": " << dsize;
		if (dsize <= 100000)
			score1 += dsize;
		if (dsize >= size_to_free)
			candidates.push_back(dsize);
	}
	cout << "\nscore1: " << score1;
	
	sort(candidates.begin(), candidates.end());
	cout << "\nans2: " << candidates[0];
	
	/// part 2
	
	


	return 0;
}