#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream& fin = cin;
ostream& fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
template <typename T, size_t N>
T sumMax(array<T, N> const& a, array<T, N> const& b) {
  T ans = a[0] + b[0];
  for (size_t i = 1; i < N; ++i) ans = max(ans, a[i] + b[i]);
  return ans;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  fin >> T;
  while (T--) {
    size_t n;
    fin >> n;
    vector<char> s(n);
    for (char& i : s) fin >> i;
    if (n % 2 == 1) {
      array<array<size_t, 26>, 2> prefix = {}, surfix = {};
      for (size_t i = 0; i < n; ++i) ++surfix[!(i & 1)][s[i] - 'a'];
      size_t ans = numeric_limits<size_t>::max();
      for (size_t i = 0; i < n; ++i) {
        --surfix[!(i & 1)][s[i] - 'a'];
        ans = min(ans, n - sumMax(prefix[0], surfix[0]) -
                           sumMax(prefix[1], surfix[1]));
        ++prefix[i & 1][s[i] - 'a'];
      }
      fout << ans << '\n';
    } else {
      array<array<size_t, 26>, 2> prefix = {};
      for (size_t i = 0; i < n; ++i) ++prefix[i & 1][s[i] - 'a'];
      fout << n - *max_element(prefix[0].begin(), prefix[0].end()) -
                  *max_element(prefix[1].begin(), prefix[1].end())
           << '\n';
    }
  }
  return 0;
}