#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  ui m;
  size_t n;
  cin >> m >> n;
  ++m;
  vector<pair<ui, ui>> a(n);
  vector<size_t> ans(n, ~0);
  for (pair<ui, ui>& i : a) cin >> i.first >> i.second;
  {  // 沿 x 轴方向从左到右扫，处理 ➀➁➂
    vector<vector<pair<ui, size_t>>> s(m);
    for (size_t i = 0; i < n; ++i) s[a[i].first].emplace_back(a[i].second, i);
    multimap<ui, size_t> vis;
    for (size_t i = 0; i < m; ++i) {
      for (pair<ui, size_t> const& j : s[i]) {
        // 当前点 x 坐标为 i, y 坐标为 j.first, 编号 j.second
        multimap<ui, size_t>::const_iterator it;
        it = vis.cbegin();  // ➀
        if (it != vis.cend() && it->first < i) ans[j.second] = it->second;
        it = vis.upper_bound(i);  // ➁
        if (it != vis.end() && it->first < j.first) ans[j.second] = it->second;
        it = vis.upper_bound(j.first);  // ➂
        if (it != vis.end()) ans[j.second] = it->second;
      }
      for (pair<ui, size_t> const& j : s[i]) vis.insert(j);
    }
  }
  {  // 沿 y 轴方向从上到下扫，处理 ➂➃➄
    vector<vector<pair<ui, size_t>>> s(m);
    for (size_t i = 0; i < n; ++i) s[a[i].second].emplace_back(a[i].first, i);
    multimap<ui, size_t> vis;
    for (size_t i = m - 1; i < m; --i) {
      for (pair<ui, size_t> const& j : s[i]) {
        // 当前点 x 坐标为 j.first, y 坐标为 i, 编号 j.second
        multimap<ui, size_t>::const_iterator it;
        it = vis.cbegin();  // ➂
        if (it != vis.cend() && it->first < j.first) ans[j.second] = it->second;
        it = vis.upper_bound(j.first);  // ➃
        if (it != vis.end() && it->first < i) ans[j.second] = it->second;
        it = vis.upper_bound(i);  // ➄
        if (it != vis.end()) ans[j.second] = it->second;
      }
      for (pair<ui, size_t> const& j : s[i]) vis.insert(j);
    }
  }
  {  // 沿 y 轴方向从下到上扫，处理 ➅
    vector<vector<pair<ui, size_t>>> s(m);
    for (size_t i = 0; i < n; ++i) s[a[i].second].emplace_back(a[i].first, i);
    multimap<ui, size_t> vis;
    for (size_t i = 0; i < m; ++i) {
      for (pair<ui, size_t> const& j : s[i]) {
        // 当前点 x 坐标为 j.first, y 坐标为 i, 编号 j.second
        multimap<ui, size_t>::const_iterator it;
        it = vis.upper_bound(j.first);  // ➅
        if (it != vis.end()) ans[j.second] = it->second;
      }
      for (pair<ui, size_t> const& j : s[i]) vis.insert(j);
    }
  }
  for (size_t i : ans) cout << i + 1 << ' ';
  return 0;
}