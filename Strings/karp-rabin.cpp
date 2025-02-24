#include <string>
#include <vector>
const int d = 31;	   // size of alphabet
const int q = 1e9 + 9; // relatively big prime

std::vector<long long> d_powers;

void prepare(int length)
{
	d_powers.resize(length);
	d_powers[0] = 1;
	for (int i = 1; i < length; i++)
		d_powers[i] = (d_powers[i - 1] * d) % q;
}

long long hash(const std::string &str, int length)
{
	long long h = 0;
	for (int i = 0; i < length; i++)
		h = (h + (str[i] - 'a' + 1) * d_powers[length - i - 1]) % q;
	return h;
}

int karp_rabin(const std::string &pattern, const std::string &text)
{

	const int m = pattern.size();
	const int n = text.size();

	prepare(m);

	long long pattern_hash = hash(pattern, m);
	long long curr_hash = hash(text, m);

	for (int i = 0; i < n - m + 1; i++)
	{
		if (pattern_hash == curr_hash)
			return i;

		curr_hash = (curr_hash - (text[i] - 'a' + 1) * d_powers[m - 1]) % q;
		if (curr_hash < 0)
			curr_hash += q;
		curr_hash = (curr_hash * d + (text[i + m] - 'a' + 1)) % q;
	}

	return -1;
}