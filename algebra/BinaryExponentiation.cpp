int binaryExp(int a, int n)
{
	if (n == 0)
		return 1;

	if (n % 2 == 0)
	{
		int x = binaryExp(a, n / 2);
		return x * x;
	}

	return a * binaryExp(a, n - 1);
}