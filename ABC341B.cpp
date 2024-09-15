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
  vector<uli> a(n);
  for (uli& i : a) cin >> i;
  for (size_t i = 1; i < n; ++i) {
    ui s, t;
    cin >> s >> t;
    a[i] += a[i - 1] / s * t, a[i - 1] %= s;
  }
  cout << a.back();
  return 0;
}