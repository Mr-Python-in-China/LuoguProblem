#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n;
    cin >> n;
    array<ui, 26> cnt = {};
    for (size_t i = 0; i < n; ++i) {
      ui c;
      cin >> c;
      array<ui, 26>::iterator it = find(cnt.begin(), cnt.end(), c);
      assert(cnt.end() != it);
      cout << char(it - cnt.begin() + 'a');
      ++*it;
    }
    cout.put('\n');
  }
  return 0;
}