// Find uses path compression and union uses union by rank. Both operations are O(log*(n))
#include <vector>

class UnionFind
{
  public:
	UnionFind(int n)
	{
		parent.resize(n + 1);
		for (int i = 1; i <= n; i++)
		{
			parent[i] = i;
			rank[i] = 0;
		}
	}

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

		if (rank[a] < rank[b])
			parent[a] = b;
		else if (rank[a] > rank[b])
			parent[b] = a;
		else
		{
			parent[b] = a;
			rank[a]++;
		}
	}

  private:
	std::vector<int> parent;
	std::vector<int> rank;
};