// Basic version. Find O(n) / Union O(n)
#include <vector>

class UnionFind
{
  public:
	UnionFind(int n)
	{
		parent.resize(n + 1);
		for (int i = 1; i <= n; i++)
			parent[i] = i;
	}

	int Find(int x)
	{
		if (parent[x] == x)
			return x;

		return Find(parent[x]);
	}

	void Union(int a, int b)
	{
		a = Find(a);
		b = Find(b);

		if (a != b)
			parent[a] = b;
	}

  private:
	std::vector<int> parent;
};