#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  vector<size_t> p(n);
  for (size_t i = 0; i < n; ++i) {
    size_t x;
    cin >> x;
    p[--x] = i;
  }
  size_t m;
  cin >> m;
  while (m--) {
    size_t a, b;
    cin >> a >> b;
    --a, --b;
    cout << (p[a] < p[b] ? a : b) + 1 << '\n';
  }
  return 0;
}