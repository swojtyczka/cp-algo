#include <vector>
void merge(std::vector<int> &vec, int l, int m, int p)
{
	std::vector<int> temp(vec.size());
	int i = l, j = m + 1, q = l;
	while (i <= m && j <= p)
	{
		if (vec[i] < vec[j])
			temp[q++] = vec[i++];
		else
			temp[q++] = vec[j++];
	}
	while (i <= m)
		temp[q++] = vec[i++];
	while (j <= p)
		temp[q++] = vec[j++];
	for (int i = l; i <= p; i++)
		vec[i] = temp[i];
}

void mergesort(std::vector<int> &vec, int l, int p)
{
	if (l < p)
	{
		int m = (l + p) / 2;
		mergesort(vec, l, m);
		mergesort(vec, m + 1, p);
		merge(vec, l, m, p);
	}
}
