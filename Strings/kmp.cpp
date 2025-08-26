#include <algorithm>
#include <iterator>
#include <string>
#include <vector>

std::vector<int> computePrefixFunction(const std::string &str)
{
	const int n = str.size();
	std::vector<int> pi(n);

	pi[0] = 0;

	for (int i = 1; i < n; i++)
	{
		int j = pi[i - 1];
		while (j > 0 and str[j] not_eq str[i])
			j = pi[j - 1];
		if (str[j] == str[i])
			j++;
		pi[i] = j;
	}

	return pi;
}

int kmp1(const std::string &text, const std::string &pattern)
{
	const auto &pi = computePrefixFunction(pattern + '#' + text);

	const auto it = std::find(pi.cbegin(), pi.cend(), pattern.size());

	if (it not_eq pi.cend())
		return std::distance(pi.cbegin(), it) - 2 * pattern.size();

	return -1;
}

int kmp2(const std::string &text, const std::string &pattern)
{
	const int n = text.size();
	const int m = pattern.size();

	const auto &pi = computePrefixFunction(pattern);

	int j = 0;

	for (int i = 0; i < n; i++)
	{
		while (j > 0 and pattern[j] not_eq text[i])
			j = pi[j - 1];
		if (pattern[j] == text[i])
			j++;
		if (j == m)
			return i - m + 1;
	}

	return -1;
}