#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, q;
  cin >> n >> q;
  vector<bool> a(n, true);
  ui ans = n;
  while (q--) {
    ui x;
    cin >> x;
    --x;
    a[x] ? --ans : ++ans;
    a[x] = !a[x];
  }
  cout << ans;
  return 0;
}