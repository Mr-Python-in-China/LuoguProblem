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
  unordered_map<ui, ui> m;
  for (size_t i = 0; i < n; ++i) {
    ui x, c;
    cin >> x >> c;
    unordered_map<ui, ui>::iterator it = m.find(c);
    if (it == m.end())
      m.emplace(c, x);
    else
      it->second = min(it->second, x);
  }
  cout << max_element(m.begin(), m.end(), [](pair<ui, ui> a, pair<ui, ui> b) {
            return a.second < b.second;
          })->second;
  return 0;
}