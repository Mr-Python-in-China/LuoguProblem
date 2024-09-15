#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
bool check_trangle(ui a, ui b, ui c) {
  return a + b > c && a + c > b && b + c > a;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    array<ui, 4> a;
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    cout << ((a[0] + a[1] + a[2] > a[3] && a[0] + a[1] + a[3] > a[2] &&
              a[0] + a[2] + a[3] > a[1] && a[1] + a[2] + a[3] > a[0]) &&
                     (check_trangle(max(a[0], a[2]) - min(a[0], a[2]), a[3],
                                    a[1]) ||
                      (check_trangle(max(a[1], a[3]) - min(a[1], a[3]), a[0],
                                     a[2])))
                 ? "yes\n"
                 : "no\n");
  }
  return 0;
}