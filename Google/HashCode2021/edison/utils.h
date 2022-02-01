#ifndef UTILS_H_
#define UTILS_H_

#include <iostream>
#include <cassert>
#include <fstream>
#include <string>
#include <map>
#include <vector>

struct SolutionType {
  int A;
  std::vector<int> ID;
  std::vector<std::vector<int>> T;
  std::vector<std::vector<std::string>> name;

  friend std::istream &operator>>(std::istream &is, SolutionType &solution) {
    auto &A = solution.A;
    auto &ID = solution.ID;
    auto &T = solution.T;
    auto &name = solution.name;
    is >> A;
    ID.resize(A);
    T.resize(A);
    name.resize(A);
    for (int i = 0; i < A; ++i) {
      is >> ID[i];
      int E;
      is >> E;
      T[i].resize(E);
      name[i].resize(E);
      for (int j = 0; j < E; ++j) is >> name[i][j] >> T[i][j];
    }
    return is;
  }
  friend std::ostream &operator<<(std::ostream &os,
                                  const SolutionType &solution) {
    const auto &A = solution.A;
    const auto &ID = solution.ID;
    const auto &T = solution.T;
    const auto &name = solution.name;
    os << A << "\n";
    for (int i = 0; i < A; ++i) {
      os << ID[i] << "\n";
      os << T[i].size() << "\n";
      for (int j = 0; j < T[i].size(); ++j) {
        os << name[i][j] << " " << T[i][j] << "\n";
      }
    }
    return os;
  }
};

struct InputData {
  std::map<std::string, int> ID;
  std::vector<int> B, E, L;
  int D, I, S, V, F;
  std::vector<std::vector<int>> route;

  friend std::istream &operator>>(std::istream &is, InputData &input) {
    int &D = input.D, &I = input.I, &S = input.S, &V = input.V, &F = input.F;
    is >> D >> I >> S >> V >> F;
    auto &B = input.B, &E = input.E, &L = input.L;
    auto &route = input.route;
    auto &ID = input.ID;
    B.resize(S);
    E.resize(S);
    L.resize(S);
    route.resize(V);
    for (int i = 0; i < S; ++i) {
      is >> B[i] >> E[i];
      std::string s;
      is >> s;
      ID[s] = i;
      is >> L[i];
    }
    for (int i = 0; i < V; ++i) {
      int P;
      is >> P;
      route[i].resize(P);
      for (int j = 0; j < P; ++j) {
        std::string s;
        is >> s;
        assert(ID.find(s) != ID.end());
        route[i][j] = ID[s];
      }
    }
    return is;
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

void FixSolution(const InputData &data, SolutionType &solution) {
	int t = data.D;

	for (int i = 0; i < (int)solution.ID.size(); ++i) {
		int totalT = 0;
		for (int j = 0; j < (int)solution.T[i].size(); ++j) {
			totalT += solution.T[i][j];
			if (totalT >= t) {
				solution.T[i][j] -= totalT - t;
				totalT = t;
			}
		}

		// std::cerr << "size = " << solution.T[i].size() << std::endl;
		// for (int j : solution.T[i]) std::cerr << j << ' '; std::cerr << std::endl;
		while (solution.T[i].size() && solution.T[i].back() == 0) {
			solution.T[i].pop_back();
			solution.name[i].pop_back();
		}

		if (solution.T[i].empty()) {
			solution.ID.erase(solution.ID.begin() + i);
			solution.T.erase(solution.T.begin() + i);
			solution.name.erase(solution.name.begin() + i);
			--solution.A;
			--i;
		}
	}
}

using ScoreType = int;

#endif  // UTILS_H_
