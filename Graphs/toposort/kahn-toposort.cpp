#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX_SIZE = 100000 + 7;
vector<int> G[MAX_SIZE];
int in_deg[MAX_SIZE];

vector<int> order;

void kahn(int n)
{
    priority_queue<int, vector<int>, greater<int>> Q;

    for (int i = 1; i <= n; i++)
        if (in_deg[i] == 0)
            Q.push(i);

    while (!Q.empty())
    {
        int top = Q.top();
        Q.pop();

        order.push_back(top);

        for (int v : G[top])
            if ((--in_deg[v]) == 0)
                Q.push(v);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, b;
    cin >> n >> m;
    while (m--)
    {
        cin >> a >> b;
        G[b].push_back(a);
        in_deg[a]++;
    }

    kahn(n);

    if (order.size() < n)
        cout << "NIE\n";
    else
    {
        for (auto it = begin(order); it < end(order); it++)
            cout << *it << " ";
    }

    cout << '\n';

    return 0;
}