#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
template <typename T> T ceildiv(T a, T b) { return ceil((long double)a / b); }
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n;
    int k, x, y;
    cin >> n >> k >> x >> y;
    vector<pair<int, int>> a(n);
    pair<li, li> sum;
    for (pair<int, int>& i : a)
      cin >> i.first >> i.second, sum.first += i.first, sum.second += i.second;
  }
  return 0;
}