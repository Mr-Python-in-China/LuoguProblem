#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  uli m;
  cin >> n >> m;
  vector<pair<ui, ui>> a(n);
  for (pair<ui, ui>& i : a) cin >> i.first >> i.second;
  vector<pair<ui, ui>>::const_iterator it = a.cbegin(), jt = a.cbegin();
  uli s = 0;
  deque<vector<pair<ui, ui>>::const_iterator> q;
  ui ans = numeric_limits<ui>::max();
  for (; it < a.cend(); ++it) {
    while (jt < a.cend() && s < m) {
      s += jt->first;
      while (!q.empty() && q.back()->second <= jt->second) q.pop_back();
      q.push_back(jt);
      ++jt;
    }
    if (s < m) break;
    ans = min(ans, q.front()->second);
    if (q.front() == it) q.pop_front();
    s -= it->first;
  }
  cout << ans;
  return 0;
}