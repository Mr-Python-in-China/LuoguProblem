#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n;
    cin >> n;
    vector<bool> vis(n);
    for (size_t i = 0; i < n; i++)
      if (!vis[i])
        for (size_t j = i + 1; j <= n; j <<= 1)
          vis[j - 1] = true, cout << j << ' ';
    cout << '\n';
  }
  return 0;
}