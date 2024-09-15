#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, l, r;
  cin >> n >> l >> r;
  ++n;
  vector<short> a(n);
  for (short& i : a) cin >> i;
  vector<size_t> window_max(n);
  vector<int> f(n, numeric_limits<int>::min());
  f[0] = a[0];
  size_t window_lengh = r - l + 1;
  deque<size_t> q({0});
  for (size_t i = 1; i < n; ++i) {
    if (i >= l && f[window_max[i - l]] != numeric_limits<int>::min())
      f[i] = f[window_max[i - l]] + a[i];

    if (q.size() >= window_lengh) q.pop_front();
    while (!q.empty() && f[q.back()] < f[i]) q.pop_back();
    q.push_back(i);
    window_max[i] = q.front();
  }
  cout << *max_element(f.begin() + (n - r), f.end());
  return 0;
}