#include <bits/stdc++.h>
using namespace std;
using uli = unsigned long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  uli k;
  cin >> n >> k;
  vector<uli> a(n);
  for (uli& i : a) cin >> i;
  sort(a.begin(), a.end());
  vector<uli> l(n), r(n);
  l[0] = r[n - 1] = 1;
  for (size_t li = 0, ri = 1; ri < n; ri++) {
    while (a[ri] - a[li] > k) li++;
    l[ri] = max<uli>(l[ri - 1], ri - li + 1);
  }
  for (size_t ri = n - 1, li = n - 2; li < n; li--) {
    while (a[ri] - a[li] > k) ri--;
    r[li] = max<uli>(r[li + 1], ri - li + 1);
  }
  // for (size_t i=0;i<n;i++) cout<<l[i]<<' ';
  // cout<<'\n';
  // for (size_t i=0;i<n;i++) cout<<r[i]<<' ';
  // cout<<'\n';
  uli ans = 0;
  for (size_t i = 0; i < n - 1; i++) ans = max(ans, l[i] + r[i + 1]);
  cout << ans;
  return 0;
}