#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n;
    cin >> n;
    vector<unsigned char> cnt(n);
    for (size_t i = 0; i < n; ++i) {
      ui x;
      cin >> x;
      ++cnt[--x];
    }
    cout << count(cnt.begin(), cnt.end(), 2) << '\n';
  }
  return 0;
}