#include <bits/stdc++.h>
using namespace std;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  li lazy = 0;
  cin >> n >> m;
  vector<li> a(n);
  for (li& i : a) cin >> i;
  sort(a.begin(), a.end());
  vector<li> sum(n + 1);
  for (size_t i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i - 1];
  while (m--) {
    char op;
    cin >> op;
    if (op == '1') {
      li x;
      cin >> x;
      lazy += x;
    } else {
      size_t line = lower_bound(a.cbegin(), a.cend(), -lazy) - a.cbegin();
      cout << (sum[n] - sum[line]) + lazy * (n - line) << '\n';
    }
  }
  return 0;
}