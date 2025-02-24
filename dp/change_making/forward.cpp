#include <iostream>
using namespace std;

int nominaly[1000 + 7];
bool dpc[100000];
int dp[100000];

void generuj(int monety, int kwota)
{
    dp[0] = 0;
    dpc[0] = true;
    for (int i = 0; i < monety; i++)
    {
        int x = nominaly[i];

        for (int j = 0; j <= kwota; j++)
            if (dpc[j])
            {
                if (dpc[j + x])
                    dp[j + x] = min(dp[j] + 1, dp[j + x]);
                else
                {
                    dpc[j + x] = true;
                    dp[j + x] = dp[j] + 1;
                }
            }
    }
}

void generuj_z_limitem(int monety, int kwota)
{
    dp[0] = 0;
    dpc[0] = true;
    for (int i = 0; i < monety; i++)
    {
        int x = nominaly[i];

        for (int j = kwota; j >= 0; j--)
            if (dpc[j])
            {
                if (dpc[j + x])
                    dp[j + x] = min(dp[j] + 1, dp[j + x]);
                else
                {
                    dpc[j + x] = true;
                    dp[j + x] = dp[j] + 1;
                }
            }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> nominaly[i];
    cin >> k;

    generuj(n, k);

    if (dp[k])
        cout << "TAK";
    else
        cout << "NIE";

    return 0;
}