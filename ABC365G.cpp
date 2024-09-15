#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream& fin = cin;
ostream& fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
ui solve(vector<pair<ui, ui>>& a, vector<pair<ui, ui>>& b, ui l, ui r) {}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  cin >> n >> m;
  vector<vector<pair<ui, ui>>> s(n);
  while (m--) {
    ui t;
    size_t p;
    cin >> t >> p;
    if (s[p].empty() || s[p].back().second != ~0)
      s[p].emplace_back(t, ~0);
    else
      s[p].back().second = t;
  }
  size_t q;
  cin >> q;
  while (q--) {}
  return 0;
}