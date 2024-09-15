#include <iostream>
using namespace std;
int main(void) {
  int n, len = 1;
  long long ans = 0;
  cin >> n;
  int lst;
  cin >> lst;
  for (int i = 1; i < n; i++) {
    int now;
    cin >> now;
    if (lst <= now) {
      ans += (long long)len * (len + 1) / 2;
      len = 0;
    }
    len++, lst = now;
  }
  ans += (long long)len * (len + 1) / 2;
  cout << ans;
  return 0;
}