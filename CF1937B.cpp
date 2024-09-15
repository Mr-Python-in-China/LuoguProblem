#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
enum class NODE : unsigned char { BOTH, FORWARD, DOWN };
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n;
    cin >> n;
    vector<bool> s1(n), s2(n);
    for (vector<bool>::reference i : s1) {
      char c;
      cin >> c;
      i = c == '1';
    }
    for (vector<bool>::reference i : s2) {
      char c;
      cin >> c;
      i = c == '1';
    }
    vector<size_t> l1(n), l2(n);
    size_t ansp = -1, ansc = 0, c = 1;
    for (size_t i = 0; i < n - 1; ++i) {
      if (s1[i + 1] == s2[i])
        ++c;
      else if (s1[i + 1] < s2[i])
        ansp = i, ansc = 0, c = 1;
      else
        break;
    }
    ansc = max(ansc, c);
    for (size_t i = 0; i <= ansp + 1; ++i) cout << s1[i];
    for (size_t i = ansp + 1; i < n; ++i) cout << s2[i];
    cout << '\n' << ansc << '\n';
  }
  return 0;
}