// search for a specific value in a sorted [l,r) range
#include <vector>

// first value bigger or equal than
int lowerBound(const std::vector<int> &vec, int l, int r, int x)
{
	while (l < r)
	{
		int s = (l + r) / 2;
		if (x > vec[s])
			l = s + 1;
		else
			r = s;
	}
	return l;
}

// first value bigger than
int upperBound(const std::vector<int> &vec, int l, int r, int x)
{
	while (l < r)
	{
		int s = (l + r) / 2;
		if (x >= vec[s])
			l = s + 1;
		else
			r = s;
	}
	return l;
}