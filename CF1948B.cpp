#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using uc = unsigned char;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n;
    cin >> n;
    vector<uc> ans;
    for (size_t i = 0; i < n; ++i) {
      unsigned short int x;
      cin >> x;
      if (x / 10 > x % 10 || (!ans.empty() && ans.back() > x / 10))
        ans.push_back(x);
      else
        ans.push_back(x / 10), ans.push_back(x % 10);
    }
    bool f = true;
    for (vector<uc>::const_iterator it = ans.cbegin(), jt = next(it);
         jt < ans.cend(); ++it, ++jt)
      if (*it > *jt) {
        f = false;
        break;
      }
    cout << (f ? "YES\n" : "NO\n");
  }
  return 0;
}