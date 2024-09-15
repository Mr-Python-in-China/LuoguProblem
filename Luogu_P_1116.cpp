#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  vector<ui> a(n);
  ui ans = 0;
  for (vector<ui>::reference i : a) cin >> i;
  for (vector<ui>::const_iterator it = a.begin(); it < a.end(); it++)
    for (vector<ui>::const_iterator jt = a.begin(); jt < it; jt++)
      ans += *it < *jt;
  cout << ans;
  return 0;
}