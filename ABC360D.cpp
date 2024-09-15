#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  ui t;
  cin >> n >> t;
  vector<pair<li, bool>> a(n);
  for (pair<li, bool> &i : a) {
    char c;
    cin >> c;
    i.second = c == '1';
  }
  for (pair<li, bool> &i : a) cin >> i.first;
  vector<li> dl, dr;
  for (pair<li, bool> i : a) (i.second ? dr : dl).emplace_back(i.first);
  sort(dl.begin(), dl.end());
  uli ans = 0;
  for (li i : dr) {
    vector<li>::iterator l = lower_bound(dl.begin(), dl.end(), i),
                         r = upper_bound(dl.begin(), dl.end(), i + li(t * 2));
    ans += r - l;
  }
  cout << ans;
  return 0;
}