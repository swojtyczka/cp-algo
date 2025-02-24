// v, tl i tr are the current node (subtree) and the current interval
// in this case, we use the segment tree to compute sum
#include <iostream>

const int MAX_N = 1e5 + 7;
int tree[4 * MAX_N];
int tab[MAX_N];

void build(int v, int tl, int tr)
{
	if (tl == tr)
		tree[v] = tab[tl];
	else
	{
		int tm = (tl + tr) / 2;
		build(v * 2, tl, tm);
		build(v * 2 + 1, tm + 1, tr);
		tree[v] = tree[v * 2] + tree[v * 2 + 1];
	}
}

void update(int v, int tl, int tr, int pos, int val)
{
	if (tl == tr)
		tree[v] = val;
	else
	{
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			update(v * 2, tl, tm, pos, val);
		else
			update(v * 2 + 1, tm + 1, tr, pos, val);
		tree[v] = tree[v * 2] + tree[v * 2 + 1];
	}
}

int query(int v, int tl, int tr, int l, int r)
{
	if (l > r)
		return 0;

	if (l == tl && r == tr)
		return tree[v];

	int tm = (tl + tr) / 2;
	return query(v * 2, tl, tm, l, std::min(r, tm)) +
		   query(v * 2 + 1, tm + 1, tr, std::max(l, tm + 1), r);
}
