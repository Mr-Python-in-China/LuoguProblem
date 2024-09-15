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
    bool flag = true;
    cin >> n;
    vector<ui> a(n);
    for (size_t i = 0; i < n; i++) cin >> a[i];
    vector<ui> sorted(a);
    sort(sorted.begin(), sorted.end());
    for (size_t i = 0; i < n; i++)
      if ((a[i] & 1) ^ (sorted[i] & 1)) flag = false;
    cout << (flag ? "YES" : "NO") << '\n';
  }
  return 0;
}