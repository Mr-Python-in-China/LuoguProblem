#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
template <typename T> T abs_minus(T a, T b) { return max(a, b) - min(a, b); }
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    array<ui, 3> b;
    cin >> b[0] >> b[1] >> b[2];
    sort(b.begin(), b.end());
    cout << b[2] - b[1] + b[1] - b[0] << '\n';
  }
  return 0;
}