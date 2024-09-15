#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  ui n, m;
  cin >> n >> m;
  vector<ui> a(n);
  for (vector<ui>::reference i : a) cin >> i;
  while (m--) next_permutation(a.begin(), a.end());
  for (vector<ui>::const_reference i : a) cout << i << ' ';
  return 0;
}