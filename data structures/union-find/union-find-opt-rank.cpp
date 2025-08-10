// Find uses path compression and union uses union by rank. Both operations are O(log*(n))

const int MAX_SIZE = 1000000 + 7;
int parent[MAX_SIZE], rank[MAX_SIZE];

int Find(int x)
{
	if (parent[x] == x)
		return x;

	parent[x] = Find(parent[x]);
	return parent[x] ;
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);

    if (a == b)
        return;

    if (rank[a] < rank[b])
        parent[a] = b;
    else if (rank[a] > rank[b])
        parent[b] = a;
    else
    {
        parent[b] = a;
        rank[a]++;
    }
}

void Init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}
