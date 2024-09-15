#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream &fin = cin;
ostream &fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  ui m;
  fin >> n >> m;
  vector<ui> a(n);
  for (ui &i : a) fin >> i;
  uli t = 0;
  uli sum = accumulate(a.begin(), a.end(), uli(0));
  uli ans = 0;
  vector<uli> pb(m);
  for_each(a.begin(), a.end(), [&](ui i) {
    ans += pb[t % m];
    ans += pb[(m - (sum - t) % m) % m];
    ++pb[t % m];
    t += i;
  });
  fout << ans;
  return 0;
}