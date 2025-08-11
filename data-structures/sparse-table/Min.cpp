#include <cmath>
#include <vector>

class SparseTable
{
  public:
	SparseTable(const std::vector<int> &vec)
	{
		const int logSize = static_cast<int>(std::ceil(std::log(vec.size()))) + 1;

		sparseTable.resize(vec.size(), std::vector<int>(logSize));

		for (size_t i = 0; i < vec.size(); i++)
			sparseTable[i][0] = vec[i];

		for (int j = 1; j <= logSize; j++)
			for (size_t i = 0; i + (1 << j) <= vec.size(); i++)
				sparseTable[i][j] = std::min(sparseTable[i][j - 1], sparseTable[i + (1 << (j - 1))][j - 1]);
	}

	int query(int a, int b)
	{
		if (a == b)
			return sparseTable[a][0];

		const int log2Length = std::log2(b - a + 1);

		return std::min(sparseTable[a][log2Length], sparseTable[b - (1 << log2Length) + 1][log2Length]);
	}

  private:
	std::vector<std::vector<int>> sparseTable;
};