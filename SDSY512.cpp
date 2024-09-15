#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, k;
  cin >> n >> k;
  vector<char> s(n);
  for (char& i : s) cin >> i;
  vector<ui> nc(n + 1), oc(n + 1), ic(n + 1);
  for (size_t i = 0; i < n; ++i)
    nc[i + 1] = nc[i] + (s[i] == 'N'), oc[i + 1] = oc[i] + (s[i] == 'O'),
           ic[i + 1] = ic[i] + (s[i] == 'I');
  size_t ans = numeric_limits<size_t>::max();
  for (size_t first_o_pos = 0; first_o_pos < n; ++first_o_pos)
    if (s[first_o_pos] == 'O') {
      size_t last_o_pos = lower_bound(oc.cbegin() + first_o_pos, oc.cend(),
                                      oc[first_o_pos] + k) -
                          oc.cbegin();
      size_t last_i_pos =
          lower_bound(ic.cbegin() + last_o_pos, ic.cend(), ic[last_o_pos] + k) -
          ic.cbegin();
      size_t first_n_pos = upper_bound(nc.cbegin(), nc.cbegin() + first_o_pos,
                                       nc[first_o_pos] - k) -
                           nc.begin() - 1;
      if (ic[last_i_pos] - ic[last_o_pos] != k ||
          oc[last_o_pos] - oc[first_o_pos] != k ||
          nc[first_o_pos] - nc[first_n_pos] != k)
        continue;
      ans = min(ans, (last_o_pos - first_o_pos - k) +
                         (last_i_pos - last_o_pos - k) +
                         (first_o_pos - first_n_pos - k));
    }
  ans == numeric_limits<size_t>::max() ? cout << "-1" : cout << ans;
  return 0;
}