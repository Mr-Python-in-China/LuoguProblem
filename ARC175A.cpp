#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using sc = signed char;
constexpr ui P = 998244353;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  vector<size_t> p(n);
  for (size_t& i : p) cin >> i, --i;
  vector<sc> t(n);
  for (sc& i : t) {
    char c;
    cin >> c;
    i = c == 'L' ? -1 : c == 'R' ? 1 : 0;
  }
  ui ansl = 1, ansr = 1;
  auto prev_circle = [n](ui x) {
    x = x + n - 1;
    if (x >= n) x -= n;
    return x;
  };
  auto next_circle = [n](ui x) {
    x = x + 1;
    if (x >= n) x -= n;
    return x;
  };
  {
    vector<bool> vis(n);
    for (size_t i : p) {
      if (vis[next_circle(i)])
        if (t[i] == 0) {
          ansl *= 2;
          if (ansl >= P) ansl -= P;
        } else
          ;
      else if (t[i] == 1)
        ansl = 0;
      vis[i] = true;
    }
  }
  {
    vector<bool> vis(n);
    for (size_t i : p) {
      if (vis[prev_circle(i)])
        if (t[i] == 0) {
          ansr *= 2;
          if (ansr >= P) ansr -= P;
        } else
          ;
      else if (t[i] == -1)
        ansr = 0;
      vis[i] = true;
    }
  }
  cout << (ansl + ansr) % P;
  return 0;
}