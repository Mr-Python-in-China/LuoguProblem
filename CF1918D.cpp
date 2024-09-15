#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  for (size_t n = 1; n < 100; ++n) {
    map<vector<unsigned char>, vector<uli>> ans;
    for (uli i = ceil(pow(10, n - 1 >> 1)), p = i * i, end = pow(10, n);
         p < end; ++i, p = i * i) {
      vector<unsigned char> c;
      while (p) {
        c.push_back(p % 10);
        p /= 10;
      }
      sort(c.begin(), c.end());
      if (c.front()) ans[c].push_back(i);
    }
    for (auto const i : ans) {
      if (i.second.size() < n) continue;
      cout << n << '-';
      for (unsigned char j : i.first) cout.put(j + '0');
      cout.put(':');
      for (uli j : i.second) cout << j << ' ';
      cout.put('\n');
    }
  }
  return 0;
}