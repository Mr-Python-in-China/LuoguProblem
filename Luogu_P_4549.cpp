#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  int ans;
  cin >> n >> ans;
  while (--n) {
    int a;
    cin >> a;
    a = abs(a);
    ans = __gcd(a, ans);
  }
  cout << ans;
  return 0;
}