#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, q;
  cin >> n >> q;
  vector<uli> ans(n);
  unordered_set<size_t> s;
  uli sum = 0;
  while (q--) {
    size_t x;
    cin >> x;
    --x;
    if (!s.count(x)) {
      ans[x] -= sum;
      s.insert(x);
    } else {
      ans[x] += sum;
      s.erase(x);
    }
    sum += s.size();
  }
  for (size_t i : s) ans[i] += sum;
  for (uli i : ans) cout << i << ' ';
  return 0;
}