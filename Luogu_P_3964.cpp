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
  vector<pair<int, int>> d(n);
  for (auto& i : d) {
    int x, y;
    cin >> x >> y;
    i = {x + y, x - y};
  }

  return 0;
}