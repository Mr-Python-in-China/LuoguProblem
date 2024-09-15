#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  ui a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << (a + b + c + d < 51 ? "Rabbit wins" : "Rabbit lose");
  return 0;
}