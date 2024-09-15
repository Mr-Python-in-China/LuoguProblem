#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
bool check_rev(uli x) {
  string s = to_string(x);
  return equal(s.cbegin(), s.cend(), s.crbegin());
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  uli x;
  cin >> x;
  uli ans = cbrt((long double)x);
  while (!check_rev(ans * ans * ans)) --ans;
  cout << ans * ans * ans;
  return 0;
}