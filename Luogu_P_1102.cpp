#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  ui n, c;
  unsigned long long int ans = 0;
  cin >> n >> c;
  vector<ui> a(n);
  for (vector<ui>::reference i : a) cin >> i;
  sort(a.begin(), a.end());
  for (vector<ui>::iterator it = a.begin(); it != a.end(); it++)
    if (*it >= c)
      ans += upper_bound(a.begin(), it, (*it) - c) -
             lower_bound(a.begin(), it, (*it) - c);
  cout << ans;
  return 0;
}