#include <cmath>
#include <vector>

std::vector<std::vector<int>> graph;
std::vector<std::vector<int>> up;

int timer;
std::vector<int> time_in;
std::vector<int> time_out;

int L;

void dfs(int node, int parent)
{
	up[node][0] = parent;

	time_in[node] = timer++;

	for (int i = 1; i <= L; i++)
		up[node][i] = up[up[node][i - 1]][i - 1];

	for (auto v : graph[node])
		if (v != parent)
			dfs(v, node);

	time_out[node] = timer++;
}

void preprocessing()
{
	L = ceil(log2(graph.size()));
	up.resize(graph.size(), std::vector<int>(L + 1));

	timer = 0;
	time_in.resize(graph.size());
	time_out.resize(graph.size());

	dfs(1, 1);
}

bool is_ancestor(int ancestor, int other)
{
	return time_in[ancestor] <= time_in[other] and time_out[ancestor] >= time_out[other];
}

int lca(int u, int v)
{
	if (is_ancestor(u, v))
		return u;

	if (is_ancestor(v, u))
		return v;

	for (int i = L; i >= 0; i--)
		if (not is_ancestor(up[u][i], v))
			u = up[u][i];

	return up[u][0];
}