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
  list<ui> a(n);
  map<ui, list<ui>::iterator> mp;
  for (list<ui>::iterator it = a.begin(); it != a.end(); ++it)
    cin >> *it, mp[*it] = it;
  size_t q;
  cin >> q;
  while (q--) {
    char op;
    ui x;
    cin >> op >> x;
    if (op == '1') {
      ui y;
      cin >> y;
      mp[y] = a.insert(next(mp[x]), y);
    } else if (op == '2') {
      a.erase(mp[x]), mp.erase(x);
    }
  }
  for (ui i : a) cout << i << ' ';
  return 0;
}