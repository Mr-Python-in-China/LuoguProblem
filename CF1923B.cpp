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
    ui k;
    cin >> n >> k;
    vector<pair<ui, ui>> a(n);
    for (pair<ui, ui>& i : a) cin >> i.second;
    for (pair<ui, ui>& i : a) {
      int x;
      cin >> x;
      i.first = abs(x);
    }
    sort(a.begin(), a.end(), greater<pair<ui, ui>>());
    size_t p = 0;
    while (!a.empty()) {
      if (a.back().first == p++) {
        cout << "NO\n";
        goto failed;
      }
      ui x = k;
      while (!a.empty() && x) {
        size_t q = min(a.back().second, x);
        x -= q, a.back().second -= q;
        if (!a.back().second) a.pop_back();
      }
    }
    cout << "YES\n";
  failed:;
  }
  return 0;
}