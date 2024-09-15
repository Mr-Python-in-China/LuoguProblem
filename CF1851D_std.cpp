/**
 *    author:  tourist
 *    created: 25.07.2023 10:40:26
 **/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 1; i < n; i++) { cin >> a[i]; }
    vector<long long> extra;
    vector<int> used(n + 1, 0);
    for (int i = 0; i < n - 1; i++) {
      long long num = a[i + 1] - a[i];
      if (1 <= num && num <= n && !used[num]) {
        used[num] = 1;
      } else {
        extra.push_back(num);
      }
    }
    if (extra.empty()) {
      cout << "YES" << '\n';
      continue;
    }
    if (extra.size() > 1) {
      cout << "NO" << '\n';
      continue;
    }
    vector<int> left;
    for (int i = 1; i <= n; i++) {
      if (!used[i]) { left.push_back(i); }
    }
    if (left.size() == 2 && extra[0] == left[0] + left[1]) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
  return 0;
}
