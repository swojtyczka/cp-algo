// compute k-th ancestor of a node in a tree in O(log n)

#include <cmath>
#include <vector>

std::vector<std::vector<int>> graph;
std::vector<std::vector<int>> up;

int L;

void dfs(int node, int parent)
{
	up[node][0] = parent;

	for (int i = 1; i <= L; i++)
		up[node][i] = up[up[node][i - 1]][i - 1];

	for (auto v : graph[node])
		if (v != parent)
			dfs(v, node);
}

void compute_up()
{
	L = ceil(log2(graph.size()));
	up.resize(graph.size(), std::vector<int>(L + 1));
	dfs(1, 0);
}

int kth_ancestor(int v, int k)
{
	int mask = 1;
	for (int j = 0; j <= L + 1; j++)
	{
		if (k & mask)
		{
			v = up[v][j];
			if (v == 0)
				break;
		}
		mask <<= 1;
	}
	return v ? v : -1;
}
