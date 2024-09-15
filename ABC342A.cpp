#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  array<size_t, 26> arr = {};
  string s;
  cin >> s;
  for (char i : s) ++arr[i - 'a'];
  char ans;
  for (char i = 'a'; i <= 'z'; ++i)
    if (arr[i - 'a'] == 1) ans = i;
  for (size_t i = 0; i < s.size(); ++i)
    if (arr[s[i] - 'a'] == 1) cout << i + 1;
  return 0;
}