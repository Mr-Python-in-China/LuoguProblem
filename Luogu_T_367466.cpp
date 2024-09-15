#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  vector<pair<ui, ui>> a(n);
  ui p = 0;
  for (pair<ui, ui>& i : a) {
    cin >> i.first >> i.second;
    p += 100 / i.first * i.second;
  }
  ui t;
  cin >> t;
  if (p >= t) cout << "Already Au.", exit(0);
  for (pair<ui, ui>& i : a) {
    if ((t - p + 100 / i.first - 1) / (100 / i.first) + i.second > i.first)
      cout << "NaN\n";
    else
      cout << (t - p + 100 / i.first - 1) / (100 / i.first) << '\n';
  }
  return 0;
}