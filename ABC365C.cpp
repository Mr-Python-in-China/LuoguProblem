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
  uli m;
  cin >> n >> m;
  vector<ui> a(n);
  for (ui &i : a) cin >> i;
  uli l = 0, r = numeric_limits<uli>::max() / 2;
  while (l < r) {
    uli mid = (l + r + 1) / 2;
    uli sum = 0;
    for (ui i : a) sum += min<uli>(mid, i);
    sum <= m ? l = mid : r = mid - 1;
  }
  if (l == numeric_limits<uli>::max() / 2)
    cout << "infinite";
  else
    cout << l;
  return 0;
}