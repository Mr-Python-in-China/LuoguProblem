#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using usi = unsigned short int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n;
    usi m;
    cin >> n >> m;
    deque<usi> q(n);
    for (usi& i : q) cin >> i;
    vector<usi> stk;
    for (size_t i = 0; i < n; ++i) {
      char c;
      cin >> c;
      stk.push_back(c == 'L' ? q.front() : q.back()),
          c == 'L' ? q.pop_front() : q.pop_back();
    }
    ui t = 1;
    vector<usi> ans;
    for_each(stk.crbegin(), stk.crend(),
             [&ans, &t, m](usi x) { ans.push_back((t *= x) %= m); });
    for_each(ans.crbegin(), ans.crend(), [](usi x) { cout << x << ' '; });
    cout.put('\n');
  }
  return 0;
}