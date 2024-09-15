#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  ui n, x, y, z;
  cin >> n >> x >> y >> z;
  if (x > y) swap(x, y);
  cout << (x <= z && z <= y ? "Yes" : "No");
  return 0;
}