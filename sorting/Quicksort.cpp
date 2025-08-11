#include <vector>

void quicksort(std::vector<int> &vec, int l, int p)
{
	using std::swap;

	int i = l;

	swap(vec[p], vec[(l + p) / 2]);

	for (int j = l; j < p; j++)
	{
		if (vec[j] < vec[p])
		{
			swap(vec[i], vec[j]);
			i++;
		}
	}

	swap(vec[i], vec[p]);

	if (l < i - 1)
		quicksort(vec, l, i - 1);

	if (i + 1 < p)
		quicksort(vec, i + 1, p);
}