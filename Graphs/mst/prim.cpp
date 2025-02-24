#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

const int MAXN = 7000 + 7;

using pii = std::pair<int, int>;
std::vector<pii> G[MAXN]; // (weight, node)
bool vis[MAXN];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        G[a].push_back(std::make_pair(c, b));
        G[b].push_back(std::make_pair(c, a));
    }

    int mst_weight = 0;

    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
    pq.push(std::make_pair(0, 1));
    while (!pq.empty())
    {
        int w = pq.top().first, v = pq.top().second;
        pq.pop();
        if (!vis[v])
        {
            vis[v] = true;
            mst_weight += w;
            for (auto u : G[v])
                if (!vis[u.second])
                    pq.push(u);
        }
    }

    std::cout << mst_weight << '\n';

    return 0;
}
