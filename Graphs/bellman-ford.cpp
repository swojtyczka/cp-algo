// compute shortest paths from a source node in a weighted graph, but also checks for a negative cycles.

#include <limits>
#include <vector>

const int MAX_N = 1000000 + 7, INF = std::numeric_limits<int>::max();

using Edge = struct
{
	int weight;
	int src;
	int dest;
};

std::vector<Edge> E;
int dist[MAX_N];

bool bellmanford(int start, int nodes)
{
	std::fill(dist, dist + MAX_N, INF);

	dist[start] = 0;

	for (int i = 0; i < nodes; i++)
		for (const auto &edge : E)
			if (dist[edge.src] != INF && dist[edge.src] + edge.weight < dist[edge.dest])
			{
				dist[edge.dest] = dist[edge.src] + edge.weight;

				if (i == nodes - 1)
					return false;
			}

	return true;
}