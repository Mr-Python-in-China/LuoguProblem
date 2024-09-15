#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned long long int;
using uli = unsigned long long int;
using li = long long int;
template <typename T> T abs_minus(T const& a, T const& b) {
  return max(a, b) - min(a, b);
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n, m;
    cin >> n >> m;
    deque<ui> a(n);
    deque<ui> b(m);
    for (ui& i : a) cin >> i;
    for (ui& i : b) cin >> i;
    sort(a.begin(), a.end(), less<ui>()),
        sort(b.begin(), b.end(), greater<ui>());
    uli ans = 0;
    while (!a.empty()) {
      if (max(abs_minus(a.front(), b.front()), abs_minus(a.front(), b.back())) >
          max(abs_minus(a.back(), b.front()), abs_minus(a.back(), b.back()))) {
        if (abs_minus(a.front(), b.front()) > abs_minus(a.front(), b.back()))
          ans += abs_minus(a.front(), b.front()), b.pop_front();
        else
          ans += abs_minus(a.front(), b.back()), b.pop_back();
        a.pop_front();
      } else {
        if (abs_minus(a.back(), b.front()) > abs_minus(a.back(), b.back()))
          ans += abs_minus(a.back(), b.front()), b.pop_front();
        else
          ans += abs_minus(a.back(), b.back()), b.pop_back();
        a.pop_back();
      }
    }
    cout << ans << '\n';
  }
  return 0;
}