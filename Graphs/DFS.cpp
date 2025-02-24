#include <vector>

const int MAX_SIZE = 1000000 + 7;
std::vector<int> G[MAX_SIZE];
bool vis[MAX_SIZE];

void dfs(int start)
{
	vis[start] = true;
	for (int u : G[start])
		if (!vis[u])
			dfs(u);
}