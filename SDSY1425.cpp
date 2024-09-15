#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
namespace IO {
const size_t MAXSIZE = 1 << 20;
char buf[MAXSIZE], *p1, *p2;
#define gc()                                                               \
  (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin), p1 == p2) \
       ? EOF                                                               \
       : *p1++)

ui rd() {
  ui x = 0;
  char c = gc();
  while (!isdigit(c)) { c = gc(); }
  while (isdigit(c)) x = x * 10 + (c ^ 48), c = gc();
  return x;
}
#undef gc
}  // namespace IO
int main(void) {
  size_t n = IO::rd();
  vector<ui> a(n);
  for (ui& i : a) i = IO::rd() - 1;
  size_t ans = 0;
  for (size_t i = 0; i < n; ++i)
    if (a[i] == 0) {
      size_t invl = i, invr = i;
      --invl;
      while (invl < n && a[invl] != 0) --invl;
      ++invl;
      ++invr;
      while (invr < n && a[invr] != 0) ++invr;
      --invr;
      vector<size_t> p(invr - invl + 1, ~0);
      size_t l = invl, r = invl;
      for (; r < i; ++r)
        if (a[r] < p.size() || p[a[r]] == -1)
          p[a[r]] = r;
        else {
          for (; l < r; ++l)
            if (a[l] < p.size()) p[a[l]] = ~0;
          ++l;
        }
      p[0] = i;
      ++r;
      size_t d = 0;
      while (d < p.size() && ~p[d]) ++d;
      ans = max(ans, d);
      for (; r <= invr; ++r) {
        if (a[r] < p.size() && p[a[r]] == -1)
          p[a[r]] = r;
        else {
          if (a[r] >= p.size() || p[a[r]] >= i) goto over;
          size_t d = p[a[r]];
          for (; l <= d; ++l)
            if (a[l] < p.size()) p[a[l]] = ~0, d = min<size_t>(d, a[l] - 1);
          p[a[r]] = r;
        }
        while (d < p.size() && ~p[d]) ++d;
        ans = max(ans, d);
      }
    over:;
    }
  cout << ans;
  return 0;
}