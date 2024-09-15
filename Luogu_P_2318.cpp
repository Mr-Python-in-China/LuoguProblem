#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t m;
  ui sz;
  cin >> sz >> m;
  unordered_map<ui, pair<size_t, size_t>> ram;
  ui ans = 0;
  for (size_t t = 0; t < m; t++) {
    size_t p;
    cin >> p;
    ram[p].second = t;
    if (ram[p].first++) {
      ans++;
      continue;
    }
    if (sz) {
      sz--;
      continue;
    }
    unordered_map<ui, pair<size_t, size_t>>::const_iterator minx = ram.cbegin();
    for (unordered_map<ui, pair<size_t, size_t>>::const_iterator it =
             next(minx);
         it != ram.cend(); it++)
      if (it->second < minx->second) minx = it;
    ram.erase(minx);
  }
  cout << ans;
  return 0;
}