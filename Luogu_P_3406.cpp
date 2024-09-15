#include <bits/stdc++.h>
using namespace std;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  cin >> n >> m;
  vector<li> dif_cnt(n + 1);
  {
    size_t lst;
    cin >> lst;
    while (--m) {
      size_t x;
      cin >> x;
      dif_cnt[min(lst, x)]++, dif_cnt[max(lst, x)]--;
      lst = x;
    }
  }
  vector<li> cnt(n);
  for (size_t i = 1; i < n; i++) cnt[i] = cnt[i - 1] + dif_cnt[i];
  li ans = 0;
  for (size_t i = 1; i < n; i++) {
    li a, b, c;
    cin >> a >> b >> c;
    ans += min(a * cnt[i], c + b * cnt[i]);
  }
  cout << ans;
  return 0;
}