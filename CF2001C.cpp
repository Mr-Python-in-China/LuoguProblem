#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream &fin = cin;
ostream &fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
size_t ask(size_t x, size_t y) {
  fout << "? " << x + 1 << ' ' << y + 1 << endl;
  size_t res;
  fin >> res;
  return --res;
}
void f(size_t l, size_t r, vector<bool> &vis, vector<vector<size_t>> &mp) {
  if (vis[r]) return;
  size_t as = ask(l, r);
  if (as == l)
    mp[l].emplace_back(r);
  else
    f(l, as, vis, mp), f(as, r, vis, mp);
  vis[r] = true;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  fin >> T;
  while (T--) {
    size_t n;
    fin >> n;
    vector<bool> vis(n, false);
    vector<vector<size_t>> mp(n);
    vis[0] = true;
    for (size_t i = 0; i < n; ++i) f(0, i, vis, mp);
    fout << "! ";
    for (size_t i = 0; i < n; ++i)
      for (size_t j : mp[i]) fout << i + 1 << ' ' << j + 1 << ' ';
    fout << endl;
  }
  return 0;
}