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
  set<size_t> online;
  pbds::priority_queue<size_t> inv;
  inv.push(0);
  for (size_t i = 0; i < n; ++i) online.insert(i);
  cout << "1 ";
  for (size_t i = 1; i < n; ++i) {
    size_t x;
    cin >> x;
    --x;
    online.erase(x);
    inv.push(x + 1);
    size_t top = *online.crbegin();
    while (inv.top() > top) inv.pop();
    cout << inv.size() << ' ';
  }
  cout << '1';
  return 0;
}