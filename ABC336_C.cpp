#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  uli x;
  cin >> x;
  --x;
  if (!x) cout << '0', exit(0);
  vector<char> ans;
  while (x) ans.push_back(x % 5), x /= 5;
  for_each(ans.crbegin(), ans.crend(), [](char c) { cout.put(c * 2 + '0'); });
  return 0;
}