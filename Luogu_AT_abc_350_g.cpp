#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  cin >> n >> m;
  vector<vector<size_t>> mp(n);
  ui l = 0;
  while (m--) {
    bool t = [l, n] {
      uli x;
      cin >> x;
      return 1 + ((x * (1 + l)) % 998244353) % 2;
    }() - 1;
    size_t a =
               [l, n] {
                 uli x;
                 cin >> x;
                 return 1 + ((x * (1 + l)) % 998244353) % n;
               }() -
               1,
           b =
               [l, n] {
                 uli x;
                 cin >> x;
                 return 1 + ((x * (1 + l)) % 998244353) % n;
               }() -
               1;
    if (t == 0)
      mp[a].emplace_back(b), mp[b].emplace_back(a);
    else {
      vector<bool> s(n);
      for (size_t i : mp[a]) s[i] = true;
      for (size_t i : mp[b])
        if (s[i]) {
          l = i + 1, cout << i + 1 << '\n';
          goto over;
        }
      l = 0, cout << "0\n";
    over:;
    }
  }
  return 0;
}