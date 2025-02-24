// Fast exponent algorithm to calculate a^n in O(log n) instead of O(n)

int fast_exp(int a, int n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
    {
        int x = fast_exp(a, n / 2);
        return x * x;
    }
    else
        return a * fast_exp(a, n - 1);
}