#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    vector<size_t> cntA(1);
    size_t ans = 0;
    for (char const& i : s)
      if (i == 'B')
        cntA.push_back(0);
      else
        ++cntA.back(), ++ans;
    size_t minx = -1;
    for (size_t const& i : cntA) minx = min(minx, i);
    cout << (cntA.size() == 1 ? 0 : ans -= minx) << '\n';
  }
  return 0;
}