#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream& fin = cin;
ostream& fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
set<size_t> setIota(size_t n) {
  set<size_t> res;
  for (size_t i = 0; i < n; ++i) res.emplace(i);
  return res;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m, q;
  fin >> n >> m >> q;
  vector<set<size_t>> a(n, setIota(m)), b(m, setIota(n));
  while (q--) {
    size_t x, y;
    fin >> x >> y;
    --x, --y;
    set<size_t>::iterator at = a[x].lower_bound(y), bt = b[y].lower_bound(x);
    if (at != a[x].end() && *at == y) {
      assert(bt != b[y].end() && *bt == x);
      a[x].erase(at), b[y].erase(bt);
    } else {
      if (at != a[x].begin()) b[*prev(at)].erase(x), a[x].erase(prev(at));
      if (bt != b[y].begin()) a[*prev(bt)].erase(y), b[y].erase(prev(bt));
      if (at != a[x].end()) b[*at].erase(x), a[x].erase(at);
      if (bt != b[y].end()) a[*bt].erase(y), b[y].erase(bt);
    }
  }
  size_t s = 0;
  for (auto const& i : a) s += i.size();
  fout << s;
  return 0;
}