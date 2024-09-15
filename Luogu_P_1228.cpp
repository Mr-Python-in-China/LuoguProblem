#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
void fun(const size_t& stx, const size_t& sty, const size_t& k,
         const size_t& bkx, const size_t& bky) {
  if (!k) return;
  size_t mdsz = 1 << (k - 1), mdx = stx + mdsz, mdy = sty + mdsz;
  if (bkx < mdx && bky < mdy)
    cout << mdx + 1 << ' ' << mdy + 1 << ' ' << 1 << '\n',
        fun(stx, sty, k - 1, bkx, bky), fun(stx, mdy, k - 1, mdx - 1, mdy),
        fun(mdx, sty, k - 1, mdx, mdy - 1), fun(mdx, mdy, k - 1, mdx, mdy);
  if (bkx < mdx && bky >= mdy)
    cout << mdx + 1 << ' ' << mdy - 1 + 1 << ' ' << 2 << '\n',
        fun(stx, sty, k - 1, mdx - 1, mdy - 1), fun(stx, mdy, k - 1, bkx, bky),
        fun(mdx, sty, k - 1, mdx, mdy - 1), fun(mdx, mdy, k - 1, mdx, mdy);
  if (bkx >= mdx && bky < mdy)
    cout << mdx - 1 + 1 << ' ' << mdy + 1 << ' ' << 3 << '\n',
        fun(stx, sty, k - 1, mdx - 1, mdy - 1),
        fun(stx, mdy, k - 1, mdx - 1, mdy), fun(mdx, sty, k - 1, bkx, bky),
        fun(mdx, mdy, k - 1, mdx, mdy);
  if (bkx >= mdx && bky >= mdy)
    cout << mdx - 1 + 1 << ' ' << mdy - 1 + 1 << ' ' << 4 << '\n',
        fun(stx, sty, k - 1, mdx - 1, mdy - 1),
        fun(stx, mdy, k - 1, mdx - 1, mdy), fun(mdx, sty, k - 1, mdx, mdy - 1),
        fun(mdx, mdy, k - 1, bkx, bky);
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t k, x, y;
  cin >> k >> x >> y;
  vector<vector<bool>> arr(1 << k, vector<bool>(1 << k));
  fun(0, 0, k, --x, --y);
  return 0;
}