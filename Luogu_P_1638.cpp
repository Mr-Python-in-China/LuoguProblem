#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  cin >> n >> m;
  vector<size_t> a(n);
  for (size_t& i : a) cin >> i, --i;
  vector<size_t> cnt(m);
  size_t c = 0;
  vector<size_t>::iterator it = a.begin(), jt = it;
  size_t mina = 0, minb = -2;
  while (true) {
    while (c < m)
      if (jt == a.end())
        cout << mina << ' ' << minb, exit(0);
      else if (!cnt[*jt++]++)
        ++c;
    if (jt - it < minb - mina + 1)
      mina = it - a.begin() + 1, minb = jt - a.begin();
    if (!--cnt[*it++]) --c;
  }
  exit(114514);
}