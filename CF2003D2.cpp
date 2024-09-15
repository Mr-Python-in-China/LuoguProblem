#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream &fin = cin;
ostream &fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  fin >> T;
  while (T--) {
    size_t n;
    ui m;
    fin >> n >> m;
    map<ui, vector<ui>> graph;
    ui maxc2 = 0;
    for (size_t i = 0; i < n; ++i) {
      size_t c;
      fin >> c;
      vector<bool> vis(c + 5);
      for (size_t i = 0; i < c; ++i) {
        ui x;
        fin >> x;
        if (x < vis.size()) vis[x] = true;
      }
      ui c1 = 0;
      for (; vis[c1]; ++c1);
      ui c2 = c1 + 1;
      for (; vis[c2]; ++c2);
      maxc2 = max(c2, maxc2);
    }
    ui d = 0;
  }
  return 0;
}