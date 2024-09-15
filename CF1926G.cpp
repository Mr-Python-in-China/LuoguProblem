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
    size_t n;
    cin >> n;
    vector<vector<size_t>> mp(n);
    for (size_t i = 1; i < n; ++i) {
      size_t p;
      cin >> p;
      --p;
      mp[p].push_back(i), mp[i].push_back(p);
    }
    vector<char> t(n);
    for (char& i : t) cin >> i;
    size_t ans = 0;
    queue<size_t> q;

    for (size_t i = 0; i < n; ++i)
      if (t[i] == 'C' && find_if(mp[i].begin(), mp[i].end(), [&](size_t x) {
                           return t[x] != 'C';
                         }) != mp[i].end())
        q.push(i);
    while (!q.empty()) {}

    cout << ans << '\n';
  }
  return 0;
}