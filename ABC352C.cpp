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
  vector<ui> a(n), b(n);
  for (size_t i = 0; i < n; ++i) cin >> a[i] >> b[i], b[i] -= a[i];
  cout << accumulate(a.begin(), a.end(), 0ull) +
              *max_element(b.begin(), b.end());
  return 0;
}