// compute all shortest paths in a weighted graph

#include <iostream>
#include <limits>

const int MAX_SIZE = 1000 + 7, INF = std::numeric_limits<int>::max();
int dist[MAX_SIZE][MAX_SIZE];

void prep(int n)
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i == j)
				dist[i][j] = 0;
			else
				dist[i][j] = INF;
}

void floydwarshall(int n)
{
	for (int k = 1; k <= n; k++)
		for (int u = 1; u <= n; u++)
			for (int v = 1; v <= n; v++)
				dist[u][v] = std::min(dist[u][v], dist[u][k] + dist[k][v]);
}