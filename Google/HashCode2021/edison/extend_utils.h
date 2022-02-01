#ifndef EXTEND_UTILS_H_
#define EXTEND_UTILS_H_

#include "util.h"

struct SolutionType {
  int A;
  std::vector<int> ID;
  std::vector<std::vector<int>> T;

  friend std::istream &operator>>(std::istream &is, SolutionType &solution) {
    return is;
  }
  friend std::ostream &operator<<(std::ostream &os,
                                  const SolutionType &solution) {
    return os;
  }
};

class InputData {
public:
  std::vector<std::vector<int>> g;
  std::map<std::string, int> ID;
  std::vector<int> B, E, L;
  int D, I, S, V, F;
  std::vector<std::vector<int>> route;

  friend std::istream &operator>>(std::istream &is, InputData &input) {
    is >> input.D >> input.I >> input.S >> input.V >> input.F;
    input.g.resize(input.I);
    input.B.resize(input.S);
    input.E.resize(input.S);
    input.L.resize(input.S);
    input.route.resize(input.V);
    for (int i = 0; i < input.S; ++i) {
      is >> input.B[i] >> input.E[i];
      std::string s;
      is >> s;
      input.ID[s] = i;
      is >> input.L[i];
    }
    for (int i = 0; i < input.V; ++i) {
      int P;
      is >> P;
      input.route[i].resize(P);
      for (int j = 0; j < P; ++j) {
        std::string s;
        is >> s;
        assert(input.ID.find(s) != input.ID.end());
        input.route[i][j] = input.ID[s];
      }
    }
    return is;
  }
};

class MoreInputData : InputData {
public:
	vector<vector<int>> ig;

	MoreInputData(const InputData &data) {
		g = data.g;
		ID = data.ID;
		B = data.B;
		E = data.E;
		L = data.L;
		D = data.D;
		I = data.I;
		S = data.S;
		V = data.V;
		F = data.F;
		route = data.route;

		ig.resize(g.size());
		for (int i = 0; i < (int)g.size(); ++i) {
			for (int j : g[i]) {
				ig[j].push_back(i);
			}
		}

	}
};

InputData ReadInput(const char *file) {
  std::ifstream ifs(file);
  InputData input;
  ifs >> input;
  return input;
}

SolutionType ReadSolution(const char *file) {
  std::ifstream ifs(file);
  SolutionType solution;
  ifs >> solution;
  return solution;
}

using ScoreType = int;

#endif  // EXTEND_UTILS_H_
