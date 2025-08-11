#include <vector>

class SegmentDecomposititon
{
  public:
	SegmentDecomposititon(const std::vector<int> &vec, int blockLength) : data(vec), blockLength_(blockLength)
	{
		blocks.resize(vec.size() / blockLength);
		for (int i = 0; i < vec.size(); i++)
			blocks[blockNumber(i)] += vec[i];
	}

	long long query(int l, int r)
	{
		long long res = 0;
		while (l <= r)
		{
			if (l % blockLength_ == 0 and l + blockLength_ - 1 <= r)
			{
				res += blocks[blockNumber(l)];
				l += blockLength_;
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
	constexpr int blockNumber(int pos)
	{
		return pos / blockLength_;
	}

	const int blockLength_;
	std::vector<int> data;
	std::vector<int> blocks;
};