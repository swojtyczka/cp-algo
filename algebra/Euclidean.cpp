int gcdIter(int a, int b)
{
	int c = a % b;
	while (b not_eq 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int gcdRec(int a, int b)
{
	if (b == 0)
		return a;
	return gcdRec(b, a % b);
}