#include <bits/extc++.h>
using namespace std;
using ui = unsigned int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  ui x, h;
  cin >> x >> h;
  cout << (x < 10   ? "Drizzle"
           : x < 25 ? "Moderate Rain"
           : x < 50 ? "Heavy Rain"
                    : "Torrential Rain");
  if (h == 1) cout << '\n' << (x >= 20 ? "YES" : "NO");
  return 0;
}