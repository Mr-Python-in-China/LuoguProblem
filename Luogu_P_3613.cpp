#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  ui n, q;
  cin >> n >> q;
  vector<map<ui, ui>> a(n);
  while (q--) {
    char c;
    cin >> c;
    if (c == '1') {
      ui i, j, k;
      cin >> i >> j >> k;
      a[--i][--j] = k;
    } else {
      ui i, j;
      cin >> i >> j;
      cout << a[--i][--j] << '\n';
    }
  }
  return 0;
}