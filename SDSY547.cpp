#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
uli number_join(uli x, ui c) {
  string t = to_string(x);
  string s;
  while (c--) s += t;
  return stoull(s);
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    ui x;
    cin >> x;
    array<pair<long double, char>, 4> s{
        {{log((long double)number_join(x, 3)), 'A'},
         {log((long double)number_join(x, 2)) * x, 'B'},
         {log((long double)x) * number_join(x, 2), 'C'},
         {log((long double)x) * pow<long double>(x, x), 'D'}}
    };
    cout << max_element(s.begin(), s.end())->second << '\n';
  }
  return 0;
}