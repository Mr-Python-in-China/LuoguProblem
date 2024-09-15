#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  string s, t;
  cin >> s >> t;
  size_t p = 0;
  for (char i : s) {
    while (t[p] != i) ++p;
    cout << ++p << ' ';
  }
  return 0;
}