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

	void update(int l, int r, int val)
	{
		update_tree(1, 0, size - 1, l, r, val);
	}

	int query(int pos)
	{
		return query_tree(1, 0, size - 1, pos);
	}

  private:
	int query_tree(int v, int tl, int tr, int pos)
	{
		if (tl == tr)
			return tree[v];

		int tm = (tl + tr) / 2;

		if (pos <= tm)
			return tree[v] + query_tree(v * 2, tl, tm, pos);

		return tree[v] + query_tree(v * 2 + 1, tm + 1, tr, pos);
	}

	void update_tree(int v, int tl, int tr, int l, int r, int val)
	{

		if (r < tl || tr < l)
			return;

		if (l <= tl && tr <= r)
		{
			tree[v] += val;
			return;
		}

		int tm = (tl + tr) / 2;

		update_tree(v * 2, tl, tm, l, r, val);
		update_tree(v * 2 + 1, tm + 1, tr, l, r, val);
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
			tree[v] = 0;
		}
	}

	int size;
	std::vector<int> tree;
};