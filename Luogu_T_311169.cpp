#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  ui T;
  cin >> T;
  while (T--) {
    ui x;
    cin >> x;
    cout << (x & 1 ? "Yes" : "No") << '\n';
  }
  return 0;
}