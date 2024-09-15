#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  ui x;
  cin >> n >> x;
  deque<ui> a(n);
  for (ui &i : a) cin >> i;
  queue<size_t> q;
  ui t = 0;
  for (ui i : a) {
    if (t <= i)
      t = i + x;
    else
      t += x;
    cout << t << '\n';
  }
  return 0;
}