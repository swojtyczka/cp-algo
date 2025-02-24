#include <iostream>
using namespace std;

const int MAX_SIZE = 1000000 + 7;
int tab[MAX_SIZE];

int gasienica(int n, int ilec)
{
    int res = MAX_SIZE, glowa = 0, ogon = 1, akt_sum = 0;
    while (glowa < n)
    {
        glowa++;
        akt_sum += tab[glowa];

        if (akt_sum < ilec)
            continue;

        if (akt_sum == ilec)
            res = min(res, glowa - ogon + 1);

        while (ogon < glowa && akt_sum >= ilec)
        {
            akt_sum -= tab[ogon];
            ogon++;

            if (akt_sum == ilec)
                res = min(res, glowa - ogon + 1);
        }
    }
    return res;
}

int main()
{

    return 0;
}