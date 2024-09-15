#include <bits/stdc++.h>
using namespace std;
using uli = unsigned long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, ans = 0;
  uli k;
  cin >> n >> k;
  vector<uli> sum(n + 1);
  for (size_t i = 0; i < n; i++) cin >> sum[i + 1], sum[i + 1] += sum[i];
  vector<uli>::const_iterator it, jt;
  for (it = sum.begin(), jt = next(sum.begin()); jt != sum.end(); jt++) {
    while (*jt - *it > k) it++;
    ans += (jt - it);
  }
  cout << ans;
  return 0;
}