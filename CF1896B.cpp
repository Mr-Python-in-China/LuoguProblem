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
    vector<char> a(n);
    for (char& i : a) cin >> i;
    vector<bool> vis(n);
    for (size_t i = n - 1; i > 0; --i)
      for (size_t j = i; j < n && a[j - 1] == 'A' && a[j] == 'B' && !vis[j - 1];
           ++j)
        vis[j - 1] = true, a[j - 1] = 'B', a[j] = 'A';
    cout << accumulate(vis.begin(), vis.end(), size_t(0)) << '\n';
  }
  return 0;
}