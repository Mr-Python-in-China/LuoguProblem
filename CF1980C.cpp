#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n;
    cin >> n;
    vector<ui> a(n), b(n);
    for (ui &i : a) cin >> i;
    for (ui &i : b) cin >> i;
    size_t m;
    cin >> m;
    vector<ui> d(m);
    for (ui &i : d) cin >> i;
    map<ui, pair<size_t, size_t>> p;
    for (size_t i = 0; i < n; ++i) {
      if (a[i] != b[i]) ++p[b[i]].first;
      p[b[i]].second = true;
    }
    size_t unknown = 0;
    for (ui i : d) {
      if (p[i].first)
        --p[i].first, unknown = 0;
      else if (p[i].second)
        unknown = 0;
      else
        ++unknown;
    }
    if (count_if(p.begin(), p.end(), [](auto x) { return x.second.first; }) ||
        unknown)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}