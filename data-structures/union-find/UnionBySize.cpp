// Find uses path compression and union uses union by size. Both operations are O(log*(n))
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
			size[i] = 1;
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

		if (size[a] < size[b])
			std::swap(a, b);

		parent[b] = a;
		size[a] += size[b];
	}

  private:
	std::vector<int> parent;
	std::vector<int> size;
};