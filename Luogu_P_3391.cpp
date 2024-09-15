#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
array<ui, size_t(1e5)> buf;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  cin >> n >> m;
  vector<ui> a(n);
  iota(a.begin(), a.end(), 1);
  vector<ui> b(a.rbegin(), a.rend());
  while (m--) {
    size_t l, r;
    cin >> l >> r;
    --l;
    move(a.begin() + l, a.begin() + r, buf.begin());
    move(b.end() - r, b.end() - l, a.begin() + l);
    move(buf.begin(), buf.begin() + (r - l), b.end() - r);
  }
  for (ui i : a) cout << i << ' ';
  return 0;
}