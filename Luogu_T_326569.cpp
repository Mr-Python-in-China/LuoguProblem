#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
const size_t N = 1e5 + 1;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  ui k;
  cin >> n >> k;
  array<size_t, N> bt;
  fill(bt.begin(), bt.end(), 0);
  for (size_t i = 0; i < n; i++) {
    ui x;
    cin >> x;
    bt[x]++;
  }
  if (k == 0) cout << n - bt[0], exit(0);
  size_t cnt = 0, minx = -1;
  for (size_t i = 0; i < k; i++) cnt += bool(bt[i]), minx = min(minx, bt[i]);
  if (cnt >= k)
    cout << minx;
  else
    cout << 0;
  return 0;
}