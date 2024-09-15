#include <bits/extc++.h>
using namespace std;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
namespace pbds = __gnu_pbds;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  ui s;
  ui u, v;
  size_t t;
  cin >> n >> m >> s >> u >> v >> t;
  deque<int> q0(n);
  for (int& i : q0) cin >> i;
  sort(q0.begin(), q0.end(), greater<int>());
  ui addtag = 0;
  deque<int> q1, q2;
  for (size_t i = 0, k = 1; i < m; ++i, ++k) {
    li target = max({
        q0.empty() ? numeric_limits<int>::min() : q0.front(),
        q1.empty() ? numeric_limits<int>::min() : q1.front(),
        q2.empty() ? numeric_limits<int>::min() : q2.front(),
    });
    !q0.empty() && target == q0.front()   ? q0.pop_front()
    : !q1.empty() && target == q1.front() ? q1.pop_front()
    : !q2.empty() && target == q2.front() ? q2.pop_front()
                                          : throw;
    target += addtag;
    addtag += s;
    q1.push_back(target * u / v - addtag);
    q2.push_back(target - (q1.back() + addtag) - addtag);
    if (k == t) cout << target << ' ', k = 0;
  }
  cout << '\n';
  vector<int> ans(q0.size() + q1.size() + q2.size());
  {
    int* buffer = new int[q1.size() + q2.size()];
    merge(q1.cbegin(), q1.cend(), q2.cbegin(), q2.cend(), buffer,
          greater<int>());
    merge(q0.cbegin(), q0.cend(), buffer, buffer + q1.size() + q2.size(),
          ans.begin(), greater<int>());
  }
  for (size_t i = t - 1; i < ans.size(); i += t) cout << ans[i] + addtag << ' ';
  return 0;
}