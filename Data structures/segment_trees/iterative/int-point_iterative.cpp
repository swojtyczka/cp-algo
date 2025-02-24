// update intervals, query points

const int H = 1 << 19; // (10^6)/2
int tree[2 * H + 7];

void update(int l, int r, int v)
{
	l += H;
	r += H;
	while (l < r)
	{
		if (l % 2 == 1)
		{
			tree[l] += v;
			l++;
		}
		if (r % 2 == 0)
		{
			tree[r] += v;
			r--;
		}
		l /= 2;
		r /= 2;
	}

	if(l == r)
		tree[l] += v;
}

int query(int pos)
{
	pos += H;
	int res = 0;
	while (pos > 0)
	{
		res += tree[pos];
		pos /= 2;
	}
	return res;
}