#include <algorithm>
#include <vector>

int n;
std::vector<bool> vis;
std::vector<std::vector<int>> graph;

void dfs(int v, std::vector<int> &order)
{
	vis[v] = true;
	for (int u : graph[v])
	{
		if (not vis[u])
		{
			dfs(u, order);
		}
	}
	order.push_back(v);
}

std::vector<int> toposort()
{
	std::vector<int> order;
	vis.assign(n + 1, false);

	for (int i = 1; i <= n; i++)
	{
		if (not vis[i])
		{
			dfs(i, order);
		}
	}

	std::ranges::reverse(order);

	return order;
}