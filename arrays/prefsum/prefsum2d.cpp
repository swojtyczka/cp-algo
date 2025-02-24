#include <iostream>
using namespace std;

const int MAX_SIZE = 1000 + 7;
int tab[MAX_SIZE][MAX_SIZE];
long long sum[MAX_SIZE][MAX_SIZE];

void fill(int n, int m)
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + tab[i][j];
}

int query(int a, int b, int c, int d)
{
	int wyn = sum[c][d];
	wyn -= sum[a - 1][d];
	wyn -= sum[c][b - 1];
	wyn += sum[a - 1][b - 1];
	return wyn;
}