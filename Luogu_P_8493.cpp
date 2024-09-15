#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
constexpr ui P = 1'000'002'022;
struct Solution {
  vector<bool> status;
  size_t n, m;
  vector<vector<size_t>> tree;
  Solution(vector<size_t> fa, vector<bool> _status)
      : status(_status),
        n(fa.size() - status.size()),
        m(status.size()),
        tree(n) {
    for (size_t i = 1; i < n + m; ++i) tree[fa[i]].emplace_back(i);
  }
  Solution() = default;
  ui operator()(size_t l, size_t r) {
    l -= n, r -= n;
    for (size_t i = l; i < r; ++i) status[i] = !status[i];
    vector<pair<ui, ui>> f(n + m);
    for (size_t i = 0; i < m; ++i)
      f[i + n] = status[i] ? make_pair(1u, 0u) : make_pair(0u, 1u);
    for (size_t p = n - 1; p < n; --p) {
      vector<ui> g(tree[p].size() + 1, 0);
      g[0] = 1;
      for (size_t son : tree[p]) {
        for (ui i = g.size() - 1; i > 0; --i)
          g[i] = ((uli)g[i] * f[son].second + (uli)g[i - 1] * f[son].first) % P;
        g[0] = ((uli)g[0] * f[son].second) % P;
      }
      for (ui i = 0; i <= tree[p].size(); ++i) {
        f[p].first = (f[p].first + (uli)g[i] * i) % P;
        f[p].second = (f[p].second + (uli)g[i] * (tree[p].size() - i)) % P;
      }
    }
    return f[0].first;
  }
};
Solution solution;
void init(int N, int M, std::vector<int> S, std::vector<int> A) {
  solution = Solution(vector<size_t>(S.begin(), S.end()),
                      vector<bool>(A.begin(), A.end()));
}
int count_ways(int L, int R) { return solution(L, R + 1); }

#ifndef ONLINE_JUDGE
#include <cassert>
#include <cstdio>
#include <vector>
int main() {
  int N, M, Q;
  assert(3 == scanf("%d %d %d", &N, &M, &Q));
  std::vector<int> S(N + M), A(M);
  for (int i = 0; i < N + M; ++i) { assert(1 == scanf("%d", &S[i])); }
  for (int j = 0; j < M; ++j) { assert(1 == scanf("%d", &A[j])); }
  init(N, M, S, A);

  for (int i = 0; i < Q; ++i) {
    int L, R;
    assert(2 == scanf("%d %d", &L, &R));
    printf("%d\n", count_ways(L, R));
  }
  return 0;
}
#endif