// Couldn't really extract only some parts of this program, because the
// "structure", reading the queries, sorting the queries ect. all are important

// This specific program implements MO's algorithm to count how many numbers x
// are there in an interval such that count[x] == x

#include <algorithm>
#include <iostream>
#include <unordered_map>
using std::cin, std::cout;

const int MAX_N = 1e5 + 7;
const int MAX_Q = 1e5 + 7;
const int B = 316; // ~sqrt(1e5)

int tab[MAX_N];

using Query = std::pair<int, int>;

Query queries[MAX_Q];
int queryOrder[MAX_Q];
int answers[MAX_Q];

// ------- Any good structure --------
int goodCount = 0;
std::unordered_map<int, int> count;

void add(int pos) {
  int val = tab[pos];

  if (count[val] == val)
    goodCount--;

  count[val]++;

  if (count[val] == val)
    goodCount++;
}

void remove(int pos) {
  int val = tab[pos];

  if (count[val] == val)
    goodCount--;

  count[val]--;

  if (count[val] == val)
    goodCount++;
}

int get_answer() { return goodCount; }
// --------------------

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  for (int i = 1; i <= n; i++)
    cin >> tab[i];

  int p, k;
  for (int i = 0; i < q; i++) {
    cin >> p >> k;
    queries[i] = std::make_pair(p, k);
    queryOrder[i] = i;
  }

  // [MO] sorting queries
  std::sort(queryOrder, queryOrder + q, [&](int a, int b) {
    int ba = queries[a].first / B;
    int bb = queries[b].first / B;
    if (ba == bb)
      return queries[a].second < queries[b].second;
    return ba < bb;
  });

  // iterating through intervals
  int l = 1;
  int r = 0;
  for (int i = 0; i < q; i++) {
    int queryNum = queryOrder[i];
    const Query &currentQuery = queries[queryNum];

    while (l > currentQuery.first) {
      l--;
      add(l);
    }
    while (r < currentQuery.second) {
      r++;
      add(r);
    }
    while (l < currentQuery.first) {
      remove(l);
      l++;
    }
    while (r > currentQuery.second) {
      remove(r);
      r--;
    }

    answers[queryNum] = get_answer();
  }

  for (int i = 0; i < q; i++)
    cout << answers[i] << '\n';

  return 0;
}
