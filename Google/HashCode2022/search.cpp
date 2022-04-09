#include <bits/stdc++.h>
#include "../grader.h"
using namespace std;

int common(const Project &p) {
	int x = 0, c = 0;
	for (auto &i : p.skills) {
		if (i.second != x && c == 0) x = i.second;
		if (i.second == x) ++c;
		else --c;
	}
	return x;
}

class MyInputData : public InputData {
	public:
		MyInputData(InputData d) : InputData(d) {
			// ocon.resize(d.contributors.size());
			// iota(ocon.begin(), ocon.end(), 0);
			// oproj.resize(d.projects.size());
			// iota(oproj.begin(), oproj.end(), 0);

			// cout << "sz " << ocon.size() << ' ' << oproj.size() << endl;
		}

		// vector<int> ocon, oproj;

		// Contributor& GetContributor(int id) { return contributors[ocon[id]]; }
		// Project& GetProject(int id) { return projects[oproj[id]]; }

		void Init() {
			// random_shuffle(contributors.begin(), contributors.end());
			sort(projects.begin(), projects.end(), [](const auto &a, const auto &b) { return a.B < b.B; });
			// sort(projects.begin(), projects.end(), [](const auto &a, const auto &b) { return common(a) < common(b); });
			// random_shuffle(ocon.begin(), ocon.end());
			// sort(oproj.begin(), oproj.end(), [&](int i, int j) {
			// 		return projects[i].S < projects[j].S;
			// 		});
		}

		void Swap() {
			for (int i = 0; i < 3; ++i) {
				int r = rand() % 3;
				if (r == 0) {
					int i = rand() % projects.size();
					int j = rand() % projects.size();
					swap(projects[i], projects[j]);
				} else if (r == 1) {
					int i = rand() % contributors.size();
					int j = rand() % contributors.size();
					swap(contributors[i], contributors[j]);
				}
			}
		}

		OutputData GenOutput() {
			OutputData d;

			set<int> did_proj;
			while (true) {
				bool new_proj = false;
				for (auto &p : projects) {
					if (did_proj.count(p.index)) continue;
					vector<int> need(p.skills.size());
					iota(need.begin(), need.end(), 0);
					random_shuffle(need.begin(), need.end());

					set<int> con_used;
					vector<int> selected(p.skills.size(), -1);
					int sel_cnt = 0;
					map<int, int> skill_max;


					for (int _ = 0; _ < 3; ++_) {
						for (int ni = 0; ni < need.size(); ++ni) {
							int skill_i = need[ni];
							auto &skill = p.skills[skill_i];
							if (selected[skill_i] != -1) continue;

							for (Contributor &c : contributors) {
								if (con_used.count(c.index)) continue;

								auto it = c.skills.find(skill.first);
								if (it != c.skills.end()) {
									bool ok = 0;
									if (it->second >= skill.second) {
										ok = 1;
									} else if (it->second == skill.second - 1) {
										auto it = skill_max.find(skill.first);
										if (it != skill_max.end() && it->second >= skill.second) {
											ok = 1;
										}
									}

									if (ok) {
										con_used.insert(c.index);
										selected[skill_i] = c.index;
										++sel_cnt;
										for (auto [i, j] : c.skills) {
											skill_max[i] = max(skill_max[i], j);
										}
										break;
									}
								}
							}
						}
					}

					// cout << "sel cnt " << sel_cnt << endl;
					// cout << "selected" << " ";
					// for (int i : selected) cout << i << ' ';
					// cout << endl;
					if (sel_cnt == (int)need.size()) {
						did_proj.insert(p.index);
						d.projects.emplace_back(p.index, selected);
						new_proj = true;

						for (int i = 0; i < p.skills.size(); ++i) {
							int sk = p.skills[i].first;
							Contributor &c = contributors[selected[i]];
							if (c.skills[sk] <= p.skills[i].second) {
								c.skills[sk]++;
							}
						}
					}

					// if (new_proj) break;
				}

				if (!new_proj) break;
			}

			return d;
		}
};

string input_filename;
InputData orig_input;

int64_t GetScore(const auto &out_data) {
	return Grade(orig_input, out_data);
}

string GetFileName(const auto &in_data, const auto &out_data, const auto &score) {
	return input_filename + "." + to_string(score) + ".out";
}

auto Output(const auto &in_data, const auto &out_data, const auto &score) {
	string filename = GetFileName(in_data, out_data, score);
	cout << "filename = " << filename << endl;
	ofstream ofs(filename);
	ofs << out_data;
}

auto GenOutput(auto in_data) {
	return in_data.GenOutput();
}

auto InitSolve(auto &in_data) {
	in_data.Init();
	return GenOutput(in_data);
}

auto NextGen(auto &in_data, auto &out_data) {
	in_data.Swap();
	return GenOutput(in_data);
}

auto ReadInput(string filename) {
	ifstream ifs(filename);
	ifs >> orig_input;
	return MyInputData(orig_input);
}

int main(int argc, char **argv) {
	if (argc < 2) {
		cerr << argv[0] << " <input_file>" << endl;
		exit(1);
	}

	srand(time(0) * clock());

	input_filename = argv[1];
	input_filename = input_filename.substr(9);

	auto in_data = ReadInput(argv[1]);
	auto out_data = InitSolve(in_data);
	auto score = GetScore(out_data);
	Output(in_data, out_data, score);
	
	while (true) {
		auto new_in_data = in_data;
		new_in_data.Swap();
		auto new_out_data = GenOutput(new_in_data);
		auto new_score = GetScore(new_out_data);

		if (new_score > score) {
			score = new_score;
			in_data = new_in_data;
			out_data = new_out_data;
			Output(in_data, out_data, score);
			cout << "new sc " << new_score << endl;
		}
	}
}
