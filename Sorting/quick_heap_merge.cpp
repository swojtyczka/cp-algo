#include <iostream>
using namespace std;

const int MAXN = 1000000 + 7;
int pom[MAXN];

void quicksort(int *tab, int l, int p)
{
    int i = l;
    swap(tab[p], tab[(l + p) / 2]);
    for (int j = l; j < p; j++)
        if (tab[j] < tab[p])
        {
            swap(tab[i], tab[j]);
            i++;
        }
    swap(tab[i], tab[p]);
    if (l < i - 1)
        quicksort(tab, l, i - 1);
    if (i + 1 < p)
        quicksort(tab, i + 1, p);
}

void merge(int *tab, int l, int m, int p)
{
    int i = l, j = m + 1, q = l;
    while (i <= m && j <= p)
    {
        if (tab[i] < tab[j])
            pom[q++] = tab[i++];
        else
            pom[q++] = tab[j++];
    }
    while (i <= m)
        pom[q++] = tab[i++];
    while (j <= p)
        pom[q++] = tab[j++];
    for (int i = l; i <= p; i++)
        tab[i] = pom[i];
}

void mergesort(int *tab, int l, int p)
{
    if (l < p)
    {
        int m = (l + p) / 2;
        mergesort(tab, l, m);
        mergesort(tab, m + 1, p);
        merge(tab, l, m, p);
    }
}

void heapify(int *tab, int n, int i)
{
    int root = i, l = 2 * i + 1, r = 2 * i + 2;

    if (l < n && tab[l] > tab[root])
        root = l;

    if (r < n && tab[r] > tab[root])
        root = r;

    if (root != i)
    {
        swap(tab[i], tab[root]);
        heapify(tab, n, root);
    }
}

void heapsort(int *tab, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(tab, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(tab[0], tab[i]);
        heapify(tab, i, 0);
    }
}
