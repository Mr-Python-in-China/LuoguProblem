#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, p;
  cin >> n;
  vector<char> s(n);
  for (size_t i = 0; i < n; i++) cin >> s[i];
  vector<char> sorted(s);
  sort(sorted.begin(), sorted.end());
  cin >> p;
  --p;
  vector<char> ans;
  size_t np;
  for (np = 0; np < n; ++np)
    if (sorted[np] == s[p]) {
      sorted[np] = '#';
      break;
    }
  ans.push_back(s[np]);
  for (size_t i = 1; i < n; ++i)
    for (size_t j = n - 1; j < n; --j)
      if (sorted[j] == s[np]) {
        np = j;
        ans.push_back(s[np]);
        sorted[j] = '#';
        break;
      }
  for_each(ans.rbegin(), ans.rend(),
           [](char const& c) -> void { cout.put(c); });
  return 0;
}
