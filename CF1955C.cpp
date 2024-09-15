#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n;
    uli k;
    cin >> n >> k;
    deque<ui> a(n);
    for (ui& i : a) cin >> i;
    while (a.size() > 1 && k > 1) {
      ui d = min(a.front(), a.back());
      if (d * 2 > k) d = k / 2;
      a.front() -= d, a.back() -= d, k -= d * 2;
      if (!a.empty() && a.front() == 0) a.pop_front();
      if (!a.empty() && a.back() == 0) a.pop_back();
    }
    if (a.size() == 1) {
      ui d = min<uli>(a.front(), k);
      a.front() -= d, k -= d;
      if (!a.empty() && a.front() == 0) a.pop_front();
    }
    if (k && !a.empty()) {
      --a.front();
      if (a.front() == 0) a.pop_front();
    }
    cout << n - a.size() << '\n';
  }
  return 0;
}