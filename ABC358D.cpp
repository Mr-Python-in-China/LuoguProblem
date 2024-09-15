#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  cin >> n >> m;
  vector<ui> a(n), b(m);
  for (ui &i : a) cin >> i;
  for (ui &j : b) cin >> j;
  sort(a.begin(), a.end()), sort(b.begin(), b.end(), greater<ui>());
  uli sum = 0;
  for (ui i : a) {
    if (i >= b.back()) b.pop_back(), sum += i;
    if (b.empty()) break;
  }
  b.empty() ? cout << sum : cout << "-1";
  return 0;
}