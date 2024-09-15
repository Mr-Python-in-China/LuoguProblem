#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m, l;
  cin >> n;
  vector<ui> a(n);
  for (ui& i : a) cin >> i;
  cin >> m;
  vector<ui> b(m);
  for (ui& i : b) cin >> i;
  cin >> l;
  vector<ui> c(l);
  for (ui& i : c) cin >> i;
  static bitset<size_t(3e8 + 1)> t;
  for (ui i : a)
    for (ui j : b)
      for (ui k : c) t[i + j + k] = true;
  size_t q;
  cin >> q;
  while (q--) {
    ui x;
    cin >> x;
    cout << (t[x] ? "Yes\n" : "No\n");
  }
  return 0;
}