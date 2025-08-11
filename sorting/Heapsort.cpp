#include <vector>

using std::swap;

void heapify(std::vector<int> &vec, int i)
{
	int root = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < vec.size() and vec[l] > vec[root])
		root = l;

	if (r < vec.size() and vec[r] > vec[root])
		root = r;

	if (root != i)
	{
		swap(vec[i], vec[root]);
		heapify(vec, root);
	}
}

void heapsort(std::vector<int> &vec)
{
	for (int i = vec.size() / 2 - 1; i >= 0; i--)
		heapify(vec, i);

	for (int i = vec.size() - 1; i > 0; i--)
	{
		swap(vec[0], vec[i]);
		heapify(vec, 0);
	}
}
