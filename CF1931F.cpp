#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using graph = vector<set<size_t>>;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n, k;
    cin >> n >> k;
    if (n == 1) {
      size_t t;
      cin >> t;
      cout << "YES\n";
      continue;
    }
    graph mp(n);
    for (size_t i = 0; i < k; ++i) {
      size_t tt, lst;
      cin >> tt >> lst;
      --lst;
      for (size_t i = 2; i < n; ++i) {
        size_t x;
        cin >> x;
        mp[lst].insert(--x);
        lst = x;
      }
    }
    vector<size_t> indeg(n);
    for (set<size_t> const& i : mp)
      for (size_t j : i) ++indeg[j];
    queue<size_t> q;
    for (size_t i = 0; i < n; ++i)
      if (!indeg[i]) q.push(i);
    while (!q.empty()) {
      size_t p = q.front();
      q.pop();
      for (size_t i : mp[p])
        if (!--indeg[i]) q.push(i);
    }
    cout << (accumulate(indeg.cbegin(), indeg.cend(), uli(0)) ? "NO\n"
                                                              : "YES\n");
  }
  return 0;
}