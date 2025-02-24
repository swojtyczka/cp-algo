#include <iostream>
#include <algorithm>
using namespace std;

int tab[1000000 + 7];

// first value bigger or equal than
int lower_bound(int *T, int l, int r, int x)
{
	while (l < r)
	{
		int s = (l + r) / 2;
		if (x > T[s])
			l = s + 1;
		else
			r = s;
	}
	return l;
}

// first value bigger than
int upper_bound(int *T, int l, int r, int x)
{
	while (l < r)
	{
		int s = (l + r) / 2;
		if (x >= T[s])
			l = s + 1;
		else
			r = s;
	}
	return l;
}

int main()
{
	int n, q;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> tab[i];

	cin >> q;

	sort(tab, tab + n);

	cout << lower_bound(tab, 0, n - 1, q) << '\n';

	return 0;
}