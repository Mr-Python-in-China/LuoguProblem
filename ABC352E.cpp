#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
struct D {
  ui c;
  vector<size_t> nxt;
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  cin >> n >> m;
  vector<D> d(m);
  for (D& i : d) {
    size_t k;
    cin >> k >> i.c;
    i.nxt.resize(k);
    for (size_t j : i.nxt) cin >> j, --k;
  }

  return 0;
}