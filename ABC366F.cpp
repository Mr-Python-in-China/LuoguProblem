#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream &fin = cin;
ostream &fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, k;
  fin >> n >> k;
  vector<pair<ui, ui>> f(n);
  for (pair<ui, ui> &i : f) fin >> i.first >> i.second;
  sort(f.begin(), f.end(), [](auto const &a, auto const &b) {
    return (a.first - 1) * b.second < (b.first - 1) * a.second;
  });
  vector<uli> g(k + 1, 0);
  g[0] = 1;
  for (pair<ui, ui> const &i : f) {
    vector<uli> h(k + 1, 0);
    h[0] = g[0];
    for (size_t j = 1; j <= k; ++j)
      h[j] = max(g[j], g[j - 1] * i.first + i.second);
    g = h;
  }
  cout << g.back();
  return 0;
}