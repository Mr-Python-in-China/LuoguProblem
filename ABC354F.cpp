#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
vector<ui> lcs1(vector<ui> const &a) {
  vector<ui> city;
  vector<ui> f;
  for (ui i : a) {
    vector<ui>::iterator it = lower_bound(city.begin(), city.end(), i);
    f.emplace_back(it - city.begin() + 1);
    if (it == city.end())
      city.emplace_back(i);
    else
      *it = i;
  }
  return f;
}
vector<ui> lcs2(vector<ui> const &a) {
  vector<ui> city;
  vector<ui> f;
  for (ui i : a) {
    vector<ui>::iterator it = upper_bound(city.begin(), city.end(), i);
    f.emplace_back(it - city.begin() + 1);
    if (it == city.end())
      city.emplace_back(i);
    else
      *it = i;
  }
  return f;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n;
    cin >> n;
    vector<ui> a(n);
    for (ui &i : a) cin >> i;
    size_t l = [](vector<ui> const &a) {
      return *max_element(a.begin(), a.end());
    }(lcs1(a));
    vector<ui> s = lcs1(a), t = lcs1([](vector<ui> b) {
                              reverse(b.begin(), b.end());
                              for (ui &i : b) i = -i;
                              return b;
                            }(a));
    reverse(t.begin(), t.end());
    vector<size_t> ans;
    for (size_t i = 0; i < n; ++i)
      if (s[i] + t[i] == l + 1) ans.emplace_back(i);
    cout << ans.size() << '\n';
    for (size_t i : ans) cout << i + 1 << ' ';
    cout << '\n';
  }
  return 0;
}