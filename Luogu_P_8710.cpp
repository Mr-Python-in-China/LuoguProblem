#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
struct dsds {
  vector<size_t> fa;
  dsds(size_t n) {
    fa.resize(n);
    for (size_t i = 0; i < n; i++) fa[i] = i;
  }
  inline size_t find(size_t a) { return fa[a] == a ? a : fa[a] = find(fa[a]); }
  inline size_t link(size_t a, size_t b) { fa[find(a)] = find(b); }
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  cin >> n >> m;

  return 0;
}