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
    vector<bool> b(n);
    for (vector<bool>::reference i : b) {
      char c;
      cin >> c;
      i = c == '1';
    }
    reverse(b.begin(), b.end());
    vector<size_t> zero_pos;
    for (size_t i = 0; i < n; ++i)
      if (!b[i]) zero_pos.push_back(i);
    uli ans = 0;
    for (size_t i = 0; i < zero_pos.size(); ++i) {
      cout << (ans += zero_pos[i] - i) << ' ';
    }
    for (size_t i = zero_pos.size(); i < n; ++i) cout << "-1 ";
    cout << '\n';
  }
  return 0;
}