#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using graph = vector<list<ui>>;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  ui n;
  cin >> n;
  graph mp(n);
  for (list<ui>& i : mp) {
    ui k;
    cin >> k;
    for (ui j = 0; j < k; j++) {
      ui x;
      cin >> x;
      i.push_back(--x);
    }
  }
  queue<ui, list<ui>> q({0});
  ui ans = 0;
  vector<bool> vis(n, true);
  while (!q.empty()) {
    ui p = q.front();
    q.pop();
    ++ans;
    for (ui const& i : mp[p])
      if (vis[i]) q.push(i), vis[i] = false;
  }
  cout << ans;
  return 0;
}