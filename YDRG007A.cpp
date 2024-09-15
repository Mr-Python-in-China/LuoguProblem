#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream &fin = cin;
ostream &fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
const auto pairHash = [](pair<ui, ui> const &pr) {
  return pr.second + ((uli)pr.first << 32);
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  fin >> T;
  while (T--) {
    size_t a;
    ui n, m;
    fin >> a >> n >> m;
    unordered_set<pair<ui, ui>, decltype(pairHash)> vis(0, pairHash);
    while (a--) {
      size_t x;
      fin >> x;
      --x;
      vis.emplace(x / n, x % n);
    }
    for (auto const &i : vis)
      if (!vis.count({i.first, n - 1 - i.second})) {
        fout << "No\n";
        goto failed;
      }
    fout << "Yes\n";
  failed:;
  }
  return 0;
}