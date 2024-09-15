#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream &fin = cin;
ostream &fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
template <typename RandomIterator>
void f(RandomIterator beg, RandomIterator end, ui k) {
  if (k == 0) return;
  if (beg == end) return;
  RandomIterator mid = (end - beg) / 2 + beg;
  for (RandomIterator it = beg; it != mid; ++it) (*it <<= 1) |= 0;
  for (RandomIterator it = mid; it != end; ++it) (*it <<= 1) |= 1;
  f(beg, mid, k - 1), f(mid, end, k - 1);
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  fin >> T;
  while (T--) {
    ui n, k;
    fin >> n >> k;
    vector<ui> ans(n, 1);
    f(ans.begin(), ans.end(), k - 1);
    for (ui i : ans) cout << i << ' ';
    cout << '\n';
  }
  return 0;
}