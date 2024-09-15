#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using ulli = __int128_t;
constexpr uli P = 1000000000000002493;
const ulli BASE = [] {
  random_device rd;
  return uniform_int_distribution<ui>(26, 154)(rd);
  // return 133;
}();
ulli pow_base(size_t x) {
  static array<uli, size_t(2e5 + 1)> mem = {};
  if (mem.at(x)) return mem.at(x);
  if (x == 0) return mem.at(x) = 1;
  return mem.at(x) = pow_base(x - 1) * BASE % P;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  cerr << ui(BASE) << '\n';
  size_t T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    if (count(s.cbegin(), s.cend(), 'a') == s.size()) {
      cout << s.size() - 1 << '\n';
      continue;
    }
    array<vector<size_t>, 26> alphas;
    for (size_t i = 0; i < s.size(); ++i)
      alphas.at(s.at(i) - 'a').emplace_back(i);
    vector<uli> hash = {0};
    for (char i : s) hash.emplace_back((hash.back() * BASE + (i - 'a')) % P);
    array<size_t, 25> checked_len = {0};
    size_t ans = 0;
    for (size_t i = 0; i < s.size(); ++i) {
      char header = s.at(i);
      if (header != 'a')
        for (size_t &len = ++checked_len.at(header - 'a' - 1);
             i + len <= s.size(); ++len) {
          uli except =
              ulli(hash.at(i + len) + P - hash.at(i) * pow_base(len) % P) % P;
          size_t lst = 0;
          auto jump = [&alphas, &header](size_t p) {
            auto it = lower_bound(alphas.at(header - 'a').cbegin(),
                                  alphas.at(header - 'a').cend(), p);
            if (it == alphas.at(header - 'a').cend())
              return size_t(1e9);
            else
              return *it;
          };
          vector<size_t> ps;
          for (size_t p = jump(lst); p + len <= s.size(); p = jump(lst)) {
            if (hash.at(p) -
                hash.at(lst) * pow_base(p - lst) % P)  // 中间不全为 'a'
              goto failed;
            uli h =
                ulli(hash.at(p + len) + P - hash.at(p) * pow_base(len) % P) % P;
            if (h != except) goto failed;
            ps.emplace_back(p);
            lst = p + len;
          }
          if (hash.at(s.size()) - hash.at(lst) * pow_base(s.size() - lst) % P)
            goto failed;
          if (ps.empty()) throw;
          {
            size_t d = ps.front();
            for (vector<size_t>::iterator it = ps.begin(), jt = next(it);
                 jt < ps.end(); ++it, ++jt)
              d = min(d, *jt - *it - len);
            ans += d + 1;
          }
        failed:;
        }
    }
    cout << ans << '\n';
  }
  return 0;
}