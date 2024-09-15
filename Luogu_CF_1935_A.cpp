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
    string s;
    size_t n;
    cin >> n >> s;
    if (string(s.crbegin(), s.crend()) < s) {
      string t = s;
      s.insert(s.begin(), t.rbegin(), t.rend());
    }
    cout << s << '\n';
  }
  return 0;
}