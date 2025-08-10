// update intervals (add number to every element in interval), query intervals (min/max)
// v, tl i tr are the current node (subtree) and the current interval
#include <vector>

class SegmentTree
{
  public:
	SegmentTree(const std::vector<int> &vec) : size(vec.size())
	{
		tree.resize(4 * size);
		lazy.resize(4 * size);
		build_tree(vec, 1, 0, size - 1);
	}

	void update(int l, int r, int val)
	{
		tree_update(1, 0, size - 1, l, r, val);
	}

	int query(int l, int r)
	{
		return tree_query(1, 0, size - 1, l, r);
	}

  private:
	void push(int v)
	{
		tree[v * 2] += lazy[v];
		tree[v * 2 + 1] += lazy[v];
		lazy[v * 2] += lazy[v];
		lazy[v * 2 + 1] += lazy[v];
		lazy[v] = 0;
	}

	void tree_update(int v, int tl, int tr, int l, int r, int val)
	{
		if (tl > r || tr < l)
			return;

		else if (l <= tl && tr <= r)
		{
			tree[v] += val;
			lazy[v] += val;
		}

		else
		{
			int tm = (tl + tr) / 2;

			push(v);

			tree_update(v * 2, tl, tm, l, r, val);
			tree_update(v * 2 + 1, tm + 1, tr, l, r, val);

			tree[v] = std::min(tree[v * 2], tree[v * 2 + 1]);
		}
	}

	int tree_query(int v, int tl, int tr, int l, int r)
	{
		if (r < tl || l > tr)
			return 0;

		else if (l <= tl && tr <= r)
			return tree[v];

		else
		{
			int tm = (tl + tr) / 2;

			push(v);

			return std::min(tree_query(v * 2, tl, tm, l, r), tree_query(v * 2 + 1, tm + 1, tr, l, r));
		}
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
	std::vector<int> lazy{};
};