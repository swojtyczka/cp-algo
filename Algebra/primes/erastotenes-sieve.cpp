// Algorithm that crosses out prime numbers less than specific threshold

void sieve(bool tab[], int n)
{
	tab[0] = tab[1] = true;
	for (int i = 2; i * i <= n; i++)
		if (!tab[i]) // if is prime
			for (int j = i * i; j <= n; j += i)
				tab[j] = true;
}