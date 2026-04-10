// for a and b, find k and l such that ak + bl = gcd(a,b)
#include <tuple>

std::tuple<int, int, int> extEuclidean(int a, int b)
{
	if (b == 0)
		return {a, 1, 0};

	const auto [d, k, l] = extEuclidean(b, a % b);
	return {d, l, k - ((a / b) * l)};
}