#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
stringstream sout;
size_t ans = 0;
void fun(const size_t& stx, const size_t& sty, const size_t& k,
         const size_t& bkx, const size_t& bky) {
  if (!k) return;
  size_t mdsz = 1 << (k - 1), mdx = stx + mdsz, mdy = sty + mdsz;
  if (bkx < mdx && bky < mdy)
    sout << mdx + 1 << ' ' << mdy + 1 << ' ' << "-1 -1" << '\n', ans++,
        fun(stx, sty, k - 1, bkx, bky), fun(stx, mdy, k - 1, mdx - 1, mdy),
        fun(mdx, sty, k - 1, mdx, mdy - 1), fun(mdx, mdy, k - 1, mdx, mdy);
  if (bkx < mdx && bky >= mdy)
    sout << mdx + 1 << ' ' << mdy - 1 + 1 << ' ' << "-1 1" << '\n', ans++,
        fun(stx, sty, k - 1, mdx - 1, mdy - 1), fun(stx, mdy, k - 1, bkx, bky),
        fun(mdx, sty, k - 1, mdx, mdy - 1), fun(mdx, mdy, k - 1, mdx, mdy);
  if (bkx >= mdx && bky < mdy)
    sout << mdx - 1 + 1 << ' ' << mdy + 1 << ' ' << "1 -1" << '\n', ans++,
        fun(stx, sty, k - 1, mdx - 1, mdy - 1),
        fun(stx, mdy, k - 1, mdx - 1, mdy), fun(mdx, sty, k - 1, bkx, bky),
        fun(mdx, mdy, k - 1, mdx, mdy);
  if (bkx >= mdx && bky >= mdy)
    sout << mdx - 1 + 1 << ' ' << mdy - 1 + 1 << ' ' << "1 1" << '\n', ans++,
        fun(stx, sty, k - 1, mdx - 1, mdy - 1),
        fun(stx, mdy, k - 1, mdx - 1, mdy), fun(mdx, sty, k - 1, mdx, mdy - 1),
        fun(mdx, mdy, k - 1, bkx, bky);
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), sout.tie(nullptr);
  size_t n, x, y;
  cin >> n >> x >> y;
  --x, --y;
  size_t k = log2(n), tk = 1 << k;
  if (x < tk && y < tk) {
    fun(0, 0, k, x, y);
    for (size_t i = tk; i < n; i++)
      sout << i + 1 << ' ' << i + 1 << " -" << i << " -" << i << '\n', ans++;
  } else if (x >= tk && y < tk) {
    fun(n - tk, 0, k, x, y);
    for (size_t i = tk; i < n; i++)
      sout << n - i << ' ' << i + 1 << ' ' << i << " -" << i << '\n', ans++;
  } else if (x < tk && y >= tk) {
    fun(0, n - tk, k, x, y);
    for (size_t i = tk; i < n; i++)
      sout << i + 1 << ' ' << n - i << " -" << i << ' ' << i << '\n', ans++;
  } else if (x >= tk && y >= tk) {
    fun(n - tk, n - tk, k, x, y);
    for (size_t i = tk; i < n; i++)
      sout << n - i << ' ' << n - i << ' ' << i << ' ' << i << '\n', ans++;
  }
  cout << "Yes\n" << ans << '\n' << sout.str();
  return 0;
}