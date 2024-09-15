#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, k;
  cin >> n >> k;
  vector<ui> a(n);
  for (ui& i : a) cin >> i;
  sort(a.begin(), a.end());
  cout << a[k];
  return 0;
}