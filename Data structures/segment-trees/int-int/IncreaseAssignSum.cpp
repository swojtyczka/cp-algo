// update intervals (add number to every element in interval or assign a new value to all elements in interval), query
// intervals (sum) v, tl i tr are the current node (subtree) and the current interval
#include <vector>

class SegmentTree
{
  public:
	SegmentTree(const std::vector<long long> &vec) : size(vec.size())
	{
		tree.resize(4 * size);
		lazy_inc.resize(4 * size);
		lazy_set.resize(4 * size);
		lazy_set_val.resize(4 * size);
		tree_build(vec, 1, 0, size - 1);
	}

	void increase(int l, int r, long long val)
	{
		tree_increase(1, 0, size - 1, l, r, val);
	}

	void set(int l, int r, long long val)
	{
		tree_set(1, 0, size - 1, l, r, val);
	}

	long long sum(int l, int r)
	{
		return tree_sum(1, 0, size - 1, l, r);
	}

  private:
	void push(int v, int tl, int tr)
	{
		int l = v * 2;
		int r = v * 2 + 1;
		int tm = (tl + tr) / 2;

		if (lazy_set[v])
		{
			tree[l] = lazy_set_val[v] * (tm - tl + 1);
			tree[r] = lazy_set_val[v] * (tr - tm);
			lazy_set[l] = true;
			lazy_set[r] = true;
			lazy_set_val[l] = lazy_set_val[v];
			lazy_set_val[r] = lazy_set_val[v];
			lazy_set[v] = false;

			lazy_inc[l] = 0;
			lazy_inc[r] = 0;
		}

		tree[l] += lazy_inc[v] * (tm - tl + 1);
		tree[r] += lazy_inc[v] * (tr - tm);
		lazy_inc[l] += lazy_inc[v];
		lazy_inc[r] += lazy_inc[v];
		lazy_inc[v] = 0;
	}

	void tree_increase(int v, int tl, int tr, int l, int r, long long val)
	{
		if (tl > r || tr < l)
			return;

		else if (l <= tl && tr <= r)
		{
			tree[v] += (tr - tl + 1) * val;
			lazy_inc[v] += val;
		}

		else
		{
			int tm = (tl + tr) / 2;

			push(v, tl, tr);

			tree_increase(v * 2, tl, tm, l, r, val);
			tree_increase(v * 2 + 1, tm + 1, tr, l, r, val);

			tree[v] = tree[v * 2] + tree[v * 2 + 1];
		}
	}

	void tree_set(int v, int tl, int tr, int l, int r, long long val)
	{
		if (tl > r || tr < l)
			return;

		else if (l <= tl && tr <= r)
		{
			tree[v] = (tr - tl + 1) * val;
			lazy_set_val[v] = val;
			lazy_set[v] = true;
			lazy_inc[v] = 0;
		}

		else
		{
			int tm = (tl + tr) / 2;

			push(v, tl, tr);

			tree_set(v * 2, tl, tm, l, r, val);
			tree_set(v * 2 + 1, tm + 1, tr, l, r, val);

			tree[v] = tree[v * 2] + tree[v * 2 + 1];
		}
	}

	long long tree_sum(int v, int tl, int tr, int l, int r)
	{
		if (r < tl || l > tr)
			return 0;

		else if (l <= tl && tr <= r)
			return tree[v];

		else
		{
			int tm = (tl + tr) / 2;

			push(v, tl, tr);

			return tree_sum(v * 2, tl, tm, l, r) + tree_sum(v * 2 + 1, tm + 1, tr, l, r);
		}
	}

	void tree_build(const std::vector<long long> &vec, int v, int tl, int tr)
	{
		if (tl == tr)
			tree[v] = vec[tl];
		else
		{
			int tm = (tl + tr) / 2;
			tree_build(vec, v * 2, tl, tm);
			tree_build(vec, v * 2 + 1, tm + 1, tr);
			tree[v] = tree[v * 2] + tree[v * 2 + 1];
		}
	}

	int size;
	std::vector<long long> tree{};
	std::vector<long long> lazy_inc{};
	std::vector<bool> lazy_set{};
	std::vector<long long> lazy_set_val{};
};