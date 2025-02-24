// update point, query intervals

const int H = 1 << 19; // (10^6)/2
int tree[2 * H + 7];

void update(int pos, int val)
{
	pos += H;
	tree[pos] = val;
	while (pos > 1)
	{
		pos /= 2;
		tree[pos] = tree[pos * 2] + tree[pos * 2 + 1];
		// tree[pos] = max(tree[pos * 2], tree[pos * 2 + 1]);
	}
}

int query(int l, int r)
{
	l += H;
	r += H;

	if (l == r)
		return tree[l];

	int res = 0;

	while (l < r)
	{
		if (l % 2 == 1)
		{
			res += tree[l];
			// res = max(res, tree[l]);
			l++;
		}
		if (r % 2 == 0)
		{
			res += tree[r];
			// res = max(res, tree[r]);
			r--;
		}
		l /= 2;
		r /= 2;
	}

	if (l == r)
	{
		res += tree[l];
		// res = max(res, tree[l]);
	}

	return res;
}