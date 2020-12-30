// not tested
#include <algorithm>
#include <vector>
#include <utility>
template <typename FlowT, typename CostT>
struct MCMF {
	struct Edge {
		int u, v;
		FlowT f;
		CostT c;
	};
	int n;
	std::vector<Edge> edge;
	std::vector<std::vector<int>> g;
	MCMF(int n) : n(n) {
		g.resize(n);
	}
	int AddEdge(int u, int v, FlowT f, CostT c) {
		g[u].emplace_back(edge.size());
		edge.emplace_back(Edge{u, v, f, c});
		g[v].emplace_back(edge.size());
		edge.emplace_back(Edge{v, u, 0, -c});
		return edge.size() - 2;
	}
	std::pair<FlowT, CostT> Flow(int s, int t) {
		constexpr CostT eps = std::numeric_limits<CostT>::epsilon;
		std::vector<CostT> d(n);
		std::vector<FlowT> f(n); f[s] = std::numeric_limits<FlowT>::max;
		std::vector<int> cf(n);
		std::vector<int> q;
		std::vector<bool> inq(n);

		FlowT tf = 0;
		CostT tc = 0;
		while (true) {
			fill(d.begin(), d.end(), std::numeric_limits<CostT>::max); d[s] = 0;
			fill(f.begin(), f.end(), 0); f[s] = std::numeric_limits<FlowT>::max;
			q.resize(1); q[0] = s; int front = 0;
			fill(inq.begin(), inq.end(), false); inq[s] = true;

			while (front != static_cast<int>(q.size())) {
				int now = q[front++];
				inq[now] = false;

				for (int ei : g[now]) {
					Edge &e = edge[ei];

					if (e.f > eps && d[now] + e.c < d[e.v]) {
						d[e.v] = d[now] + e.c;
						f[e.v] = std::min(f[now], e.f);
						cf[e.v] = ei;
						if (!inq[e.v]) {
							inq[e.v] = true;
							q.push_back(e.v);
						}
					}
				}
			}

			if (f[t] == 0) break;

			tf += f[t];
			tc += f[t] * d[t];
			
			int u = t;
			for (int ei = cf[u]; u != s; u = edge[ei].u, ei = cf[u]) {
				edge[ei].f -= f[t];
				edge[ei ^ 1].f += f[t];
			}
		}

		return std::pair(tf, tc);
	}
};
