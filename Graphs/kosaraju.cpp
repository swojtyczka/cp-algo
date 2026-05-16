#include <algorithm>
#include <vector>

void dfs(int v, const std::vector<std::vector<int>> &graph, std::vector<bool> &visited, std::vector<int> &order)
{
	visited[v] = true;
	for (int u : graph[v])
	{
		if (not visited[u])
		{
			dfs(u, graph, visited, order);
		}
	}

	order.push_back(v);
}

std::vector<std::vector<int>> scc(const std::vector<std::vector<int>> &graph)
{
	std::vector<bool> visited(graph.size());

	std::vector<int> order;
	for (int v = 1; v < graph.size(); v++)
	{
		if (not visited[v])
		{
			dfs(v, graph, visited, order);
		}
	}
	std::ranges::reverse(order);

	std::vector<std::vector<int>> revGraph(graph.size());
	for (int v = 1; v < graph.size(); v++)
	{
		for (int u : graph[v])
		{
			revGraph[u].push_back(v);
		}
	}

	visited.clear();
	visited.resize(revGraph.size(), false);

	std::vector<std::vector<int>> components;

	for (int v : order)
	{
		std::vector<int> component;
		if (not visited[v])
		{
			dfs(v, revGraph, visited, component);
			components.push_back(component);
		}
	}

	return components;
}