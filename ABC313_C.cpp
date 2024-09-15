#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using uli = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  vector<uli> a(n);
  uli sum = 0;
  for (uli& i : a) cin >> i, sum += i;
  sort(a.begin(), a.end());
  size_t small_count = n - sum % n;
  uli small = sum / n;
  uli ans = 0;
  for (size_t i = 0; i < n; i++) ans += abs(small + (i >= small_count) - a[i]);
  cout << (ans >> 1);
  return 0;
}