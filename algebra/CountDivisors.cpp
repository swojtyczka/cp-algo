#include <vector>

std::vector<int> computeNumbersOfDivisors(int limit)
{
	std::vector<int> numOfDivisors;
	for (int i = 1; i <= limit; i++)
		for (int j = i; j <= limit; j += i)
			numOfDivisors[j]++;
	return numOfDivisors;
}