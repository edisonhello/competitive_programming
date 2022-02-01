#include <bits/stdc++.h>

#include "checker.h"
#include "cpp_thread_pool.h"
#include "utils.h"
using namespace std;

const bool debug = 0;
const int print_every_iteration = 16 - 1;
const int thread_pool_size = 20;
const int child_count = 10;

void init_args(int argc, char **argv) {}

bool is_better_score(const ScoreType &a, const ScoreType &b) { return a > b; }

vector<string> road_name;

pair<ScoreType, SolutionType> init_solve(const InputData &data, int argc,
                                         char **argv) {
	road_name.resize(data.S);
	for (auto [name, id] : data.ID) {
		road_name[id] = name;
	}

	vector<long long> path_weight(data.S, 0);
	for (auto &r : data.route) {
		long long sum_length = 0;
		for (int i : r) {
			sum_length += data.L[i];
		}

		for (int i : r) {
			path_weight[i] += sum_length;
		}
	}

	SolutionType solution;

	vector<vector<long long>> come_to(data.I);
	vector<long long> come_to_weight(data.I, 0);
	for (int i = 0; i < data.S; ++i) {
		if (path_weight[i] == 0) continue;

		come_to[data.E[i]].push_back(i);
		come_to_weight[data.E[i]] += path_weight[i];
	}

	for (int i = 0; i < data.I; ++i) {
		if (come_to_weight[i] == 0) continue;
		long long g = 0;
		for (long long j : come_to[i]) {
			g = __gcd(g, path_weight[j]);
		}

		long long mx = 0;
		for (long long j : come_to[i]) {
			path_weight[j] /= g;
			mx = max(mx, path_weight[j]);
		}

		solution.ID.push_back(i);
		solution.T.emplace_back();
		solution.name.emplace_back();

		long long fac = rand() % mx + 1;
		for (long long j : come_to[i]) {
			path_weight[j] = floor((double)path_weight[j] / fac);
			if (path_weight[j] == 0) continue;
			solution.T.back().push_back(path_weight[j]);
			solution.name.back().push_back(road_name[j]);
		}
	}

	solution.A = solution.ID.size();

	ScoreType score = Evaluate(data, solution);

	return make_pair(score, solution);
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
		vector<long long> path_weight(data.S, 0);
		for (auto &r : data.route) {
			long long sum_length = 0;
			for (int i : r) {
				sum_length += data.L[i];
			}

			for (int i : r) {
				path_weight[i] += sum_length;
			}
		}

		vector<vector<long long>> come_to(data.I);
		vector<long long> come_to_weight(data.I, 0);
		for (int i = 0; i < data.S; ++i) {
			if (path_weight[i] == 0) continue;

			come_to[data.E[i]].push_back(i);
			come_to_weight[data.E[i]] += path_weight[i];
		}

		int idx = rand() % solution.ID.size();
		int i = solution.ID[idx];

		long long g = 0;
		for (long long j : come_to[i]) {
			g = __gcd(g, path_weight[j]);
		}

		long long mx = 0;
		for (long long j : come_to[i]) {
			path_weight[j] /= g;
		}

		long long bruh = max(mx / data.D, 1ll);
		mx = 0;
		for (long long j : come_to[i]) {
			path_weight[j] /= bruh;
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


			long long fac = rand() % mx + 1;
			for (long long j : come_to[i]) {
				path_weight[j] = floor((double)path_weight[j] / fac);
				if (path_weight[j] == 0) continue;
				solution.T.back().push_back(path_weight[j]);
				solution.name.back().push_back(road_name[j]);
			}

			if (solution.T[idx].empty()) {
				solution.ID.erase(solution.ID.begin() + idx);
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

	auto [init_score, solution] = init_solve(data, argc, argv);

	record_solution(init_score, solution, argc, argv);

	int iteration = 0;

	vector<vector<pair<ScoreType, SolutionType>>> solutions;
	solutions.emplace_back();
	solutions[0].emplace_back(init_score, solution);

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
					is_better_score(solutions[gen - 1][0].first,
						solutions[gen].back().first))
				solutions[gen].pop_back();
		}


		while (solutions.back().empty()) solutions.pop_back();

		record_solution(solutions.back()[0].first, solutions.back()[0].second, argc,
				argv);

		if ((iteration & print_every_iteration) == 0) {
			cerr << "iterated " << iteration << " times. Best score: " << solutions.back()[0].first
				<< endl;
		}
	}
}
