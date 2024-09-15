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
    map<ui, size_t> cnt;
    for (size_t i = 0; i < n; ++i) {
      ui x;
      cin >> x;
      ++cnt[x];
    }
    cout << (find_if(cnt.rbegin(), cnt.rend(),
                     [](auto const &x) { return x.second & 1; }) != cnt.rend()
                 ? "YES\n"
                 : "NO\n");
  }
  return 0;
}