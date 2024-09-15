#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t q;
  cin >> q;
  while (q--) {
    ui x;
    unsigned long long int ans = 0;
    cin >> x;
    while (x != 1) x = (x & 1 ? (x << 1) + x + 1 : x >> 1), ans++;
    cout << ans << '\n';
  }
  return 0;
}