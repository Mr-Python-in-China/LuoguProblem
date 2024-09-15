#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, q;
  cin >> n >> q;
  vector<ui> a(n * n);
  for (ui& i : a) cin >> i;
  sort(a.begin(), a.end());
  while (q--) {
    ui v;
    cin >> v;
    cout << a.cend() - lower_bound(a.cbegin() + n * n - n, a.cend(), v) << '\n';
  }
  return 0;
}