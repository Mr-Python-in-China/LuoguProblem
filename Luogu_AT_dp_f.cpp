#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream &fin = cin;
ostream &fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
enum class FROM : unsigned char {
  Nan = (unsigned char)-1,
  ST = 0,
  S = 1,
  T = 2
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  string s, t;
  cin >> s >> t;
  vector<vector<pair<size_t, FROM>>> f(
      s.size() + 1,
      vector<pair<size_t, FROM>>(
          t.size() + 1, {numeric_limits<size_t>::max() / 2, FROM::Nan}));
  for (size_t i = 1; i <= s.size(); ++i)
    for (size_t j = 1; j <= t.size(); ++j) {
      f[i][j] = max<pair<size_t, FROM>>({f[i - 1][j].first, FROM::S},
                                        {f[i][j - 1].first, FROM::T});
      if (s[i - 1] == t[j - 1])
        f[i][j] = max({f[i - 1][j - 1].first + 1, FROM::ST}, f[i][j]);
    }
  vector<char> ans;
  for (size_t i = s.size(), j = t.size(); f[i][j].second != FROM::Nan;)
    f[i][j].second == FROM::S   ? --i
    : f[i][j].second == FROM::T ? --j
                                : (ans.emplace_back(s[--i]), --j);
  for_each(ans.crbegin(), ans.crend(), [](char c) { cout.put(c); });
  return 0;
}