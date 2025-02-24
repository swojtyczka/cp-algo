#include <iostream>
#include <cstdint>
using namespace std;

int nominaly[200 + 7];
int dp[20000 + 7];
const int INF = INT32_MAX;

void generuj(int n, int R)
{
    fill(begin(dp), end(dp), INF);
    dp[0] = 0;

    for (int j = 1; j <= R; j++)
    {
        for (int i = 0; i < n; i++)
            if ((nominaly[i] <= j) && dp[j - nominaly[i]] < INF)
                dp[j] = min(dp[j], dp[j - nominaly[i]] + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> nominaly[i];

    int k;
    cin >> k;

    generuj(n, k);

    cout << (dp[k] == INF ? -1 : dp[k]) << '\n';

    return 0;
}