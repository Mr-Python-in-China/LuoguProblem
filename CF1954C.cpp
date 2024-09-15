#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    string s, t;
    cin >> s >> t;
    size_t n = s.size();
    if (s < t) swap(s, t);
    size_t i = 0;
    for (; i < n && s[i] == t[i]; ++i);
    for (++i; i < n; ++i)
      if (s[i] > t[i]) swap(s[i], t[i]);
    cout << s << '\n' << t << '\n';
  }
  return 0;
}