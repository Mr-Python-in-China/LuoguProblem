#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  ui b;
  cin >> n >> b;
  vector<ui> a(n);
  for (vector<ui>::reference i : a) cin >> i;
  sort(a.begin(), a.end(), greater<ui>());
  ui high = 0, ans = 0;
  while (high < b) high += a[ans++];
  cout << ans;
  return 0;
}