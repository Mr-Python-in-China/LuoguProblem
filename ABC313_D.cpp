#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
class dsds {
  struct node {
    size_t fa;
    bool nav;
  };
  vector<node> v;
  node find(size_t x) {
    if (v[x].fa == x)
      return v[x];
    else {
      node res = find(v[x].fa);
      if (v[x].nav) res.nav ^= 1;
      return res;
    }
  }

 public:
  void merge(size_t x, size_t y) {}
};
int main(void) {
  ios::sync_with_stdio(false);
  size_t n, k;
  cin >> n >> k;
  vector<bool> ans(n);
  if (k == 1) {
    for (size_t i = 0; i < n; i++) {
      cout << "? " << i + 1 << endl;
      bool x;
      cin >> x;
      ans[i] = x;
    }
    for (vector<bool>::reference i : ans) cout << i << ' ';
  } else {
    ans[0] = 1;
    cout << "? ";
    for (size_t i = 0; i < k; i++) cout << i << ' ';
    cout << endl;
    bool ans1;
    cin >> ans1;
  }
  return 0;
}