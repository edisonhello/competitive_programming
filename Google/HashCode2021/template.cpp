#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

using ScoreType = int;
using DataType = int;
using SolutionType = int;

const bool debug = 0;
const int print_every_iteration = 1048576 - 1;

void init_args(int argc, char **argv) {

}

DataType input(int argc, char **argv) {

}

pair<ScoreType, SolutionType> init_solve(const DataType &data, int argc, char **argv) {

}

pair<ScoreType, SolutionType> next_solve(const DataType &data, const SolutionType &prev_solution, int argc, char **argv) {

}

string convert_solution_to_string(const ScoreType score, const SolutionType &solution, int argc, char **argv) {

}

void record_solution(const ScoreType score, const SolutionType &solution, int argc, char **argv) {
	string filename = "solutions/" + to_string(score);
	ofstream out(filename);

	out << convert_solution_to_string(score, solution, argc, argv);

	out.close();
}

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	init_args(argc, argv);

	DataType data = input(argc, argv);

	auto [init_score, solution] = init_solve(data, argc, argv);

	record_solution(init_score, solution, argc, argv);

	int iteration = 0;
	while (true) {
		++iteration;

		auto [new_score, new_solution] = next_solve(data, solution, argc, argv);

		if (new_score > init_score) {
			init_score = new_score;
			solution = new_solution;
			record_solution(new_score, new_solution, argc, argv);
		}

		if ((iteration & print_every_iteration) == 0) {
			cerr << "iterated " << iteration << " times. Best score: " << init_score << endl;
		}
	}
}
