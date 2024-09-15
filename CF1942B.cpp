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
    vector<int> a(n);
    for (int& i : a) cin >> i;
    set<ui> unvis;
    for (size_t i = 0; i < n + 2; ++i) unvis.insert(i);
    for (size_t i = 0; i < n; ++i) {
      ui x;
      if (*next(unvis.begin()) - *unvis.begin() == a[i])
        x = *unvis.begin();
      else
        x = *unvis.begin() - a[i];
      cout << x << ' ';
      unvis.erase(x);
    }
    cout << '\n';
  }
  return 0;
}