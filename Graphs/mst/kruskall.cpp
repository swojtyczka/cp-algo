#include <vector>
#include <algorithm>

const int MAXN = 7000 + 7;
int parent[MAXN], size[MAXN];

struct Edge
{
	int num, weight, NodeA, NodeB;
};

int Find(int x)
{
	if (parent[x] == x)
		return x;

	parent[x] = Find(parent[x]);
	return parent[x];
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a == b)
		return;

	if (size[a] < size[b])
		std::swap(a, b);

	parent[b] = a;
	size[a] += size[b];
}

void Init(int n)
{
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
		size[i] = 1;
	}
}

bool comp(Edge e1, Edge e2)
{
	if (e1.weight < e2.weight)
		return true;
	if (e1.weight == e2.weight)
		return (e1.num < e2.num);
	return false;
}

std::vector<Edge> kruskall(int n, const std::vector<Edge> &edges)
{
	std::vector<Edge> mst_edges;

	Init(n);

	sort(edges.begin(), edges.end(), comp);

	for (const Edge &edge : edges)
	{
		int Na = edge.NodeA, Nb = edge.NodeB;
		if (Find(Na) != Find(Nb))
		{
			mst_edges.push_back(edge);
			Union(Na, Nb);
		}
	}

	return mst_edges;
}
