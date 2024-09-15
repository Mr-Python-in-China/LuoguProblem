#include <bits/stdc++.h>

#include <tr2/dynamic_bitset>
using namespace std;
istream &fin = cin;
ostream &fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
string input_rev_string() {
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  return s;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t q;
  string s, t;
  cin >> s >> t >> q;
  vector<bool> a(s.size()), b(t.size());
  transform(s.begin(), s.end(), a.begin(), [](char c) { return c == '1'; });
  transform(t.begin(), t.end(), b.begin(), [](char c) { return c == '1'; });
  vector<uli> f, g;
  for (size_t i = 0; i + 64 <= a.size(); ++i)
    f.emplace_back(stoull(string(s.begin() + i, s.begin() + i + 64), 0, 2));
  for (size_t i = 0; i + 64 <= b.size(); ++i)
    g.emplace_back(stoull(string(t.begin() + i, t.begin() + i + 64), 0, 2));
  while (q--) {
    size_t x, y, l;
    cin >> x >> y >> l;
    ui ans = 0;
    size_t i = 0;
    for (; i + 64 <= l; i += 64)
      ans += __builtin_popcountll(f[x + i] ^ g[y + i]);
    for (; i < l; ++i) ans += a[x + i] != b[y + i];
    cout << ans << '\n';
  }
  return 0;
}