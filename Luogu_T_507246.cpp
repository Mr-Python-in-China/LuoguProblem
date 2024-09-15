#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream& fin = cin;
ostream& fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using ulli = __uint128_t;
using li = long long int;
constexpr ui BASE = 26;
constexpr uli P = 1000000000000000009;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  string s, x;
  fin >> s >> x;
  for (char i : x) s = s + i + s;
  vector<uli> hash(s.size() + 1), basePow(s.size() + 1);
  basePow[0] = 1;
  for (size_t i = 0; i < s.size(); ++i) {
    basePow[i + 1] = (ulli)basePow[i] * BASE % P;
    hash[i + 1] = (hash[i] + ulli(s[i] - 'a') * basePow[i]) % P;
  }
  size_t Q;
  fin >> Q;
  while (Q--) {
    string t;
    fin >> t;
    uli h = 0;
    for (size_t i = 0; i < t.size(); ++i)
      h = (h + ulli(t[i] - 'a') * basePow[i]) % P;
    ui ans = 0;
    for (size_t i = 0, j = t.size(); j <= s.size(); ++i, ++j) {
      uli tmp = hash[j] - hash[i] + P;
      if (tmp >= P) tmp -= P;
      if (tmp == h) ++ans;
      h = (ulli)h * BASE % P;
    }
    fout << ans << '\n';
  }
  return 0;
}