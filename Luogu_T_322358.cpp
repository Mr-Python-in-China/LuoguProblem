#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  ui m, sum = 0;
  cin >> n >> m;
  for (size_t i = 0; i < n; i++) {
    ui x;
    cin >> x;
    if (m >= x) m -= x, sum += x;
  }
  cout << sum - ui(sum * 0.88);
  return 0;
}