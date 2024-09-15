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
  vector<string> s(n);
  for (string& i : s) cin >> i;
  bool flag = false;
  for (size_t i = 1; i < n; ++i) {
    if (flag) {
      cout << "No";
      return 0;
    }
    if (s[i] == "sweet" && s[i - 1] == "sweet") flag = true;
  }
  cout << "Yes";
  return 0;
}