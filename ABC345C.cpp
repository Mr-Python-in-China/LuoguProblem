#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  string s;
  cin >> s;
  array<ui, 128> cnt = {};
  uli ans = 0;
  for (size_t i = 0; i < s.size(); ++i) { ans += i - cnt[s[i]]++; }
  cout << ans + (find_if(cnt.begin(), cnt.end(), [](ui x) { return x > 1; }) !=
                 cnt.end());
  return 0;
}