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
  vector<bool> d(n);
  for (vector<bool>::reference i : d) {
    char c;
    cin >> c;
    i = c == '1';
  }
  reverse(d.begin(), d.end());
  bool flag = false;
  vector<bool> ans;
  for (size_t i = 0; i < n; ++i)
    if (flag != d[i]) {
      for (size_t j = i; j < n; ++j) ans.push_back(flag);
      flag = !flag;
    }
  cout << ans.size() << '\n';
  for (bool i : ans) cout.put('A' + i);
  return 0;
}