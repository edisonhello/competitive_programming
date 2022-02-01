#ifndef CHECKER_H_
#define CHECKER_H_

#include <algorithm>
#include <iostream>
#include <queue>
#include <set>

#include "utils.h"

ScoreType Evaluate(const InputData &input, const SolutionType &solution) {
  int S = input.S, V = input.V, D = input.D, F = input.F, I = input.I;
  auto &E = input.E;
  std::vector<std::queue<int>> que(S);
  std::vector<int> worklist;
  std::vector<int> degree(I);
  std::vector<int> addition;
  std::vector<bool> removed(I);
  int calls = 0;

  auto Increment = [&](int p) {
    calls++;
    if (degree[p]++ == 0) addition.push_back(p);
  };

  auto Decrement = [&](int p) {
    calls++;
    if (--degree[p] == 0) removed[p] = true;
  };

  for (int i = 0; i < V; ++i) {
    assert(!input.route[i].empty());
    que[input.route[i][0]].push(i);
    Increment(E[input.route[i][0]]);
  }
  std::vector<std::vector<int>> events(D + 1);
  std::vector<int> iter(V);
  std::vector<int> period(I, -1);
  std::vector<std::vector<std::pair<int, int>>> cycle(I);
  int A = solution.A;
  for (int i = 0; i < A; ++i) {
    int ID = solution.ID[i];
    assert(period[ID] == -1);
    period[ID] = 0;
    for (int j = 0; j < solution.T[i].size(); ++j) {
      assert(input.ID.find(solution.name[i][j]) != input.ID.end());
      int s = input.ID.find(solution.name[i][j])->second;
      if (solution.T[i][j] > D) return -1;
      cycle[ID].emplace_back(solution.T[i][j], s);
      period[ID] += solution.T[i][j];
    }
  }
  for (int i = 0; i < I; ++i) {
    if (period[i] == -1) continue;
    for (int j = 1; j < cycle[i].size(); ++j) {
      cycle[i][j].first += cycle[i][j - 1].first;
    }
  }

  std::vector<int> new_worklist;

  auto UpdateWorklist = [&]() {
    if (calls == 0) return;
    calls = 0;
    new_worklist.clear();
    new_worklist.insert(new_worklist.end(), addition.begin(), addition.end());
    addition.clear();
    for (int u : worklist) {
      if (!removed[u]) new_worklist.push_back(u);
      removed[u] = false;
    }
    worklist.swap(new_worklist);
  };

  int score = 0;
  for (int i = 0; i <= D; ++i) {
    UpdateWorklist();
    for (int car : events[i]) {
      if (iter[car] + 1 == input.route[car].size()) {
        score += F + D - i;
      } else {
        que[input.route[car][iter[car]]].push(car);
        Increment(E[input.route[car][iter[car]]]);
      }
    }
    UpdateWorklist();
    for (int its : worklist) {
      if (period[its] == -1) continue;
      int t = i % period[its];
      int it = std::lower_bound(cycle[its].begin(), cycle[its].end(), t,
                                [](const std::pair<int, int> &lhs, int rhs) {
                                  return lhs.first <= rhs;
                                }) -
               cycle[its].begin();
      int street = cycle[its][it].second;
      if (!que[street].empty()) {
        int car = que[street].front();
        Decrement(its);
        que[street].pop();
        assert(iter[car] + 1 < input.route[car].size());
        iter[car]++;
        int nxt = input.route[car][iter[car]];
        if (i + input.L[nxt] <= D) events[i + input.L[nxt]].push_back(car);
      }
    }
  }
  return score;
}

#endif  // CHECKER_H_
