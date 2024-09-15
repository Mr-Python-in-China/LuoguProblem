#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream& fin = cin;
ostream& fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
constexpr ui P = 998244353;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  li k;
  fin >> n >> k;
  unordered_map<li, ui> p;
  p[0] = 1;
  li s = 0;
  ui f = 0, g = 1;
  for (size_t i = 0; i < n; ++i) {
    li x;
    fin >> x;
    s += x;
    (p[s] += f = (g - p[s - k] + P) % P) %= P;
    g = (f + g) % P;
  }
  fout << f;
  return 0;
}