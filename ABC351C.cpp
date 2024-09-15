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
  for (size_t i = 0; i < n; ++i) {
    ui k;
    cin >> k;
    a.push_back(k);
    while (a.size() > 1 && a.rbegin()[0] == a.rbegin()[1]) {
      ui x = a.back();
      a.pop_back(), a.pop_back();
      a.push_back(x + 1);
    }
  }
  cout << a.size();
  return 0;
}