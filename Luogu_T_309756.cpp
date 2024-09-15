#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  ui n, m;
  cin >> n >> m;
  vector<ui> a(n);
  for (vector<ui>::reference i : a) cin >> i;
  sort(a.begin(), a.end());
  ui s = 0x7fffffff;
  for (vector<ui>::iterator it = a.begin(), jt = it + m; jt != a.end();
       it++, jt++)
    s = min(s, *(jt - 1) - *it);
  cout << s;
  return 0;
}