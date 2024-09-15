#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
struct pos {
  int x, y;
  int val1(void) const { return x; }
  int val2(void) const { return y; }
  int val3(void) const { return x - y; }
  int val4(void) const { return x + y; }
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n;
    cin >> n;
    vector<pos> a(n);
    for (pos& i : a) cin >> i.x >> i.y;
    vector<pos> b(a), c(a), d(a);
    sort(a.begin(), a.end(),
         [](pos const& a, pos const& b) { return a.val1() < b.val1(); });
    sort(b.begin(), b.end(),
         [](pos const& a, pos const& b) { return a.val2() < b.val2(); });
    sort(c.begin(), c.end(),
         [](pos const& a, pos const& b) { return a.val3() < b.val3(); });
    sort(d.begin(), d.end(),
         [](pos const& a, pos const& b) { return a.val4() < b.val4(); });
#ifdef debug
    cout << "a:\n";
    for (pos const& i : a) cout << ' ' << i.x << ' ' << i.y << '\n';
    cout << "b:\n";
    for (pos const& i : b) cout << ' ' << i.x << ' ' << i.y << '\n';
    cout << "c:\n";
    for (pos const& i : c) cout << ' ' << i.x << ' ' << i.y << '\n';
    cout << "d:\n";
    for (pos const& i : d) cout << ' ' << i.x << ' ' << i.y << '\n';
#endif
    unsigned long long int ans = 0;
    {
      unsigned long long int cnt = 1;
      for (size_t i = 1; i < n; i++)
        if (a[i].val1() == a[i - 1].val1())
          cnt++;
        else
          ans += (cnt - 1) * cnt, cnt = 1;
      ans += (cnt - 1) * cnt;
#ifdef debug
      cout << ans << ',';
#endif
    }
    {
      unsigned long long int cnt = 1;
      for (size_t i = 1; i < n; i++)
        if (b[i].val2() == b[i - 1].val2())
          cnt++;
        else
          ans += (cnt - 1) * cnt, cnt = 1;
      ans += (cnt - 1) * cnt;
#ifdef debug
      cout << ans << ',';
#endif
    }
    {
      unsigned long long int cnt = 1;
      for (size_t i = 1; i < n; i++)
        if (c[i].val3() == c[i - 1].val3())
          cnt++;
        else
          ans += (cnt - 1) * cnt, cnt = 1;
      ans += (cnt - 1) * cnt;
#ifdef debug
      cout << ans << ',';
#endif
    }
    {
      unsigned long long int cnt = 1;
      for (size_t i = 1; i < n; i++)
        if (d[i].val4() == d[i - 1].val4())
          cnt++;
        else
          ans += (cnt - 1) * cnt, cnt = 1;
      ans += (cnt - 1) * cnt;
#ifdef debug
      cout << ans << ',';
#endif
    }
    cout << ans << '\n';
  }
  return 0;
}