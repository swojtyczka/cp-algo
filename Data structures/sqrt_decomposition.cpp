const int MAX_N = 2e5 + 7;
const int BLOCK_LEN = 447; // ~sqrt(2e5+7)
const int BLOCKS_NUM = MAX_N / BLOCK_LEN;
long long x[MAX_N], block[BLOCKS_NUM];

void init(int n)
{
	for (int i = 0; i < n; i++)
		block[i / BLOCK_LEN] += x[i];
}

long long query_sum(int l, int r)
{
	long long res = 0;
	while (l <= r)
	{
		if (l % BLOCK_LEN == 0 and l + BLOCK_LEN - 1 <= r)
		{
			res += block[l / BLOCK_LEN];
			l += BLOCK_LEN;
		}
		else
			res += x[l++];
	}
	return res;
}

void update(int k, int u)
{
	int old = x[k];
	x[k] = u;
	block[k / BLOCK_LEN] = block[k / BLOCK_LEN] - old + u;
}