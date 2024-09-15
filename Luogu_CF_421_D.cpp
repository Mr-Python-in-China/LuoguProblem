#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  ui p;
  cin >> n >> p;
  vector<pair<ui, size_t>> cnt(n);
  for (size_t i = 0; i < n; ++i) cnt[i].second = i;
  vector<pair<size_t, size_t>> inp(n);
  for (pair<size_t, size_t>& i : inp)
    cin >> i.first >> i.second, ++cnt[i.first].first, ++cnt[i.second].first;
  sort(cnt.begin(), cnt.end());
  vector<size_t> f(n);
  for (size_t i = 0; i < n; ++i) f[cnt[i].second] = i;
  uli ans = 0;
  vector<ui> t(n);
  for (pair<size_t, size_t>& i : inp) {
    i = {f[i.first], f[i.second]};
    if (i.first > i.second) swap(i.first, i.second);
    ++t[i.first];
  }
  for (size_t i = 0; i < n; ++i) {
    vector<pair<ui, size_t>>::iterator it =
        lower_bound(cnt.begin() + i + 1, cnt.end(), p - cnt[i].first,
                    [](pair<ui, size_t> x, ui a) { return x.first < a; });
    ans += (cnt.end() - it >= t[i] ? cnt.end() - it - t[i] : 0);
  }
  cout << ans;
  return 0;
}