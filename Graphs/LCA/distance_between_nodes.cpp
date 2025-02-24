// compute distances betwen nodes in a tree using LCA and euler tour

#include <algorithm>
#include <limits>
#include <vector>

std::vector<std::vector<int>> graph;

std::vector<int> euler_tour_depths;
std::vector<int> depth;
std::vector<int> first_occurrence;

void dfs(int node, int parent, int curr_depth)
{
	first_occurrence[node] = euler_tour_depths.size();
	euler_tour_depths.push_back(curr_depth);

	depth[node] = curr_depth;

	for (int v : graph[node])
	{
		if (v != parent)
		{
			dfs(v, node, curr_depth + 1);
			euler_tour_depths.push_back(curr_depth);
		}
	}
}

void preprocessing()
{
	depth.resize(graph.size());
	first_occurrence.resize(graph.size());

	dfs(1, 1, 0);
}

class SegmentTree
{
  public:
	SegmentTree(int n) : size(n)
	{
		tree.resize(4 * size);
	}

	SegmentTree(const std::vector<int> &vec) : size(vec.size())
	{
		tree.resize(4 * size);
		build_tree(vec, 1, 0, size - 1);
	}

	void update(int pos, int val)
	{
		update_tree(1, 0, size - 1, pos, val);
	}

	int query(int l, int r)
	{
		return query_tree(1, 0, size - 1, l, r);
	}

  private:
	void update_tree(int v, int tl, int tr, int pos, int val)
	{
		if (tl == tr)
			tree[v] = val;
		else
		{
			int tm = (tl + tr) / 2;
			if (pos <= tm)
				update_tree(v * 2, tl, tm, pos, val);
			else
				update_tree(v * 2 + 1, tm + 1, tr, pos, val);
			tree[v] = std::min(tree[v * 2], tree[v * 2 + 1]);
		}
	}

	int query_tree(int v, int tl, int tr, int l, int r)
	{
		if (l > r)
			return std::numeric_limits<int>::max();

		if (l == tl && r == tr)
			return tree[v];

		int tm = (tl + tr) / 2;
		return std::min(query_tree(v * 2, tl, tm, l, std::min(r, tm)),
						query_tree(v * 2 + 1, tm + 1, tr, std::max(l, tm + 1), r));
	}

	void build_tree(const std::vector<int> &vec, int v, int tl, int tr)
	{
		if (tl == tr)
			tree[v] = vec[tl];
		else
		{
			int tm = (tl + tr) / 2;
			build_tree(vec, v * 2, tl, tm);
			build_tree(vec, v * 2 + 1, tm + 1, tr);
			tree[v] = std::min(tree[v * 2], tree[v * 2 + 1]);
		}
	}

	int size;
	std::vector<int> tree{};
};

int dist(int u, int v)
{
	SegmentTree segment_tree(euler_tour_depths);

	const auto [lesser, greater] = std::minmax(first_occurrence[u], first_occurrence[v]);

	int lca_depth = segment_tree.query(lesser, greater);

	return depth[u] + depth[v] - 2 * lca_depth;
}
