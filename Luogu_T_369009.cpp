#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n;
    cin >> n;
    vector<li> a(n);
    for (li& i : a) cin >> i;
    unordered_map<li, pbds::priority_queue<li>> s;
    for (size_t i = 0; i < n; i++) s[i - a[i]].push(a[i]);
    li ans = 0;
    for (unordered_map<li, pbds::priority_queue<li>>::iterator it = s.begin();
         it != s.end(); it++) {
      pbds::priority_queue<li>& q = it->second;
      while (q.size() > 1) {
        li t1 = q.top();
        q.pop();
        li t2 = q.top();
        q.pop();
        if (t1 + t2 > 0) ans += t1 + t2;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}