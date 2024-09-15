#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m, ans = 0;
  cin >> n >> m;
  deque<ui> people(n);
  for (deque<ui>::reference i : people) cin >> i;
  vector<ui> tap(m);
  while (true) {
    size_t cnt = 0;
    for (vector<ui>::reference i : tap)
      if (i)
        i--;
      else if (!people.empty())
        i = --people.front(), people.pop_front();
      else
        cnt++;
    if (cnt == m) break;
    ans++;
  }
  cout << ans;
  return 0;
}