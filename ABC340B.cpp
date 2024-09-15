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
  vector<ui> a;
  while (n--) {
    char op;
    cin >> op;
    if (op == '1') {
      ui x;
      cin >> x;
      a.push_back(x);
    } else if (op == '2') {
      size_t p;
      cin >> p;
      cout << a.rbegin()[--p] << '\n';
    }
  }
  return 0;
}