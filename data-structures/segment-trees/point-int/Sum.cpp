// v, tl i tr are the current node (subtree) and the current interval
// in this case, we use the segment tree to compute sum
#include <vector>

class SegmentTree
{
  public:
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
			tree[v] = tree[v * 2] + tree[v * 2 + 1];
		}
	}

	int query_tree(int v, int tl, int tr, int l, int r)
	{
		if (r < tl || tr < l)
			return 0;

		if (l <= tl && tr <= r)
			return tree[v];

		int tm = (tl + tr) / 2;
		return query_tree(v * 2, tl, tm, l, r) + query_tree(v * 2 + 1, tm + 1, tr, l, r);
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
			tree[v] = tree[v * 2] + tree[v * 2 + 1];
		}
	}

	int size;
	std::vector<int> tree;
};