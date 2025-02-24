// BFS - in this case, computing shortest paths from a source node

#include <vector>
#include <queue>

const int MAX_SIZE = 1000000 + 7;

std::vector<int> G[MAX_SIZE];
int dist[MAX_SIZE];
bool vis[MAX_SIZE];

void bfs(int start)
{
	vis[start] = true;
	std::queue<int> q;
	q.push(start);

	while (!q.empty())
	{
		int curr = q.front();
		q.pop();
		for (int u : G[curr])
			if (!vis[u])
			{
				vis[u] = true;
				dist[u] = dist[curr] + 1;
				q.push(u);
			}
	}
}