// Basic version. Find O(n) / Union O(n)

const int MAX_SIZE = 1000000 + 7;
int parent[MAX_SIZE];

int Find(int x)
{
    if (parent[x] == x)
        return x;

    return Find(parent[x]);
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);

    if (a != b)
        parent[a] = b;
}

void Init(int n)
{
    for (int i = 1; i <= n; i++)
        parent[i] = i;
}