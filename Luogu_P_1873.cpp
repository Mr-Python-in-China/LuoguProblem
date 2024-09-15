#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  ui m;
  cin >> n >> m;
  vector<ui> a(n);
  ui l = 0, r = 0;
  for (vector<ui>::reference i : a) cin >> i, r = max(i, r);
  while (l < r) {
    ui mid = (l + r + 1) >> 1;
    ui gn = 0;
    for (vector<ui>::reference i : a)
      if (i > mid)
        if ((gn += i - mid) >= m) break;
    if (gn >= m)
      l = mid;
    else
      r = mid - 1;
  }
  cout << l;
  return 0;
}