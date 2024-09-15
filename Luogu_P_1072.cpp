#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    uli a0, a1, b0, b1;
    cin >> a0 >> a1 >> b0 >> b1;
    vector<uli> yz_of_b0;
    {
      uli i = 1;
      for (; i * i < b0; ++i)
        if (b0 % i == 0) yz_of_b0.push_back(i), yz_of_b0.push_back(b0 / i);
      if (i * i == b0) yz_of_b0.push_back(i);
    }
    uli div = b1 / b0;
    size_t ans = 0;
    for (uli& i : yz_of_b0) {
      uli x = i * div;
      if (x / __gcd(x, b0) == div && __gcd(x, a0) == a1) ++ans;
    }
    cout << ans << '\n';
  }
  return 0;
}