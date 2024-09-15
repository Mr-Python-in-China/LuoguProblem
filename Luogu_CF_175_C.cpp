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
  deque<pair<uli, uli>> a(n);
  for (pair<uli, uli>& i : a) cin >> i.first >> i.second;
  sort(a.begin(), a.end(),
       [](pair<uli, uli> const& a, pair<uli, uli> const& b) {
         return a.second < b.second;
       });
  size_t t;
  cin >> t;
  deque<uli> p(t);
  for (uli& i : p) cin >> i;
  for (uli i = t - 1, j = i - 1; i < t && j < t; --i, --j) p[i] -= p[j];
  p.push_back(numeric_limits<uli>::max());
  uli ans = 0, d = 1;
  while (!a.empty() && !p.empty()) {
    uli minus = min(a.front().first, p.front());
    a.front().first -= minus, p.front() -= minus;
    ans += (uli)a.front().second * d * minus;
    if (!a.front().first) a.pop_front();
    if (!p.front()) p.pop_front(), ++d;
  }
  cout << ans;
  return 0;
}