#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using uli = unsigned long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m, c;
  uli k;
  cin >> n >> m >> c >> k;
  vector<uli> a(n);
  for (uli& i : a) cin >> i;
  uli seeds = 0;
  while (m--) {
    size_t p, q;
    cin >> p >> q;
    seeds |= (1ull << p);
  }
  uli used = seeds;
#ifdef debug
  cerr << used << endl;
#endif
  for (uli const& i : a)
    for (size_t j = 0; j < k; j++)
      if (((seeds >> j) & 1ull) && ((i >> j) & 1ull)) used &= ~(1ull << j);
#ifdef debug
  cerr << used << endl;
#endif
  if ((k - __builtin_popcountll(used)) == 64 && n == 0)
    cout << "18446744073709551616";
  else
    cout << (1ull << (k - __builtin_popcountll(used))) - n;
  return 0;
}