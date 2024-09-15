#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream& fin = cin;
ostream& fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  string s, t;
  fin >> s >> t;
  size_t n = s.size();
  vector<string> ans;
  for (size_t i = 0; i < n; ++i)
    if (s[i] > t[i]) {
      s[i] = t[i];
      ans.emplace_back(s);
    }
  for (size_t i = n - 1; i < n; --i)
    if (s[i] < t[i]) {
      s[i] = t[i];
      ans.emplace_back(s);
    }
  fout << ans.size() << '\n';
  for (string const& i : ans) fout << i << '\n';
  return 0;
}