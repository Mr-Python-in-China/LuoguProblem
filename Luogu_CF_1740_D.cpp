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
    size_t k;
    uli n, m;
    cin >> n >> m >> k;
    deque<ui> a(k);
    for (ui& i : a) cin >> i;
    size_t maxs = 0;
    pbds::priority_queue<ui> q;
    ui stk_need = k;
    while (!a.empty()) {
      q.push(a.front());
      a.pop_front();
      maxs = max(maxs, q.size());
      while (!q.empty() && stk_need == q.top()) q.pop(), --stk_need;
    }
    cout << (maxs <= n * m - 3 ? "YA" : "TIDAK") << '\n';
  }
  return 0;
}