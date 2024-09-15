#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream &fin = cin;
ostream &fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
typedef vector<vector<size_t>> Graph;
void makeTree(size_t p, vector<size_t> &fa, vector<size_t> &deepth,
              Graph const &mp) {
  for (size_t i : mp[p])
    if (!~fa[i])
      fa[i] = p, deepth[i] = deepth[p] + 1, makeTree(i, fa, deepth, mp);
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, k;
  fin >> n >> k;
  Graph mp(n);
  for (size_t i = 1; i < n; ++i) {
    size_t x, y;
    fin >> x >> y;
    --x, --y;
    mp[x].emplace_back(y), mp[y].emplace_back(x);
  }
  vector<size_t> fa(n, -1), deepth(n);
  makeTree(0, fa, deepth, mp);
  vector<bool> used(n);
  size_t top;
  fin >> top;
  --k;
  used[--top] = true;
  while (k--) {
    size_t x;
    fin >> x;
    used[--x] = true;
    if (deepth[x] < deepth[top]) swap(x, top);
    while (deepth[x] > deepth[top]) {
      if (used[fa[x]]) goto next;
      used[x = fa[x]] = true;
    }
    while (x != top) used[x = fa[x]] = true, used[top = fa[top]] = true;
  next:;
  }
  fout << accumulate(used.begin(), used.end(), size_t(0));
  return 0;
}