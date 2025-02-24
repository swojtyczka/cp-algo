// v, tl i tr are the current node (subtree) and the current interval
// in this case, we use the segment tree to compute sum
#include <iostream>

const int MAX_N = 1e5 + 7;
int tree[4 * MAX_N];

int query(int v, int tl, int tr, int pos)
{
	if (tl == tr)
		return tree[v];
	else
	{
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			return tree[v] + query(v * 2, tl, tm, pos);
		else
			return tree[v] + query(v * 2 + 1, tm + 1, tr, pos);
	}
}

void update(int v, int tl, int tr, int l, int r, int val)
{
	if (l > r)
		return;

	if (l == tl && r == tr)
	{
		tree[v] += val;
		return;
	}

	int tm = (tl + tr) / 2;

	update(v * 2, tl, tm, l, std::min(r, tm), val);
	update(v * 2 + 1, tm + 1, tr, std::max(l, tm + 1), r, val);
}