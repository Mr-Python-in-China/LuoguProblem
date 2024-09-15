#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream &fin = cin;
ostream &fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
string const D[] = {"BG", "BR", "BY", "GR", "GY", "RY"};
unordered_map<string, ui> const M = {
    {"BG", 0},
    {"BR", 1},
    {"BY", 2},
    {"GR", 3},
    {"GY", 4},
    {"RY", 5}
};
size_t const R[] = {5, 4, 3, 2, 1, 0};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  fin >> T;
  while (T--) {
    size_t n, q;
    fin >> n >> q;
    vector<size_t> a(n);
    array<vector<size_t>, 6> state;
    for (size_t i = 0; i < n; ++i) {
      string s;
      fin >> s;
      a[i] = M.at(s);
      for (size_t j = 0; j < 6; ++j)
        if (a[i] != j && R[a[i]] != j) state[j].emplace_back(i);
    }
    while (q--) {
      size_t x, y;
      fin >> x >> y;
      --x, --y;
      if (x > y) swap(x, y);
      if (R[a[x]] != a[y])
        fout << y - x << '\n';
      else {
        if (state[a[x]].empty()) {
          fout << "-1\n";
          continue;
        }
        size_t r = upper_bound(state[a[x]].begin(), state[a[x]].end(), x) -
                   state[a[x]].begin();
        size_t ans = numeric_limits<size_t>::max();
        if (r != state[a[x]].size())
          ans = min(ans, max(x, state[a[x]][r]) - min(x, state[a[x]][r]) +
                             max(y, state[a[x]][r]) - min(y, state[a[x]][r]));
        if (r != 0)
          ans = min(
              ans, max(x, state[a[x]][r - 1]) - min(x, state[a[x]][r - 1]) +
                       max(y, state[a[x]][r - 1]) - min(y, state[a[x]][r - 1]));
        fout << ans << '\n';
      }
    }
  }
  return 0;
}