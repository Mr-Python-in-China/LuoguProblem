#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, l, r;
  cin >> n >> l >> r;
  vector<ui> ans(n);
  iota(ans.begin(), ans.end(), ui(1));
  reverse(ans.begin() + --l, ans.begin() + r);
  for (ui i : ans) cout << i << ' ';
  return 0;
}