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
    vector<vector<size_t>> mp(n * 2);
    for (size_t i = 0; i < n; ++i) {
      char c;
      cin >> c;
      if (c == '>' && i < n - 1) {
        if (i > 0) mp[i - 1].emplace_back(i + 1);
        mp[i + 1].emplace_back(i + 1);
        mp[i + n].emplace_back(i + 1);
      } else if (c == '<' && i > 0) {
        if (i < n - 1) mp[i + 1].emplace_back(i - 1);
        mp[i - 1].emplace_back(i - 1);
        mp[i + n].emplace_back(i - 1);
      }
    }
    for (size_t i = 0; i < n; ++i) {
      char c;
      cin >> c;
      if (c == '>' && i < n - 1) {
        if (i > 0) mp[i - 1 + n].emplace_back(i + 1 + n);
        mp[i + 1 + n].emplace_back(i + 1 + n);
        mp[i].emplace_back(i + 1 + n);
      } else if (c == '<' && i > 0) {
        if (i < n - 1) mp[i + 1 + n].emplace_back(i - 1 + n);
        mp[i - 1 + n].emplace_back(i - 1 + n);
        mp[i].emplace_back(i - 1 + n);
      }
    }
    vector<bool> vis(n * 2);
    vis[0] = true;
    queue<size_t> q({0});
    while (!q.empty()) {
      size_t p = q.front();
      q.pop();
      for (size_t i : mp[p])
        if (!vis[i]) vis[i] = true, q.push(i);
    }
    cout << (vis.back() ? "YES\n" : "NO\n");
  }
  return 0;
}