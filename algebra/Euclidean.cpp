int gcd_iter(int a, int b)
{
    int c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int gcd_rec(int a, int b)
{
    if (b == 0)
        return a;
    return gcd_rec(b, a % b);
}