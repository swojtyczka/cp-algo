#include <vector>

std::vector<bool> sieve(int size)
{
	std::vector<bool> isPrime(size + 1, true);
	isPrime[1] = false;
	for (int i = 2; i * i <= size; i++)
		if (isPrime[i])
			for (int j = i * i; j <= size; j += i)
				isPrime[j] = false;
	return isPrime;
}

// Modified version that stores smallest prime divisor

std::vector<int> sieveWithSmallestPrimeDivisor(int size)
{
	std::vector<int> smallestPrimeDivisor(size + 1);
	for (int i = 2; i <= size; i++)
	{
		if (smallestPrimeDivisor[i] == 0)
		{
			smallestPrimeDivisor[i] = i;
			for (int j = i * i; j <= size; j += i)
				if (smallestPrimeDivisor[j] == 0)
					smallestPrimeDivisor[j] = i;
		}
	}
	return smallestPrimeDivisor;
}

std::vector<int> prime_factorize(int x, const std::vector<int> &smallestPrimeDivisor)
{
	std::vector<int> result;

	while (smallestPrimeDivisor[x] not_eq 0)
	{
		result.push_back(smallestPrimeDivisor[x]);
		x /= smallestPrimeDivisor[x];
	}

	return result;
}
