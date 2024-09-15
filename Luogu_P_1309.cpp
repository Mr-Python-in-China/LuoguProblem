#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
struct S {
  size_t p;
  ui s, w;
  friend bool operator<(S const& a, S const& b) {
    return a.s != b.s ? a.s < b.s : a.p < b.p;
  }
  friend bool operator>(S const& a, S const& b) {
    return a.s != b.s ? a.s > b.s : a.p < b.p;
  }
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, r, q;
  cin >> n >> r >> q;
  --q;
  vector<S> a(n * 2);
  for (size_t i = 0; i < n * 2; ++i) a[i].p = i;
  for (S& i : a) cin >> i.s;
  for (S& i : a) cin >> i.w;
  while (r--) {
    sort(a.begin(), a.end(), greater<S>());
    for (size_t i = 0; i < n; ++i)
      ++(a[i * 2].w > a[i * 2 + 1].w ? a[i * 2] : a[i * 2 + 1]).s;
  }
  sort(a.begin(), a.end(), greater<S>());
  cout << a[q].p + 1;
  return 0;
}