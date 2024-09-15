#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
int main(void) {
  // ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
  array<pair<vector<ui>, vector<ui>>, 10001> arr;
  size_t l, r;
  ui h;
  while (cin >> l >> h >> r)
    arr[l].first.push_back(h), arr[r].second.push_back(h);
  multiset<int> buildings;
  ui lst = 0;
  for (size_t i = 0; i < 10001; i++) {
    for (const ui& j : arr[i].first) buildings.insert(j);
    for (const ui& j : arr[i].second) buildings.erase(j);
    const ui now = (buildings.empty() ? 0 : *buildings.crbegin());
    if (now != lst) cout << i << ' ' << (lst = now) << ' ';
  }
  return 0;
}