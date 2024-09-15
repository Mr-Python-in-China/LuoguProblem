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
    vector<ui> a(n);
    for (ui& i : a) cin >> i;
    sort(a.begin(), a.end());
    bool flag = false;
    if (a[0] != a[1])
      flag = true;
    else
      for (ui i : a)
        if (i % a.front()) {
          flag = true;
          break;
        }
    cout << (flag ? "YES\n" : "NO\n");
  }
  return 0;
}