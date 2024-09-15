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
    ui k;
    cin >> n >> k;
    vector<ui> a(n);
    vector<bool> vis(k, 0);
    for (ui& i : a) cin >> i, vis[--i] = true;
    vector<size_t> first(k, -1), last(k, 0);
    for (size_t i = 0; i < n; ++i) {
      if (!~first[a[i]]) first[a[i]] = i;
      last[a[i]] = i;
    }
    for (size_t i = k - 1; i > 0; --i)
      first[i - 1] = min(first[i], first[i - 1]),
                last[i - 1] = max(last[i], last[i - 1]);
    for (ui i = 0; i < k; ++i)
      cout << vis[i] * ((last[i] - first[i] + 1) << 1) << ' ';
    cout.put('\n');
  }
  return 0;
}