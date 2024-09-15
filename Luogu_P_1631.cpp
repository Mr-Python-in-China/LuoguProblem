#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  vector<ui> a(n), b(n);
  for (ui &i : a) cin >> i;
  for (ui &i : b) cin >> i;
  sort(b.begin(), b.end());
  priority_queue<pair<uli, size_t>, vector<pair<uli, size_t>>,
                 greater<pair<uli, size_t>>>
      q;
  for (size_t i = 0; i < n; ++i) q.emplace(a[i] + b[0], 0);
  for (size_t i = 0; i < n; ++i) {
    auto p = q.top();
    q.pop();
    cout << p.first << ' ';
    if (p.second + 1 < n)
      q.emplace(p.first - b[p.second] + b[p.second + 1], p.second + 1);
  }
  return 0;
}