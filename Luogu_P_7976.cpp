#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream& fin = cin;
ostream& fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
constexpr ui P = 1732073999;
auto const F = [] {
  vector<pair<uli, ui>> f;
  f.emplace_back(1, 1);
  while (f.back().first <= 1e17)
    f.emplace_back(f.back().first * 3, f.back().second * 4ull % P);
  return f;
}();
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  uli M;
  fin >> T >> M;
  while (T--) {
    uli x;
    fin >> x;
    ++x;
    ui level = 0;
    ui ans = 0;
    for_each(F.rbegin(), F.rend(), [&](pair<uli, ui> const& i) {
      if (x / i.first == 0)
        ;
      else if (x / i.first == 1)
        ans = (ans + i.second * (1ull << level++)) % P;
      else if (x / i.first == 2)
        ans = (ans + i.second * 3ull * (1ull << level)) % P;
      else
        throw;
      x %= i.first;
    });
    fout << ans << '\n';
  }
  return 0;
}