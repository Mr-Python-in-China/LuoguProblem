#include <bits/extc++.h>
using namespace std;
using uli = unsigned long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  uli a, b, c, d, e, f, k;
  cin >> a >> b >> c >> d >> e >> f >> k;
  cout << max(k / b * a * c, k / e * d * f);
  return 0;
}