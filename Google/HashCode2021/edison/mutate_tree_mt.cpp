#include <bits/stdc++.h>

#include "checker.h"
#include "cpp_thread_pool.h"
#include "utils.h"
using namespace std;

const bool debug = 0;
const int print_every_iteration = 16 - 1;
const int thread_pool_size = 100;
const int child_count = 10;

void init_args(int argc, char **argv) {}

bool is_better_score(const ScoreType &a, const ScoreType &b) { return a > b; }

vector<string> road_name;

void init_data(const InputData &data) {
	road_name.resize(data.S);
	for (auto [name, id] : data.ID) {
		road_name[id] = name;
	}
}

pair<ScoreType, SolutionType> next_solve(const InputData &data,
                                         const SolutionType &prev_solution,
                                         int argc, char **argv) {
	SolutionType solution = prev_solution;

	int rand_type = rand() % 3;

	if (rand_type == 0) { // permute
		int p = rand() % solution.T.size();
		for (int i = 1; i < (int)solution.T[p].size(); ++i) {
			int j = rand() % (i + 1);
			swap(solution.T[p][i], solution.T[p][j]);
			swap(solution.name[p][i], solution.name[p][j]);
		}
	} else if (rand_type == 1) { // re-weight
		vector<int> path_weight(data.S, 0);
		for (auto &r : data.route) {
			for (int i : r) {
				path_weight[i]++;
			}
		}

		vector<vector<int>> come_to(data.I);
		vector<int> come_to_weight(data.I, 0);
		for (int i = 0; i < data.S; ++i) {
			if (path_weight[i] == 0) continue;

			come_to[data.E[i]].push_back(i);
			come_to_weight[data.E[i]] += path_weight[i];
		}

		int idx = rand() % solution.ID.size();
		int i = solution.ID[idx];

		int g = 0;
		for (int j : come_to[i]) {
			g = __gcd(g, path_weight[j]);
		}

		int mx = 0;
		for (int j : come_to[i]) {
			path_weight[j] /= g;
			mx = max(mx, path_weight[j]);
		}

		if (mx == 0) {
			solution.ID.erase(solution.ID.begin() + idx);
			solution.T.erase(solution.T.begin() + idx);
			solution.name.erase(solution.name.begin() + idx);
			--solution.A;
		} else {
			solution.T[idx].clear();
			solution.name[idx].clear();

			int fac = rand() % mx + 1;
			for (int j : come_to[i]) {
				path_weight[j] = floor((double)path_weight[j] / fac);
				if (path_weight[j] == 0) continue;
				solution.T[idx].push_back(path_weight[j]);
				solution.name[idx].push_back(road_name[j]);
			}

			if (solution.T[idx].empty()) {
				solution.name.erase(solution.name.begin() + idx);
				solution.T.erase(solution.T.begin() + idx);
				solution.name.erase(solution.name.begin() + idx);
				--solution.A;
			}
		}
	} else if (rand_type == 2) { // kill a in-road
		int p = rand() % solution.T.size();
		if (solution.T[p].size() > 1u) {
			solution.T[p].pop_back();
			solution.name[p].pop_back();
		}
	}

	FixSolution(data, solution);
	ScoreType score = Evaluate(data, solution);

	return make_pair(score, solution);
}

void record_solution(const ScoreType score, const SolutionType &solution,
		int argc, char **argv) {
	string filename = "solutions/" + string(argv[1] + 3) + "_" + to_string(score);
	cerr << "record solution to filename " << filename << endl;
	ofstream out(filename);
	out << solution << "\n";
	out.close();
}

int main(int argc, char **argv) {
	srand(time(0) * clock() * clock());

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	init_args(argc, argv);

	InputData data = ReadInput(argv[1]);
	SolutionType solution = ReadSolution(argv[2]);
	ScoreType score = Evaluate(data, solution);

	int iteration = 0;

	vector<vector<pair<ScoreType, SolutionType>>> solutions;
	solutions.emplace_back();
	solutions[0].emplace_back(score, solution);

	init_data(data);

	threadpool pool(thread_pool_size);
	while (true) {
		++iteration;

		int last_generation = solutions.size() - 1u;
		int first_generation = max(0, last_generation - 5);

		vector<vector<future<pair<ScoreType, SolutionType>>>> promises(
				last_generation - first_generation + 1);
		for (int gen = first_generation; gen <= last_generation; ++gen) {
			for (int i = 0; i < (int)solutions[gen].size(); ++i) {
				for (int j = 0; j < child_count; ++j) {
					promises[gen - first_generation].push_back(
							pool.commit(next_solve, data, solutions[gen][i].second, argc, argv));
				}
			}
		}

		solutions.emplace_back();
		for (int gen = first_generation; gen <= last_generation; ++gen) {
			for (auto &p : promises[gen - first_generation]) {
				auto [new_score, new_solution] = p.get();
				solutions[gen + 1].emplace_back(new_score, new_solution);
			}
		}

		for (int gen = first_generation; gen <= last_generation + 1; ++gen) {
			sort(solutions[gen].begin(), solutions[gen].end(),
					[&](const auto &a, const auto &b) -> bool {
					return is_better_score(a.first, b.first);
					});

			while (solutions[gen].size() > 10u) solutions[gen].pop_back();
			while (gen > 0 && solutions[gen].size() &&
					!is_better_score(solutions[gen].back().first, solutions[gen - 1][0].first))
				solutions[gen].pop_back();
		}

		while (solutions.back().empty()) solutions.pop_back();

		record_solution(solutions.back()[0].first, solutions.back()[0].second, argc,
				argv);

		if ((iteration & print_every_iteration) == 0) {
			cerr << "iterated " << iteration << " times. Best score: " << solutions.back()[0].first
				<< " at generation " << solutions.size() << endl;
		}
	}
}
