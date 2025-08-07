// for a and b, find k and l such that ak + bl = gcd(a,b)
#include <tuple>
using triple = std::tuple<int, int, int>;

triple ext_euclidean(int a, int b)
{
	if (b == 0)
		return {a, 1, 0};

	const auto [d, k, l] = ext_euclidean(b, a % b);
	return {d, l, k - (a / b) * l};
}