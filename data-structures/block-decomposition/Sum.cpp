#include <vector>

class BlockDecomposition
{
  public:
	BlockDecomposition(const std::vector<int> &vec, int blockLength) : data(vec), blockLength(blockLength)
	{
		blocks.resize(vec.size() / blockLength);
		for (int i = 0; i < vec.size(); i++)
			blocks[blockNumber(i)] += vec[i];
	}

	int query(int l, int r)
	{
		int res = 0;
		while (l <= r)
		{
			if (l % blockLength == 0 and l + blockLength - 1 <= r)
			{
				res += blocks[blockNumber(l)];
				l += blockLength;
			}
			else
				res += data[l++];
		}
		return res;
	}

	void update(int pos, int val)
	{
		int old = data[pos];
		data[pos] = val;
		blocks[blockNumber(pos)] += val - old;
	}

  private:
	constexpr int blockNumber(int pos) const
	{
		return pos / blockLength;
	}

	int blockLength;
	std::vector<int> data;
	std::vector<int> blocks;
};