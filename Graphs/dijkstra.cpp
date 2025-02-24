// compute shortest paths from a source node in a weighted graph. Edge is stored as (weight, node)

#include <vector>
#include <queue>
#include <limits>

using Edge = std::pair<int, int>;

const int MAX_N = 1000000 + 7;
std::vector<Edge> G[MAX_N];
int dist[MAX_N];

void dijkstra(int start)
{
    std::fill(dist, dist + MAX_N, std::numeric_limits<int>::max());

    dist[start] = 0;

    std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> pq;
    pq.push({0, start});

    while (!pq.empty())
    {
        int curr_dist = pq.top().first;
        int curr_id = pq.top().second;
        pq.pop();

        if (curr_dist > dist[curr_id])
            continue;

        for (auto p : G[curr_id])
            if (curr_dist + p.first < dist[p.second])
            {
                dist[p.second] = curr_dist + p.first;
                pq.push({dist[p.second], p.second});
            }
    }
}